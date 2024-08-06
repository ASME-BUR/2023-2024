#include "manager_node.h"
#include "bt_nodes.h"

#include <cmath>

BT::NodeStatus GoToTarget::tick() {
    if(this->successful) {
        return BT::NodeStatus::SUCCESS;
    }

    float dist = sqrt(pow(this->target_pos_ptr_->position.x - this->node_->getCurrentPosition().position.x, 2)
            + pow(this->target_pos_ptr_->position.y - this->node_->getCurrentPosition().position.y, 2)
            + pow(this->target_pos_ptr_->position.z - this->node_->getCurrentPosition().position.z, 2));

    if(dist < this->tolerance_radius) {
        this->successful = true;
        return BT::NodeStatus::SUCCESS;
    }

    this->node_->set_goal_pose(*this->target_pos_ptr_);

    return BT::NodeStatus::RUNNING;
}