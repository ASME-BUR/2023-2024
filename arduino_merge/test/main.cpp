#include <Arduino.h>
#include <micro_ros_platformio.h>

#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <rmw_microros/rmw_microros.h>
#include <micro_ros_utilities/string_utilities.h>

#include <sensor_msgs/msg/imu.h>
#include <sensor_msgs/msg/magnetic_field.h>

#include "MTi.h"
#include <Wire.h>

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

#define DRDY 3       // Arduino Digital IO pin used as input for MTi-DRDY
#define ADDRESS 0x6B // MTi I2C address 0x6B (default I2C address for MTi 1-series)
MTi *IMU = NULL;
bool verbose = false;

// Publisher and msg obj
rcl_publisher_t publisher_imu;
rcl_publisher_t publisher_mag;
sensor_msgs__msg__Imu imu_msg;
sensor_msgs__msg__MagneticField mag_msg;
rcl_allocator_t allocator;
rclc_support_t support;
rcl_node_t node;
rcl_timer_t timer;
rclc_executor_t executor;
bool micro_ros_init_successful;
// float accel_offset[3] = {0};
// float quat_offset[4] = {0};
// float mag_offset[3] = {0};
// float omega_offset[3] = {0};

enum states
{
  WAITING_AGENT,
  AGENT_AVAILABLE,
  AGENT_CONNECTED,
  AGENT_DISCONNECTED
} state;

// Restart arduino
void (*resetFunc)(void) = 0;

void timer_callback(rcl_timer_t *timer, int64_t last_call_time)
{
  (void)last_call_time;
  if (timer != NULL)
  {
    if (digitalRead(DRDY))
    {
      rmw_uros_sync_session(100);
      IMU->readMessages(verbose);
      imu_msg.header.stamp.sec = rmw_uros_epoch_millis() / pow(10, 3);
      imu_msg.header.stamp.nanosec = rmw_uros_epoch_nanos();
      imu_msg.header.frame_id = micro_ros_string_utilities_init("odom");
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
      mag_msg.header.frame_id = micro_ros_string_utilities_init("odom");
      mag_msg.magnetic_field.x = IMU->getMag()[0];
      mag_msg.magnetic_field.y = IMU->getMag()[1];
      mag_msg.magnetic_field.z = IMU->getMag()[2];

      // Set covariance values
      // 70 * pow(10, -9) * sqrt(float(hz))
      double linear_acceleration_covariance[9] = {0.0000007, 0, 0,
                                                  0, 0.0000007, 0,
                                                  0, 0, 0.0000007};
      // 0.003 * (PI / 180) * sqrt(float(hz))
      double angular_velocity_covariance[9] = {0.000523598775598, 0, 0,
                                               0, 0.000523598775598, 0,
                                               0, 0, 0.000523598775598};
      double orientation_covariance[9] = {0.008726646259972, 0, 0,
                                          0, 0.008726646259972, 0,
                                          0, 0, 0.034906585039887};
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
      rcl_publish(&publisher_imu, &imu_msg, NULL);
      rcl_publish(&publisher_mag, &mag_msg, NULL);
    }
  }
}

bool create_entities()
{
  // MicroROS config
  allocator = rcl_get_default_allocator();
  // // create init_options
  RCCHECK(rclc_support_init(&support, 0, NULL, &allocator));
  // // create node
  RCCHECK(rclc_node_init_default(&node, "arduino_node_imu", "", &support));
  // // create publisher
  RCCHECK(rclc_publisher_init_best_effort(&publisher_imu, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(sensor_msgs, msg, Imu), "imu"));
  RCCHECK(rclc_publisher_init_best_effort(&publisher_mag, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(sensor_msgs, msg, MagneticField), "mag"));
  const float timer_timeout = 0.7;
  RCCHECK(rclc_timer_init_default(
      &timer,
      &support,
      RCL_MS_TO_NS(timer_timeout),
      timer_callback));
  // create executor
  RCCHECK(rclc_executor_init(&executor, &support.context, 1, &allocator));
  RCCHECK(rclc_executor_add_timer(&executor, &timer));
  return true;
}

void destroy_entities()
{
  rmw_context_t *rmw_context = rcl_context_get_rmw_context(&support.context);
  (void)rmw_uros_set_context_entity_destroy_session_timeout(rmw_context, 0);

  rcl_publisher_fini(&publisher_imu, &node);
  rcl_publisher_fini(&publisher_mag, &node);
  rcl_timer_fini(&timer);
  rclc_executor_fini(&executor);
  rcl_node_fini(&node);
  rclc_support_fini(&support);
}

void setup()
{
  // IMU Initialization
  IMU = new MTi(ADDRESS, DRDY);
  Wire1.begin(); // Initialize Wire1 library for I2C communication
  Wire1.setClock(400000);
  pinMode(DRDY, INPUT);
  // Configure serial transport
  SerialUSB.begin(250000);
  delay(1000);
  set_microros_serial_transports(SerialUSB);
  state = WAITING_AGENT;
  // IMU->configureOutputs(100);
  IMU->resetAlignment();
  IMU->goToMeasurement(); // Switch device to Measurement mode
}

void loop()
{
  switch (state)
  {
  case WAITING_AGENT:
    EXECUTE_EVERY_N_MS(500, state = (RMW_RET_OK == rmw_uros_ping_agent(50, 1)) ? AGENT_AVAILABLE : WAITING_AGENT;);
    break;
  case AGENT_AVAILABLE:
    state = (true == create_entities()) ? AGENT_CONNECTED : WAITING_AGENT;
    if (state == WAITING_AGENT)
    {
      destroy_entities();
    };
    break;
  case AGENT_CONNECTED:
    EXECUTE_EVERY_N_MS(200, state = (RMW_RET_OK == rmw_uros_ping_agent(50, 1)) ? AGENT_CONNECTED : AGENT_DISCONNECTED;);
    if (state == AGENT_CONNECTED)
    {
      rclc_executor_spin_some(&executor, RCL_MS_TO_NS(10));
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
