#ifndef BUR_NODES
#define BUR_NODES

#include <chrono>
#include <memory>

#include "behaviortree_cpp/action_node.h"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "geometry_msgs/msg/quaternion.hpp"

#include "tf2/LinearMath/Quaternion.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"


#include "manager_node.h"


class DriveForDuration : public BT::StatefulActionNode
{
    public:
        DriveForDuration(const std::string& name, const BT::NodeConfiguration& config,
                        const std::shared_ptr<SimpleManager> ptr,
                        const sensor_msgs::msg::Joy joy_msg,
                        const float duration):
            BT::StatefulActionNode(name, config),
            node_(ptr),
            joy_msg_(joy_msg) {
                begin_ = std::chrono::steady_clock::now();
            }

        static BT::PortsList providedPorts() { return {}; }

        BT::NodeStatus onStart() override   { return this->publish_joy(); }
        BT::NodeStatus onRunning() override { return this->publish_joy(); }

        void onHalted() override {}

        void setDuration(float duration) { this->duration_ = duration; }

    
    private:
        std::shared_ptr<SimpleManager> node_;
        float duration_;

        std::chrono::steady_clock::time_point begin_;

        sensor_msgs::msg::Joy joy_msg_;
        BT::NodeStatus publish_joy();
};

class DriveForDurationBlackboard : public DriveForDuration
{
    public:
        DriveForDurationBlackboard(const std::string& name, const BT::NodeConfiguration& config,
                        const std::shared_ptr<SimpleManager> ptr,
                        const sensor_msgs::msg::Joy joy_msg):
            DriveForDuration(name, config, ptr, joy_msg, 0.0) {}

        static BT::PortsList providedPorts() { return { BT::InputPort<float>("duration") }; }

        BT::NodeStatus onStart() override {
            updateDuration();
            DriveForDuration::onStart();
        }
        BT::NodeStatus onRunning() override {
            updateDuration();
            DriveForDuration::onRunning();
        }
    
    private:
        void updateDuration() {
            auto msg = getInput<float>("duration");
            if(!msg) {
                throw BT::RuntimeError("missing required input [duration]: ", 
                              msg.error() );
            }
            DriveForDuration::setDuration(msg.value());
        }

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

class SaveCurrentPoseToBlackboard : public BT::SyncActionNode
{
    public:
        SaveCurrentPoseToBlackboard(const std::string& name, const BT::NodeConfiguration& config,
                            const std::shared_ptr<SimpleManager> ptr):
            BT::SyncActionNode(name, config),
            node_(ptr) {}
        
        static BT::PortsList providedPorts() {
            return { BT::OutputPort<geometry_msgs::msg::Pose>("output") };
        }

        BT::NodeStatus tick() override {
            setOutput("output", this->node_->getCurrentPosition());
            return BT::NodeStatus::SUCCESS;
        }
    
    private:
        std::shared_ptr<SimpleManager> node_;
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

        std::shared_ptr<SimpleManager> getNode() { return this->node_; }

        void setTarget(const tf2::Quaternion& q) {
            this->target_ = tf2::toMsg(q);
        }

        BT::NodeStatus turn();

    private:
        std::shared_ptr<SimpleManager> node_;
        geometry_msgs::msg::Quaternion target_;
};

class TurnFromCurrentPosition : public TurnToOrientation
{
    public:
        TurnFromCurrentPosition(const std::string& name, const BT::NodeConfiguration& config,
                            const std::shared_ptr<SimpleManager> ptr,
                            const tf2::Quaternion q):
            TurnToOrientation(name,config, ptr, geometry_msgs::msg::Quaternion()),
            transf_(q) {}
        
        BT::NodeStatus onStart() override {
            auto initial_pos_ = this->getNode()->getCurrentPosition();
            this->initial_orientation_ = tf2::Quaternion(initial_pos_.orientation.x, 
                                                initial_pos_.orientation.y, 
                                                initial_pos_.orientation.z, 
                                                initial_pos_.orientation.w);
            return this->onRunning();
        }

        BT::NodeStatus onRunning() override {
            tf2::Quaternion q_new = this->transf_ * initial_orientation_;
            q_new.normalize();

            this->setTarget(q_new);

            return TurnToOrientation::onStart();
        }

        void setTransformation(tf2::Quaternion q) { this->transf_ = q; }

    private:
        tf2::Quaternion initial_orientation_;
        tf2::Quaternion transf_;
};

class TurnFromCurrentPositionBlackboard : public TurnFromCurrentPosition {
    public:
        TurnFromCurrentPositionBlackboard(const std::string& name, const BT::NodeConfiguration& config,
                            const std::shared_ptr<SimpleManager> ptr):
            TurnFromCurrentPosition(name, config, ptr, tf2::Quaternion()) {}
        
        static BT::PortsList providedPorts() { 
            return { BT::InputPort<float>("roll"),
                     BT::InputPort<float>("pitch"),
                     BT::InputPort<float>("yaw") }; 
        }


        BT::NodeStatus onStart() override {
            this->updateTransformation();
            return TurnFromCurrentPosition::onStart();
        }
        BT::NodeStatus onRunning() override {
            this->updateTransformation();
            return TurnFromCurrentPosition::onRunning();
        }
    
    private:
        void updateTransformation() {
            auto roll_msg = getInput<float>("roll");
            auto pitch_msg = getInput<float>("pitch");
            auto yaw_msg = getInput<float>("yaw");
            if(!roll_msg || pitch_msg || yaw_msg) {
                throw BT::RuntimeError("missing required input ");
            }

            tf2::Quaternion q_target;
            q_target.setRPY(roll_msg.value(), pitch_msg.value(), yaw_msg.value());
            
            this->setTransformation(q_target);
        }
};

class TurnToBlackboardOrientation : public TurnToOrientation
{
    public:
        TurnToBlackboardOrientation(const std::string& name, const BT::NodeConfiguration& config,
                            const std::shared_ptr<SimpleManager> ptr):
            TurnToOrientation(name, config, ptr, geometry_msgs::msg::Quaternion()) {}
        
        static BT::PortsList providedPorts() {
            return { BT::InputPort<geometry_msgs::msg::Pose>("orientation") };
        }


        BT::NodeStatus onStart() override { 
            this->updateTarget();
            return TurnToOrientation::turn();
        }
        BT::NodeStatus onRunning() override { 
            this->updateTarget();
            return TurnToOrientation::turn();
        }

        void updateTarget() {
            auto q_msg = getInput<geometry_msgs::msg::Pose>("orientation");

            if(!q_msg) {
                throw BT::RuntimeError("missing required input [orientation]: ", 
                              q_msg.error() );
            }

            tf2::Quaternion q;
            tf2::fromMsg(q_msg.value().orientation, q);

            this->setTarget(q);
        }
};


// Vision Nodes (unused)

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

#endif
