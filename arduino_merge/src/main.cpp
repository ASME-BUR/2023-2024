#include "main.hpp"

// Imu
rcl_publisher_t publisher_imu;
rcl_publisher_t publisher_mag;
sensor_msgs__msg__Imu imu_msg;
sensor_msgs__msg__MagneticField mag_msg;
// Thrusters
rcl_subscription_t subscriber;
bur_rov_msgs__msg__ThrusterCommand msg;

rclc_executor_t executor_pub;
rclc_executor_t executor_sub;
rcl_timer_t timer;
rclc_support_t support;
rcl_allocator_t allocator;
rcl_node_t node;

bool micro_ros_init_successful;

const uint8_t util_pin_begin = 24;
Servo motor[MOTOR_COUNT];
MTi *IMU = NULL;
bool verbose = false;

// subscription callback
void sub_callback(const void *msgin)
{
  // micro_ros_utilities_create_message_memory(ROSIDL_GET_MSG_TYPE_SUPPORT(bur_rov_msgs, msg, ThrusterCommand), &msgin, conf);
  const bur_rov_msgs__msg__ThrusterCommand *msg = (const bur_rov_msgs__msg__ThrusterCommand *)msgin;

  for (int i = 0; i < MOTOR_COUNT; i++)
  {
    motor[i].writeMicroseconds((int)(msg->thrusters.data[i + 1] * 400 + 1500));
  }

  for (int i = 0; i < UTIL_COUNT; i++)
  {
    digitalWrite(i * 2 + util_pin_begin, (msg->buttons.data[i * 3 - 2]));
  }
}

void timer_callback(rcl_timer_t *timer, int64_t last_call_time)
{
  (void)last_call_time;
  if (timer != NULL)
  {
    if (digitalRead(DRDY))
    {
      rmw_uros_sync_session(100);
      IMU->readMessages(verbose);
      imu_msg.header.stamp.sec = rmw_uros_epoch_nanos() / pow(10, 9);
      imu_msg.header.stamp.nanosec = rmw_uros_epoch_nanos();
      imu_msg.linear_acceleration.x = IMU->getAcceleration()[0];
      imu_msg.linear_acceleration.y = IMU->getAcceleration()[1];
      imu_msg.linear_acceleration.z = IMU->getAcceleration()[2];
      imu_msg.orientation.w = IMU->getQuat()[0];
      imu_msg.orientation.x = IMU->getQuat()[1];
      imu_msg.orientation.y = IMU->getQuat()[2];
      imu_msg.orientation.z = IMU->getQuat()[3];
      imu_msg.angular_velocity.x = IMU->getRateOfTurn()[0];
      imu_msg.angular_velocity.y = IMU->getRateOfTurn()[1];
      imu_msg.angular_velocity.z = IMU->getRateOfTurn()[2];

      mag_msg.header.stamp.sec = rmw_uros_epoch_nanos() / pow(10, 9);
      mag_msg.header.stamp.nanosec = rmw_uros_epoch_nanos();
      mag_msg.magnetic_field.x = IMU->getMag()[0];
      mag_msg.magnetic_field.y = IMU->getMag()[1];
      mag_msg.magnetic_field.z = IMU->getMag()[2];
      rcl_publish(&publisher_imu, &imu_msg, NULL);
      rcl_publish(&publisher_mag, &mag_msg, NULL);
    }
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
  // MicroROS config
  allocator = rcl_get_default_allocator();

  // create init_options
  RCCHECK(rclc_support_init(&support, 0, NULL, &allocator));

  // create node
  RCCHECK(rclc_node_init_default(&node, "arduino_node", "", &support));
  // create subscriber
  RCCHECK(rclc_subscription_init_best_effort(&subscriber, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(bur_rov_msgs, msg, ThrusterCommand), "thruster_command"));
  // create publisher
  RCCHECK(rclc_publisher_init_best_effort(&publisher_imu, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(sensor_msgs, msg, Imu), "imu"));
  RCCHECK(rclc_publisher_init_best_effort(&publisher_mag, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(sensor_msgs, msg, MagneticField), "mag"));

  const unsigned int timer_timeout = 7;
  RCCHECK(rclc_timer_init_default(&timer, &support, RCL_MS_TO_NS(timer_timeout), timer_callback));
  // create executor
  executor_pub = rclc_executor_get_zero_initialized_executor();
  executor_sub = rclc_executor_get_zero_initialized_executor();
  RCCHECK(rclc_executor_init(&executor_pub, &support.context, 1, &allocator));
  RCCHECK(rclc_executor_add_timer(&executor_pub, &timer));

  RCCHECK(rclc_executor_init(&executor_sub, &support.context, 1, &allocator));
  RCCHECK(rclc_executor_add_subscription(&executor_sub, &subscriber, &msg, &sub_callback, ON_NEW_DATA));

  return true;
}

void destroy_entities()
{
  rmw_context_t *rmw_context = rcl_context_get_rmw_context(&support.context);
  (void)rmw_uros_set_context_entity_destroy_session_timeout(rmw_context, 0);
  rcl_subscription_fini(&subscriber, &node);
  rcl_publisher_fini(&publisher_imu, &node);
  rcl_publisher_fini(&publisher_mag, &node);
  rcl_timer_fini(&timer);
  rclc_executor_fini(&executor_pub);
  rclc_executor_fini(&executor_sub);
  rcl_node_fini(&node);
  rclc_support_fini(&support);
  // sensor_msgs__msg__Imu__fini(&imu_msg);
  // sensor_msgs__msg__MagneticField__fini(&mag_msg);
}

void setup()
{

  // Configure serial transport
  SerialUSB.begin(115200);
  while (!SerialUSB)
  {
    delay(1);
  }
  set_microros_serial_transports(SerialUSB);
  Wire1.begin(); // Initialize Wire1 library for I2C communication
  Wire1.setClock(400000);
  state = WAITING_AGENT;

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

  // IMU Initialization
  IMU = new MTi(ADDRESS, DRDY);
  pinMode(DRDY, INPUT);
  IMU->configureOutputs(100);
  imu_msg.header.frame_id = micro_ros_string_utilities_init("imu");
  mag_msg.header.frame_id = micro_ros_string_utilities_init("mag");
  // Set covariance values
  // 70 * pow(10, -9) * sqrt(float(hz))
  double linear_acceleration_covariance[9] = {0.0000007, 0, 0,
                                              0, 0.0000007, 0,
                                              0, 0, 0.0000007};
  // 0.003 * (PI / 180) * sqrt(float(hz))
  double angular_velocity_covariance[9] = {0.000523598775598, 0, 0,
                                           0, 0.000523598775598, 0,
                                           0, 0, 0.000523598775598};
  double orientation_covariance[9] = {0.000000008726646259972, 0, 0,
                                      0, 0.000000008726646259972, 0,
                                      0, 0, 0.000000034906585039887};
  double magnetic_covariance[9] = {0.00005, 0, 0,
                                   0, 0.00005, 0,
                                   0, 0, 0.00005};

  for (int i = 0; i < 9; i++)
  {
    imu_msg.linear_acceleration_covariance[i] = linear_acceleration_covariance[i];
    imu_msg.angular_velocity_covariance[i] = angular_velocity_covariance[i];
    imu_msg.orientation_covariance[i] = orientation_covariance[i];
    mag_msg.magnetic_field_covariance[i] = magnetic_covariance[i];
  };
  IMU->resetInclination();
  IMU->goToMeasurement(); // Switch device to Measurement mode
  pinMode(13, OUTPUT);
}

void loop()
{
  switch (state)
  {
  case WAITING_AGENT:
    EXECUTE_EVERY_N_MS(500, state = (RMW_RET_OK == rmw_uros_ping_agent(100, 1)) ? AGENT_AVAILABLE : WAITING_AGENT;);
    break;
  case AGENT_AVAILABLE:
    state = (true == create_entities()) ? AGENT_CONNECTED : WAITING_AGENT;
    if (state == WAITING_AGENT)
    {
      destroy_entities();
    };
    break;
  case AGENT_CONNECTED:
    EXECUTE_EVERY_N_MS(200, state = (RMW_RET_OK == rmw_uros_ping_agent(100, 1)) ? AGENT_CONNECTED : AGENT_DISCONNECTED;);
    if (state == AGENT_CONNECTED)
    {
      rclc_executor_spin_some(&executor_pub, RCL_MS_TO_NS(10));
      rclc_executor_spin_some(&executor_sub, RCL_MS_TO_NS(5));
    }
    break;
  case AGENT_DISCONNECTED:
    destroy_entities();
    state = WAITING_AGENT;
    break;
  default:
    break;
  }
  if (state == AGENT_CONNECTED)
  {
    digitalWrite(13, 1);
  }
  else
  {
    digitalWrite(13, 0);
    turn_off_outputs();
  }
}