#include <Arduino.h>
#include <micro_ros_platformio.h>
#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <rcl/error_handling.h>
#include <rmw_microros/rmw_microros.h>

#include <Servo.h>
#include "bur_rov_msgs/msg/thruster_command.h"

#define RCCHECK(fn)              \
  {                              \
    rcl_ret_t temp_rc = fn;      \
    if ((temp_rc != RCL_RET_OK)) \
    {                            \
      return false;              \
    }                            \
  }
#define EXECUTE_EVERY_N_MS(MS, X)      \
  do                                   \
  {                                    \
    static volatile int64_t init = -1; \
    if (init == -1)                    \
    {                                  \
      init = uxr_millis();             \
    }                                  \
    if (uxr_millis() - init > MS)      \
    {                                  \
      X;                               \
      init = uxr_millis();             \
    }                                  \
  } while (0)

rcl_subscription_t subscriber;
bur_rov_msgs__msg__ThrusterCommand msg;
rclc_executor_t executor;
rcl_timer_t timer;
rclc_support_t support;
rcl_allocator_t allocator;
rcl_node_t node;
bool micro_ros_init_successful;

enum states
{
  WAITING_AGENT,
  AGENT_AVAILABLE,
  AGENT_CONNECTED,
  AGENT_DISCONNECTED
} state;

#define MOTOR_COUNT 9
#define UTIL_COUNT 3
const uint8_t util_pin_begin = 24;
Servo motor[MOTOR_COUNT];

// Restart arduino
void (*resetFunc)(void) = 0;

// subscription callback
void sub_callback(const void *msgin)
{
  const bur_rov_msgs__msg__ThrusterCommand *msg = (const bur_rov_msgs__msg__ThrusterCommand *)msgin;
  for (uint8_t i = 0; i < MOTOR_COUNT; i++)
  {
    motor[i].writeMicroseconds((int)(msg->thrusters[i] * 400 + 1500));
  }
  for (uint8_t i = 0; i < UTIL_COUNT; i++)
  {
    digitalWrite(i * 2 + util_pin_begin, msg->buttons[i]);
  }
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
  RCCHECK(rclc_subscription_init_default(&subscriber, &node,
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
  uint8_t motor_pin_begin = 3;
  for (uint8_t i = 0; i < MOTOR_COUNT; i++)
  {
    motor[i].attach(i + motor_pin_begin);
    motor[i].writeMicroseconds(1500);
  }
  for (uint8_t i = 0; i < UTIL_COUNT; i++)
  {
    pinMode(i * 2 + util_pin_begin, OUTPUT);
  }
  // Initialize micro-ROS
  Serial.begin(115200);
  set_microros_serial_transports(Serial);

  state = WAITING_AGENT;
}

void loop()
{
  switch (state)
  {
  case WAITING_AGENT:
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
    break;
  }
}