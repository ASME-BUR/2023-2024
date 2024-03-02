#include <micro_ros_arduino.h>
#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <std_msgs/msg/string.h>
#include "my_custom_msgs/msg/my_custom_message.h" // Include your custom message header

rcl_subscription_t subscriber;
my_custom_msgs__msg__MyCustomMessage msg;
rclc_support_t support;
rcl_allocator_t allocator;
rcl_node_t node;

void setup() {
  // Initialize micro-ROS
  set_microros_transports();
  
  allocator = rcl_get_default_allocator();
  rclc_support_init(&support, 0, NULL, &allocator);

  // Create an Arduino node
  rclc_node_init_default(&node, "micro_ros_arduino_node", "", &support);

  // Create a subscriber
  rclc_subscription_init_default(&subscriber, &node,
                                ROSIDL_GET_MSG_TYPE_SUPPORT(my_custom_msgs, msg, MyCustomMessage),
                                "my_custom_topic");

  // Initialize the message
  my_custom_msgs__msg__MyCustomMessage__init(&msg);
}

void loop() {
  // Spin the node to check for callback messages
  rcl_wait_set_t wait_set = rcl_get_zero_initialized_wait_set();
  rclc_wait_set_init_default(&wait_set, &support, 1, 0, 0, 0, 0);
  rclc_wait_set_clear(&wait_set);
  rclc_wait_set_add_subscription(&wait_set, &subscriber, &msg, NULL, &allocator);
  rclc_wait(&wait_set, RCL_MS_TO_NS(100));
  
  if (msg) {
    // Handle the custom message, printing the received data (for now)
    Serial.print("Received number: ");
    Serial.println(msg.my_number);
    Serial.print("Received string: ");
    Serial.println(msg.my_string);
  }
}