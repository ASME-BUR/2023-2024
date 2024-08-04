#ifndef BUR_NODES
#define BUR_NODES

#include <memory>

#include "behaviortree_cpp/action_node.h"
#include "geometry_msgs/msg/pose_stamped.hpp"

#include "manager_node.h"


class GoToTarget : public BT::SyncActionNode
{
    public:
        GoToTarget(const std::string& name, const BT::NodeConfig& config,
                         std::shared_ptr<SimpleManager> ptr):
            BT::SyncActionNode(name, config),
            node_(ptr) {}

        static BT::PortsList providedPorts() { return {}; }

        BT::NodeStatus tick() override;

        void testFunc(void (SimpleManager::*func)(int));
    
    private:
        geometry_msgs::msg::Pose target_pos_;
        std::shared_ptr<SimpleManager> node_;

        bool successful = false;

        void updateTargetPosition();
};

class IncrementCounter : public BT::SyncActionNode
{
    public:
        IncrementCounter(const std::string& name, const BT::NodeConfig& config,
                         std::shared_ptr<SimpleManager> ptr):
            BT::SyncActionNode(name, config),
            ptr(ptr) {}


        static BT::PortsList providedPorts() { return {}; }
        

        BT::NodeStatus tick() override {
            this->ptr->i++;
            std::cout << this->ptr->i << " " << this->name() << std::endl;
            return BT::NodeStatus::SUCCESS;
        }

        std::shared_ptr<SimpleManager> ptr;
};

#endif
