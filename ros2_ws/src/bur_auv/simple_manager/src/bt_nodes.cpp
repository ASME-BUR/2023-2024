#include "manager_node.h"
#include "bt_nodes.h"

BT::NodeStatus GoToTarget::tick() {
    if(this->successful) {
        return BT::NodeStatus::SUCCESS;
    }

    this->node_->set_goal_pose(this->target_pos_);
}