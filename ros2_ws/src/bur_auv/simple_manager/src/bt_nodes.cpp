#include "manager_node.h"
#include "bt_nodes.h"

#include <cmath>
#include <iostream>


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
