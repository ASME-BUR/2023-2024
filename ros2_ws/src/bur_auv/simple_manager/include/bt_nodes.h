#ifndef BUR_NODES
#define BUR_NODES

#include <memory>

#include "behaviortree_cpp/action_node.h"
#include "geometry_msgs/msg/pose_stamped.hpp"

#include "manager_node.h"

class UpdateTarget : public BT::StatefulActionNode
{
    public:
        UpdateTarget(const std::string& name, const BT::NodeConfiguration& config,
                          std::shared_ptr<geometry_msgs::msg::Pose> target):
            BT::StatefulActionNode(name, config),
            target_pos_ptr_(target) {}

        static BT::PortsList providedPorts() {
            return { BT::OutputPort<geometry_msgs::msg::Pose>("target") };
        }

        BT::NodeStatus onStart() override   { return this->getTarget(); }
        BT::NodeStatus onRunning() override { return this->getTarget(); }

        void onHalted() override {}

    
    private:
        std::shared_ptr<SimpleManager> node_;
        std::shared_ptr<geometry_msgs::msg::Pose> target_pos_ptr_;

        BT::NodeStatus getTarget();

};


class GoToTarget : public BT::StatefulActionNode
{
    public:
        GoToTarget(const std::string& name, const BT::NodeConfiguration& config,
                          std::shared_ptr<SimpleManager> ptr):
            BT::StatefulActionNode(name, config),
            node_(ptr) {}

        static BT::PortsList providedPorts() {
            return { BT::InputPort<geometry_msgs::msg::Pose>("target") };
        }

        BT::NodeStatus onStart() override   { return this->getStatus(); }
        BT::NodeStatus onRunning() override { return this->getStatus(); }

        void onHalted() override {}

    
    private:
        std::shared_ptr<SimpleManager> node_;
        geometry_msgs::msg::Pose target_pose_;

        BT::NodeStatus getStatus();

        bool successful = false;

        float tolerance_radius = 0.5;

};

#endif
