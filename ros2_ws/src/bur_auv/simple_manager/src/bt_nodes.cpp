#include "manager_node.h"
#include "bt_nodes.h"

#include <chrono>
#include <cmath>
#include <iostream>
#include <thread>

#include "sensor_msgs/msg/joy.hpp"

int getMatchingDetection(const std::vector<yolo_msgs::msg::CVDetection> detected,
                                    const int label) {
    for(int i = 0; i < detected.size(); i++) {
        if(detected[i].label == label) {
            return i;
        }
    }
    return -1;
}

BT::NodeStatus DriveAtDetected::publish_joy() {
    int idx = getMatchingDetection(this->node_->detected_, this->object_label_);

    if(idx >= 0) {
        this->not_seen_ = false;

        auto detection = this->node_->detected_[idx];
        int center_tolerance = 20;

        bool center_in_bbox = (ZED_WIDTH / 2 >= detection.bbox.pose.position.x - detection.width / 2)
            && (ZED_WIDTH / 2 < detection.bbox.pose.position.x + detection.width / 2)
            && (ZED_HEIGHT / 2 < detection.bbox.pose.position.y + detection.height / 2)
            && (ZED_HEIGHT / 2 < detection.bbox.pose.position.y + detection.height / 2);
        
        bool bbox_is_centered = (abs(detection.bbox.pose.position.x - ZED_WIDTH / 2) < center_tolerance)
            && (abs(detection.bbox.pose.position.y - ZED_HEIGHT / 2) < center_tolerance);
        
        this->msg = sensor_msgs::msg::Joy();

        this->node_->publish_joy_msg(msg);

        if(detection.width > ZED_WIDTH * 0.5 || detection.height > ZED_HEIGHT * 0.5) {
            return BT::NodeStatus::RUNNING;
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
        this->node_->publish_joy_msg(msg);

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
    return BT::NodeStatus::SUCCESS;
}


BT::NodeStatus UpdateTarget::getTarget() {
    setOutput("target",  *this->target_pos_ptr_);
    return BT::NodeStatus::SUCCESS;
}


BT::NodeStatus GoToTarget::getStatus() {
    if(this->successful) {
        return BT::NodeStatus::SUCCESS;
    }

    auto msg = getInput<geometry_msgs::msg::Pose>("target");
    
    if(msg) {
        this->target_pose_ = msg.value();
    }

    float dist = sqrt(pow(this->target_pose_.position.x - this->node_->getCurrentPosition().position.x, 2)
            + pow(this->target_pose_.position.y - this->node_->getCurrentPosition().position.y, 2)
            + pow(this->target_pose_.position.z - this->node_->getCurrentPosition().position.z, 2));


    if(dist < this->tolerance_radius) {
        this->successful = true;
        return BT::NodeStatus::SUCCESS;
    }

    this->node_->set_goal_pose(this->target_pose_);

    return BT::NodeStatus::RUNNING;
}
