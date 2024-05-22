#include "main.hpp"

rcl_subscription_t subscriber;
bur_rov_msgs__msg__ThrusterCommand msg;
rclc_executor_t executor;
rcl_timer_t timer;
rclc_support_t support;
rcl_allocator_t allocator;
rcl_node_t node;
bool micro_ros_init_successful;
static micro_ros_utilities_memory_conf_t conf = {0};

const uint8_t util_pin_begin = 24;
Servo motor[MOTOR_COUNT];

// subscription callback
void sub_callback(const void *msgin)
{
  micro_ros_utilities_create_message_memory(ROSIDL_GET_MSG_TYPE_SUPPORT(bur_rov_msgs, msg, ThrusterCommand), &msgin, conf);

  const bur_rov_msgs__msg__ThrusterCommand *msg = (const bur_rov_msgs__msg__ThrusterCommand *)msgin;

  for (int i = 0; i < MOTOR_COUNT; i++)
  {
    motor[i].writeMicroseconds((int)(msg->thrusters[i + 1] * 400 + 1500));
  }

  for (int i = 0; i < UTIL_COUNT; i++)
  {
    digitalWrite(i * 2 + util_pin_begin, (msg->buttons.data[i * 3 - 2]));
  }
  // }
}

void turn_off_outputs()
{
  for (uint8_t i = 0; i < MOTOR_COUNT; i++)
  {
    motor[i].writeMicroseconds(1500);
  }
  for (uint8_t i = 0; i < UTIL_COUNT; i++)
  {
    digitalWrite(i * 2 + util_pin_begin, LOW);
  }
}

// Functions create_entities and destroy_entities can take several seconds.
// In order to reduce this rebuild the library with
// - RMW_UXRCE_ENTITY_CREATION_DESTROY_TIMEOUT=0
// - UCLIENT_MAX_SESSION_CONNECTION_ATTEMPTS=3

bool create_entities()
{
  allocator = rcl_get_default_allocator();

  // create init_options
  RCCHECK(rclc_support_init(&support, 0, NULL, &allocator));

  // create node
  RCCHECK(rclc_node_init_default(&node, "arduino_node_thruster", "", &support));
  // create subscriber
  RCCHECK(rclc_subscription_init_best_effort(&subscriber, &node,
                                             ROSIDL_GET_MSG_TYPE_SUPPORT(bur_rov_msgs, msg, ThrusterCommand),
                                             "thruster_command"));

  // create executor
  RCCHECK(rclc_executor_init(&executor, &support.context, 1, &allocator));
  RCCHECK(rclc_executor_add_subscription(&executor, &subscriber, &msg, &sub_callback, ON_NEW_DATA));

  return true;
}

void destroy_entities()
{
  rmw_context_t *rmw_context = rcl_context_get_rmw_context(&support.context);
  (void)rmw_uros_set_context_entity_destroy_session_timeout(rmw_context, 0);
  turn_off_outputs();
  rcl_subscription_fini(&subscriber, &node);
  rcl_timer_fini(&timer);
  rclc_executor_fini(&executor);
  rcl_node_fini(&node);
  rclc_support_fini(&support);
}

void setup()
{
  // Initialize motors and outputs
  int motor_pin_begin = 4;
  for (int i = 0; i < MOTOR_COUNT; i++)
  {
    motor[i].attach(i + motor_pin_begin);
  }
  for (int i = 0; i < UTIL_COUNT; i++)
  {
    pinMode(i * 2 + util_pin_begin, OUTPUT);
  }
  turn_off_outputs();
  // Initialize micro-ROS
  SerialUSB.begin(115200);
  set_microros_serial_transports(SerialUSB);

  conf.max_ros2_type_sequence_capacity = 14;
  micro_ros_utilities_memory_rule_t rules[] = {
      {"header.frame_id", 10},
      {"auxilary", 2},
      {"buttons", 14}};
  conf.rules = rules;
  conf.n_rules = sizeof(rules) / sizeof(rules[0]);

  size_t dynamic_size = micro_ros_utilities_get_dynamic_size(
      ROSIDL_GET_MSG_TYPE_SUPPORT(bur_rov_msgs, msg, ThrusterCommand), conf);

  // The total (stack, static & dynamic) memory usage of a packet will be:

  size_t message_total_size = dynamic_size + sizeof(bur_rov_msgs__msg__ThrusterCommand);

  // The message dynamic memory can be allocated using the following call.
  // This will use rcutils default allocators for getting memory.

  bool success = micro_ros_utilities_create_message_memory(
      ROSIDL_GET_MSG_TYPE_SUPPORT(bur_rov_msgs, msg, ThrusterCommand), &msg, conf);

  state = WAITING_AGENT;
}

void loop()
{
  switch (state)
  {
  case WAITING_AGENT:
    turn_off_outputs();
    EXECUTE_EVERY_N_MS(500, state = (RMW_RET_OK == rmw_uros_ping_agent(200, 3)) ? AGENT_AVAILABLE : WAITING_AGENT;);
    break;
  case AGENT_AVAILABLE:
    state = (true == create_entities()) ? AGENT_CONNECTED : WAITING_AGENT;
    if (state == WAITING_AGENT)
    {
      destroy_entities();
    };
    break;
  case AGENT_CONNECTED:
    EXECUTE_EVERY_N_MS(200, state = (RMW_RET_OK == rmw_uros_ping_agent(200, 3)) ? AGENT_CONNECTED : AGENT_DISCONNECTED;);
    if (state == AGENT_CONNECTED)
    {
      rclc_executor_spin_some(&executor, RCL_MS_TO_NS(500));
    }
    break;
  case AGENT_DISCONNECTED:
    destroy_entities();
    state = WAITING_AGENT;
    break;
  default:
    turn_off_outputs();
    break;
  }
}