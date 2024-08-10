#ifndef BUR_NODES
#define BUR_NODES

#include <chrono>
#include <memory>

#include "behaviortree_cpp/action_node.h"
#include "geometry_msgs/msg/pose_stamped.hpp"

#include "manager_node.h"


class TurnTowardsBuoy : public BT::StatefulActionNode
{
    public:
        TurnTowardsBuoy(const std::string& name, const BT::NodeConfiguration& config,
                        const std::shared_ptr<SimpleManager> ptr):
            BT::StatefulActionNode(name, config),
            node_(ptr) {
            this->node_->gate_complete = true;
            begin_ = std::chrono::steady_clock::now();
        }
        
        static BT::PortsList providedPorts() { return {}; }

        BT::NodeStatus onStart() override   { return this->turn(); }
        BT::NodeStatus onRunning() override { return this->turn(); }

        void onHalted() override {}
    
    private: 
        std::shared_ptr<SimpleManager> node_;

        std::chrono::steady_clock::time_point begin_;
        float time_limit_ = 10.0;

        BT::NodeStatus turn();
        nav_msgs::msg::Odometry odometry_msg_;

};

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

        float target_distance_ = -1.0;
        float stop_distance_ = 3.0;

        BT::NodeStatus publish_joy();

        sensor_msgs::msg::Joy joy_msg_;
        nav_msgs::msg::Odometry odometry_msg_;

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
                          const std::shared_ptr<SimpleManager> ptr):
            BT::SyncActionNode(name, config),
            node_(ptr) {}

        static BT::PortsList providedPorts() { return {}; }

        BT::NodeStatus tick() override;
    
    private:
        std::shared_ptr<SimpleManager> node_;
        std::string pub_topic_;
};

class TurnToOrientation : public BT::StatefulActionNode
{
    public:
        TurnToOrientation(const std::string& name, const BT::NodeConfiguration& config,
                            const std::shared_ptr<SimpleManager> ptr,
                            const geometry_msgs::msg::Quaternion quat):
            BT::StatefulActionNode(name, config),
            node_(ptr),
            target_(quat) {}
        
        static BT::PortsList providedPorts() { return {}; }

        BT::NodeStatus onStart() override   { return this->turn(); }
        BT::NodeStatus onRunning() override { return this->turn(); }

        void onHalted() override {}

    private:
        std::shared_ptr<SimpleManager> node_;
        geometry_msgs::msg::Quaternion target_;

        BT::NodeStatus turn();
};

#endif
