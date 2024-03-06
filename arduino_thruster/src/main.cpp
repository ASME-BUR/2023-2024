#include <Arduino.h>
#include <micro_ros_platformio.h>
#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <rcl/error_handling.h>
#include <std_msgs/msg/string.h>
#include <Servo.h>
#include "bur_rov_msgs/msg/thruster_command.h" 

rcl_subscription_t subscriber;
bur_rov_msgs__msg__ThrusterCommand msg;
rclc_executor_t executor;
rclc_support_t support;
rcl_allocator_t allocator;
rcl_node_t node;

#define MOTOR_COUNT 8
#define UTIL_COUNT 3
const uint8_t util_pin_begin = 6;
Servo motor[MOTOR_COUNT];

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
// subscription callback
void sub_callback(const void *msgin)
{
  const bur_rov_msgs__msg__ThrusterCommand *msg = (const bur_rov_msgs__msg__ThrusterCommand *)msgin;
  for (uint8_t i = 0; i < MOTOR_COUNT; i++)
  {
    motor[i].writeMicroseconds(msg->thrusters[i]);
  }
  for (uint8_t i = 0; i< UTIL_COUNT; i++){
    digitalWrite(i + util_pin_begin, msg->buttons[i]);
  }
}

void setup()
{
  // Initialize micro-ROS
  set_microros_serial_transports(Serial);
  Serial.begin(115200);
  // Initialize motors and outputs
  uint8_t motor_pin_begin = 2;
  for (uint8_t i = 0; i < MOTOR_COUNT; i++)
  {
    motor[i].attach(i + motor_pin_begin);
    motor[i].writeMicroseconds(1500);
  }
  for (uint8_t i = 0; i < UTIL_COUNT; i++)
  {
    pinMode(i + util_pin_begin, OUTPUT);
  }

  allocator = rcl_get_default_allocator();
  RCCHECK(rclc_support_init(&support, 0, NULL, &allocator));
  // // create node
  RCCHECK(rclc_node_init_default(&node, "arduino_node_thruster", "", &support));
  // create subscriber
  RCCHECK(rclc_subscription_init_default(&subscriber, &node,
                                         ROSIDL_GET_MSG_TYPE_SUPPORT(bur_rov_msgs, msg, ThrusterCommand),
                                         "thruster_command"));

  RCCHECK(rclc_executor_init(&executor, &support.context, 1, &allocator));
  RCCHECK(rclc_executor_add_subscription(&executor, &subscriber, &msg, &sub_callback, ON_NEW_DATA));
}

void loop()
{
  delay(100);
  RCCHECK(rclc_executor_spin_some(&executor, RCL_MS_TO_NS(100)));
}