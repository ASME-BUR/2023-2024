#ifndef BUR_NODES
#define BUR_NODES

#include <memory>

#include "behaviortree_cpp/action_node.h"
#include "geometry_msgs/msg/pose_stamped.hpp"

#include "manager_node.h"

class DriveAtDetected : public BT::StatefulActionNode
{
    public:
        DriveAtDetected(const std::string& name, const BT::NodeConfiguration& config,
                        const std::shared_ptr<SimpleManager> ptr,
                        const int object_label):
            BT::StatefulActionNode(name, config),
            node_(ptr),
            object_label_(object_label) {}
        
        static BT::PortsList providedPorts() { return {}; }

        BT::NodeStatus onStart() override   { return this->publish_joy(); }
        BT::NodeStatus onRunning() override { return this->publish_joy(); }

        void onHalted() override {}
    
    private: 
        std::shared_ptr<SimpleManager> node_;
        int object_label_;

        std::chrono::steady_clock::time_point timer_;
        bool not_seen_ = false;

        BT::NodeStatus publish_joy();

        sensor_msgs::msg::Joy msg;

};


class DriveForDuration : public BT::StatefulActionNode
{
    public:
        DriveForDuration(const std::string& name, const BT::NodeConfiguration& config,
                        const std::shared_ptr<SimpleManager> ptr,
                        const sensor_msgs::msg::Joy joy_msg,
                        const float duration):
            BT::StatefulActionNode(name, config),
            node_(ptr),
            joy_msg_(joy_msg),
            duration_(duration) {
                    begin_ = std::chrono::steady_clock::now();
            }

        static BT::PortsList providedPorts() { return {}; }

        BT::NodeStatus onStart() override   { return this->publish_joy(); }
        BT::NodeStatus onRunning() override { return this->publish_joy(); }

        void onHalted() override {}

    
    private:
        std::shared_ptr<SimpleManager> node_;
        float duration_;

        std::chrono::steady_clock::time_point begin_;

        sensor_msgs::msg::Joy joy_msg_;
        BT::NodeStatus publish_joy();
};


class FireTorpedo : public BT::SyncActionNode
{
    public:
        FireTorpedo(const std::string& name, const BT::NodeConfiguration& config,
                          const std::shared_ptr<SimpleManager> ptr, 
                          const std::string pub_topic):
            BT::SyncActionNode(name, config),
            node_(ptr),
            pub_topic_(pub_topic) {}

        static BT::PortsList providedPorts() { return {}; }

        BT::NodeStatus tick() override;
    
    private:
        std::shared_ptr<SimpleManager> node_;
        std::string pub_topic_;
};

class UpdateTarget : public BT::StatefulActionNode
{
    public:
        UpdateTarget(const std::string& name, const BT::NodeConfiguration& config,
                          const std::shared_ptr<geometry_msgs::msg::Pose> target):
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
                          const std::shared_ptr<SimpleManager> ptr):
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
