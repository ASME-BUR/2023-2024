#ifndef BUR_NODES
#define BUR_NODES

#include <memory>

#include "behaviortree_cpp/action_node.h"
#include "geometry_msgs/msg/pose_stamped.hpp"

#include "manager_node.h"


class GoToTarget : public BT::StatefulActionNode
{
    public:
        GoToTarget(const std::string& name, const BT::NodeConfiguration& config,
                          std::shared_ptr<SimpleManager> ptr,
                          std::shared_ptr<geometry_msgs::msg::Pose> target):
            BT::StatefulActionNode(name, config),
            node_(ptr),
            target_pos_ptr_(target) {}

        static BT::PortsList providedPorts() { return {}; }

        BT::NodeStatus onStart() override;
        BT::NodeStatus onRunning() override;

        void onHalted() override {}

    
    private:
        std::shared_ptr<SimpleManager> node_;
        std::shared_ptr<geometry_msgs::msg::Pose> target_pos_ptr_;

        BT::NodeStatus getStatus();

        bool successful = false;

        int tolerance_radius = 0.5;

};

#endif
