#include <Arduino.h>
#include <micro_ros_platformio.h>

#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

#include <sensor_msgs/msg/imu.h>
#include <sensor_msgs/msg/magnetic_field.h>
#include <bur_rov_msgs/msg/thrustercommand.h>

#include "MTi.h"
#include <Wire.h>

#define DRDY 3       // Arduino Digital IO pin used as input for MTi-DRDY
#define ADDRESS 0x6B // MTi I2C address 0x6B (default I2C address for MTi 1-series)
MTi *IMU = NULL;

// Publisher and msg obj
rcl_publisher_t publisher;
sensor_msgs__msg__Imu imu_msg;
sensor_msgs__msg__MagneticField mag_msg;

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

void imu_callback()
{
  // IMU->readMessages();
  // // IMU->readMessages(); // Read new data messages
  // // IMU->printData();    //...and print them to the serial monitor (Ctrl+Shift+M)
  // // msg.header.stamp = ;
  // imu_msg.linear_acceleration.x = (double)IMU->getAcceleration()[0];
  // imu_msg.linear_acceleration.y = (double)IMU->getAcceleration()[1];
  // imu_msg.linear_acceleration.z = (double)IMU->getAcceleration()[2];
  // imu_msg.orientation.w = (double)IMU->getQuat()[0];
  // imu_msg.orientation.x = (double)IMU->getQuat()[0];
  // imu_msg.orientation.y = (double)IMU->getQuat()[0];
  // imu_msg.orientation.z = (double)IMU->getQuat()[0];
  // imu_msg.angular_velocity.x = (double)IMU->getRateOfTurn()[0];
  // imu_msg.angular_velocity.y = (double)IMU->getRateOfTurn()[0];
  // imu_msg.angular_velocity.z = (double)IMU->getRateOfTurn()[0];

  // // Set covariance values
  // double linear_acceleration_covariance[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  // double angular_velocity_covariance[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  // double orientation_covariance[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  // for (int i = 0; i < 9; i++)
  // {
  //   imu_msg.linear_acceleration_covariance[i] = linear_acceleration_covariance[i];
  //   imu_msg.angular_velocity_covariance[i] = angular_velocity_covariance[i];
  //   imu_msg.orientation_covariance[i] = orientation_covariance[i];
  // };
  // // publish
  // RCSOFTCHECK(rcl_publish(&publisher, &imu_msg, NULL));
}

void setup()
{
  // Configure serial transport
  Serial.begin(115200);
  set_microros_serial_transports(Serial);

  // IMU Initialization
  IMU = new MTi(ADDRESS, DRDY);
  Wire1.begin();         // Initialize Wire1 library for I2C communication
  pinMode(DRDY, INPUT);
  // pinMode(DRDY, INPUT);
  delay(1000);
  if (!IMU->detect(1, false))
  { // Check if MTi is detected before moving on
    // Serial.println("Please check your hardware connections. Resetting ...");
    delay(1000);
    resetFunc();
  }
  else
  {
    IMU->goToConfig(true);        // Switch device to Config mode
    IMU->requestDeviceInfo(true); // Request the device's product code and firmware version
    IMU->configureOutputs(1, true);  // Configure the device's outputs based on its functionality. See MTi::configureOutputs() for more alternative output configurations.
    IMU->requestOutputs(true);
    IMU->requestOutputs(true);
    // attachInterrupt(DRDY, imu_callback, CHANGE);
  }
  delay(5000);

  // MicroROS config
  // allocator = rcl_get_default_allocator();
  // // create init_options
  // RCCHECK(rclc_support_init(&support, 0, NULL, &allocator));
  // // create node
  // RCCHECK(rclc_node_init_default(&node, "arduino_node", "", &support));
  // // create publisher
  // RCCHECK(rclc_publisher_init_default(&publisher, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(sensor_msgs, msg, Imu), "imu"));

  IMU->goToMeasurement(); // Switch device to Measurement mode
}

void loop()
{
  // IMU->readMessages(); // Read new data messages
  // IMU->printData();
  if (digitalRead(DRDY))
  {
    IMU->readMessages(true);
    IMU->printData();
    // msg.header.stamp = ;
    // imu_msg.linear_acceleration.x = (double)IMU->getAcceleration()[0];
    // imu_msg.linear_acceleration.y = (double)IMU->getAcceleration()[1];
    // imu_msg.linear_acceleration.z = (double)IMU->getAcceleration()[2];
    // imu_msg.orientation.w = (double)IMU->getQuat()[0];
    // imu_msg.orientation.x = (double)IMU->getQuat()[1];
    // imu_msg.orientation.y = (double)IMU->getQuat()[2];
    // imu_msg.orientation.z = (double)IMU->getQuat()[3];
    // imu_msg.angular_velocity.x = (double)IMU->getRateOfTurn()[0];
    // imu_msg.angular_velocity.y = (double)IMU->getRateOfTurn()[1];
    // imu_msg.angular_velocity.z = (double)IMU->getRateOfTurn()[2];

    // Set covariance values
    // double linear_acceleration_covariance[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    // double angular_velocity_covariance[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    // double orientation_covariance[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    // for (int i = 0; i < 9; i++)
    // {
    //   imu_msg.linear_acceleration_covariance[i] = linear_acceleration_covariance[i];
    //   imu_msg.angular_velocity_covariance[i] = angular_velocity_covariance[i];
    //   imu_msg.orientation_covariance[i] = orientation_covariance[i];
    // };
    // // publish
    // RCSOFTCHECK(rcl_publish(&publisher, &imu_msg, NULL));
  }
}
