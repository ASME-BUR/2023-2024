#include <Arduino.h>
#include <micro_ros_platformio.h>

#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <rmw_microros/rmw_microros.h>

#include <sensor_msgs/msg/imu.h>
#include <sensor_msgs/msg/magnetic_field.h>
#include <bur_rov_msgs/msg/thruster_command.h>

#include "MTi.h"
#include <Wire.h>

#define DRDY 3       // Arduino Digital IO pin used as input for MTi-DRDY
#define ADDRESS 0x6B // MTi I2C address 0x6B (default I2C address for MTi 1-series)
MTi *IMU = NULL;
bool verbose = false;

// Publisher and msg obj
rcl_publisher_t publisher;
sensor_msgs__msg__Imu imu_msg;
sensor_msgs__msg__MagneticField mag_msg;
bool micro_ros_init_successful;

enum states
{
  WAITING_AGENT,
  AGENT_AVAILABLE,
  AGENT_CONNECTED,
  AGENT_DISCONNECTED
} state;

// Initialize micro-ros allocator
rcl_allocator_t allocator;
// Initialize support obj
rclc_support_t support;
// Create node obj
rcl_node_t node;
rcl_timer_t timer;

#define RCCHECK(fn)              \
  {                              \
    rcl_ret_t temp_rc = fn;      \
    if ((temp_rc != RCL_RET_OK)) \
    {                            \
      error_loop();              \
    }                            \
  }
#define RCSOFTCHECK(fn)          \
  {                              \
    rcl_ret_t temp_rc = fn;      \
    if ((temp_rc != RCL_RET_OK)) \
    {                            \
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

// Restart arduino
void (*resetFunc)(void) = 0;

// Error handle loop
void error_loop()
{
  while (1)
  {
    delay(100);
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
  RCCHECK(rclc_publisher_init_default(&publisher, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(sensor_msgs, msg, Imu), "imu"));
}

void destroy_entities()
{
  rmw_context_t *rmw_context = rcl_context_get_rmw_context(&support.context);
  (void)rmw_uros_set_context_entity_destroy_session_timeout(rmw_context, 0);

  rcl_publisher_fini(&publisher, &node);
  rcl_timer_fini(&timer);
  rclc_executor_fini(&executor);
  rcl_node_fini(&node);
  rclc_support_fini(&support);
}

void setup()
{
  // Configure serial transport
  Serial.begin(115200);
  set_microros_serial_transports(Serial);
  state = WAITING_AGENT;
  // IMU Initialization
  IMU = new MTi(ADDRESS, DRDY);
  Wire1.begin(); // Initialize Wire1 library for I2C communication
  pinMode(DRDY, INPUT);
  // pinMode(DRDY, INPUT);
  delay(1000);
  if (!IMU->detect(1, verbose))
  { // Check if MTi is detected before moving on
    delay(1000);
    resetFunc();
  }
  else
  {
    IMU->goToConfig(verbose); // Switch device to Config mode
    // IMU->requestDeviceInfo(verbose);   // Request the device's product code and firmware version
    IMU->configureOutputs(60, verbose); // Configure the device's outputs based on its functionality. See MTi::configureOutputs() for more alternative output configurations.
    // IMU->requestOutputs(verbose);
    IMU->requestOutputs(verbose);
  }
  delay(2000);
  IMU->goToMeasurement(); // Switch device to Measurement mode
}

void loop()
{
  if (digitalRead(DRDY))
  {
    IMU->readMessages(verbose);
    // IMU->printData();
  }
  switch (state)
  {
  case WAITING_AGENT:
    EXECUTE_EVERY_N_MS(100, state = (RMW_RET_OK == rmw_uros_ping_agent(100, 1)) ? AGENT_AVAILABLE : WAITING_AGENT;);
    break;
  case AGENT_AVAILABLE:
    state = (true == create_entities()) ? AGENT_CONNECTED : WAITING_AGENT;
    if (state == WAITING_AGENT)
    {
      destroy_entities();
    };
    break;
  case AGENT_CONNECTED:
    EXECUTE_EVERY_N_MS(100, state = (RMW_RET_OK == rmw_uros_ping_agent(100, 1)) ? AGENT_CONNECTED : AGENT_DISCONNECTED;);
    if (state == AGENT_CONNECTED)
    {
      // msg.header.stamp = ;
      imu_msg.linear_acceleration.x = (double)IMU->getAcceleration()[0];
      imu_msg.linear_acceleration.y = (double)IMU->getAcceleration()[1];
      imu_msg.linear_acceleration.z = (double)IMU->getAcceleration()[2];
      imu_msg.orientation.w = (double)IMU->getQuat()[0];
      imu_msg.orientation.x = (double)IMU->getQuat()[1];
      imu_msg.orientation.y = (double)IMU->getQuat()[2];
      imu_msg.orientation.z = (double)IMU->getQuat()[3];
      imu_msg.angular_velocity.x = (double)IMU->getRateOfTurn()[0];
      imu_msg.angular_velocity.y = (double)IMU->getRateOfTurn()[1];
      imu_msg.angular_velocity.z = (double)IMU->getRateOfTurn()[2];

      // Set covariance values
      double linear_acceleration_covariance[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
      double angular_velocity_covariance[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
      double orientation_covariance[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
      for (int i = 0; i < 9; i++)
      {
        imu_msg.linear_acceleration_covariance[i] = linear_acceleration_covariance[i];
        imu_msg.angular_velocity_covariance[i] = angular_velocity_covariance[i];
        imu_msg.orientation_covariance[i] = orientation_covariance[i];
      };
      // publish
      RCSOFTCHECK(rcl_publish(&publisher, &imu_msg, NULL));
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
