#include "manager_node.h"
#include "bt_nodes.h"

#include <chrono>
#include <cmath>
#include <iostream>
#include <thread>

#include "tf2/LinearMath/Matrix3x3.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/utils.h>

#include "sensor_msgs/msg/joy.hpp"

#include "geometry_msgs/msg/quaternion.hpp"


int getMatchingDetection(const std::vector<yolo_msgs::msg::CVDetection> detected,
                                    const int label) {
    for(int i = 0; i < detected.size(); i++) {
        if(detected[i].label == label) {
            return i;
        }
    }
    return -1;
}


BT::NodeStatus TurnTowardsBuoy::turn() {
    int idx = getMatchingDetection(this->node_->detected_, YOLO_BUOY);

    if(idx != -1) {
        return BT::NodeStatus::SUCCESS;
    }

    auto end = std::chrono::steady_clock::now();
    if(std::chrono::duration_cast<std::chrono::seconds> (end - this->begin_).count() > this->time_limit_) {
        return BT::NodeStatus::FAILURE;
    }

    // Set Odometry message
    double roll_state, pitch_state, yaw_state;

    auto current_pos = this->node_->getCurrentPosition();
    tf2::Quaternion q = tf2::Quaternion(current_pos.orientation.x, current_pos.orientation.y, current_pos.orientation.z, current_pos.orientation.w);
    tf2::Matrix3x3 rot_matrix = tf2::Matrix3x3(q);
    rot_matrix.getRPY(roll_state, pitch_state, yaw_state);

    // Turns counterclockwise
    tf2::Quaternion q_target;
    q_target.setRPY(roll_state, pitch_state, yaw_state + 0.2);

    this->odometry_msg_ = nav_msgs::msg::Odometry();
    odometry_msg_.pose.pose.orientation = tf2::toMsg(q_target);
    this->odometry_msg_.pose.pose.position.z = 1.0;

    // Set Joy message
    sensor_msgs::msg::Joy joy_msg;

    auto values = std::vector<double>(9, 0);
    auto buttons = std::vector<int>(10, 0);
    
    values[2] = -0.7;
    buttons[9] = 1;

    values[5] = (this->node_->buoy_is_left_) ? -1.0 : 1.0;

    for (size_t i = 0; i < values.size(); i++) {
            joy_msg.axes.push_back(values[i]);
    }
    for (size_t i = 0; i < buttons.size(); i++) {
            joy_msg.buttons.push_back(buttons[i]);
    }

    this->node_->publish_joy_msg(joy_msg);
    this->node_->publish_odometry_msg(this->odometry_msg_);

    return BT::NodeStatus::RUNNING;

}

BT::NodeStatus DriveAtDetected::publish_joy() {
    int idx = getMatchingDetection(this->node_->detected_, this->object_label_);

    if(idx >= 0) {
        this->not_seen_ = false;

        auto detection = this->node_->detected_[idx];
        this->target_distance_ = detection.bbox.pose.position.z;

        // Set Odometry message
        double roll_state, pitch_state, yaw_state;

        auto current_pos = this->node_->getCurrentPosition();
        tf2::Quaternion q = tf2::Quaternion(current_pos.orientation.x, current_pos.orientation.y, current_pos.orientation.z, current_pos.orientation.w);
        tf2::Matrix3x3 rot_matrix = tf2::Matrix3x3(q);
        rot_matrix.getRPY(roll_state, pitch_state, yaw_state);

        // ZED Mini FOV is approx. 66 degrees = 1.152 rad
        double yaw_change_target = -0.576 * (detection.bbox.pose.position.x / ZED_WIDTH - 0.5);

        tf2::Quaternion q_target;
        q_target.setRPY(roll_state, pitch_state, yaw_state + yaw_change_target);

        this->odometry_msg_ = nav_msgs::msg::Odometry();
        odometry_msg_.pose.pose.orientation = tf2::toMsg(q_target);
        this->odometry_msg_.pose.pose.position.z = 1.0;

        // Set Joy message
        this->joy_msg_ = sensor_msgs::msg::Joy();

        auto values = std::vector<double>(9, 0);
        auto buttons = std::vector<int>(10, 0);
        
        values[2] = -0.7;
        values[0] = 1.0;
        buttons[9] = 1;

        for (size_t i = 0; i < values.size(); i++) {
                this->joy_msg_.axes.push_back(values[i]);
        }
        for (size_t i = 0; i < buttons.size(); i++) {
                this->joy_msg_.buttons.push_back(buttons[i]);
        }

        this->node_->publish_joy_msg(joy_msg_);
        this->node_->publish_odometry_msg(this->odometry_msg_);

        if(detection.width > ZED_WIDTH * 0.5 || detection.height > ZED_HEIGHT * 0.5) {
            return BT::NodeStatus::SUCCESS;
        }

        return BT::NodeStatus::RUNNING;
    } else {
        if(!this->not_seen_) {
            this->timer_ = std::chrono::steady_clock::now();
        } else {
            this->not_seen_ = true;

            auto end = std::chrono::steady_clock::now();
            if(std::chrono::duration_cast<std::chrono::seconds> (end - this->timer_).count() > 1.5) {
                return BT::NodeStatus::SUCCESS;
            }
        }
        this->node_->publish_joy_msg(joy_msg_);
        this->node_->publish_odometry_msg(this->odometry_msg_);

        return BT::NodeStatus::RUNNING;
    }
}


BT::NodeStatus DriveForDuration::publish_joy() {
    auto end = std::chrono::steady_clock::now();
    if(std::chrono::duration_cast<std::chrono::seconds> (end - this->begin_).count() > this->duration_) {
        return BT::NodeStatus::SUCCESS;
    }

    this->node_->publish_joy_msg(this->joy_msg_);

    return BT::NodeStatus::RUNNING;
}


BT::NodeStatus FireTorpedo::tick() {
    sensor_msgs::msg::Joy msg;

    auto values = std::vector<double>(9, 0);
    auto buttons = std::vector<int>(10, 0);
    
    values[2] = -0.7;
    values[0] = 1.0;
    buttons[9] = 1;

    for (size_t i = 0; i < values.size(); i++) {
            msg.axes.push_back(values[i]);
    }
    for (size_t i = 0; i < buttons.size(); i++) {
            msg.buttons.push_back(buttons[i]);
    }

    this->node_->publish_joy_msg(msg);

    return BT::NodeStatus::SUCCESS;
}

BT::NodeStatus TurnToOrientation::turn() {
    double roll_state, pitch_state, yaw_state;

    auto current_pos = this->node_->getCurrentPosition();
    tf2::Quaternion q = tf2::Quaternion(current_pos.orientation.x, current_pos.orientation.y, current_pos.orientation.z, current_pos.orientation.w);
    tf2::Matrix3x3 rot_matrix = tf2::Matrix3x3(q);
    rot_matrix.getRPY(roll_state, pitch_state, yaw_state);

    double roll_target, pitch_target, yaw_target;
    tf2::Quaternion q_target = tf2::Quaternion(target_.x, target_.y, target_.z, target_.w);
    tf2::Matrix3x3(q_target).getRPY(roll_target, pitch_target, yaw_target);

    if(abs(roll_target - roll_state) < 0.1 && abs(pitch_target - pitch_state) < 0.1
        && abs(yaw_target - yaw_state) < 0.1) {
        return BT::NodeStatus::SUCCESS;
    }

    auto odometry_msg_ = nav_msgs::msg::Odometry();
    odometry_msg_.pose.pose.orientation = this->target_;
    odometry_msg_.pose.pose.position.z = 1.0;

    this->node_->publish_odometry_msg(odometry_msg_);

    return BT::NodeStatus::RUNNING;
}
