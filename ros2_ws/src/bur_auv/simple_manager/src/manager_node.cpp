#include "manager_node.h"
#include "bt_nodes.h"

#include "tf2/exceptions.h"
#include "rclcpp/rclcpp.hpp"


SimpleManager::SimpleManager() : rclcpp::Node::Node("simple_manager")
{
    this->declare_parameter("localizer_topic", "/odometry/filtered");
    this->declare_parameter("vision_topic", "/vision");

    this->declare_parameter("goal_topic", "/goal_pose");
    this->declare_parameter("joy_topic", "/joy");
    this->declare_parameter("waypoint_topic", "/des_pose");
    this->declare_parameter("pub_rate", 10);

    this->declare_parameter("behavior_tree", "tree.xml");
    this->declare_parameter("tick_rate", 10);

    this->declare_parameter("auto_shutdown", false);


    int pub_rate = this->get_parameter("pub_rate").as_int();
    int tick_rate = this->get_parameter("tick_rate").as_int();

    localizer_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
        this->get_parameter("localizer_topic").as_string(), 
        10, std::bind(&SimpleManager::localizer_callback, this, std::placeholders::_1));
    vision_sub_ = this->create_subscription<yolo_msgs::msg::CVDetections>(
        this->get_parameter("vision_topic").as_string(),
        10, std::bind(&SimpleManager::vision_callback, this, std::placeholders::_1));

    goal_pose_pub_ = this->create_publisher<geometry_msgs::msg::PoseStamped>(
        this->get_parameter("goal_topic").as_string(), 10);
    joy_pub_ = this->create_publisher<sensor_msgs::msg::Joy>(
        this->get_parameter("joy_topic").as_string(), 10);
    odometry_pub_ = this->create_publisher<nav_msgs::msg::Odometry>(
        this->get_parameter("waypoint_topic").as_string(), 10);

    pubTimer_ = this->create_wall_timer(
        std::chrono::milliseconds(1000 / pub_rate), 
        std::bind(&SimpleManager::publish_goal_pose, this));
    btTimer_ = this->create_wall_timer(
        std::chrono::milliseconds(1000 / tick_rate), 
        std::bind(&SimpleManager::tick_behavior, this));

    tf_buffer_ = std::make_unique<tf2_ros::Buffer>(this->get_clock());
    tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);

}

void SimpleManager::initialize_targets() {
    this->declare_parameter("start_position.x", 0.0);
    this->declare_parameter("start_position.y", 0.0);
    this->declare_parameter("start_position.z", 0.0);

    this->declare_parameter("gate_position.x", 5.0);
    this->declare_parameter("gate_position.y", 0.0);
    this->declare_parameter("gate_position.z", 0.0);

    this->start_position_->position.x = this->get_parameter("start_position.x").as_double();
    this->start_position_->position.y = this->get_parameter("start_position.y").as_double();
    this->start_position_->position.z = this->get_parameter("start_position.z").as_double();

    this->gate_position_->position.x = this->get_parameter("gate_position.x").as_double();
    this->gate_position_->position.y = this->get_parameter("gate_position.y").as_double();
    this->gate_position_->position.z = this->get_parameter("gate_position.z").as_double();
}

void SimpleManager::initialize_tree(BT::BehaviorTreeFactory &factory) {
    factory.registerBehaviorTreeFromFile(this->get_parameter("behavior_tree").as_string());
    this->behavior_tree_ = factory.createTree("MainTree");
}

void SimpleManager::localizer_callback(const nav_msgs::msg::Odometry::SharedPtr msg) {
    // try {
    //     this->baselink2Odom = tf_buffer_->lookupTransform("odom", "base_link", tf2::TimePointZero);
    // } catch (const tf2::TransformException& ex) {
    //     RCLCPP_INFO(this->get_logger(), "Could no transform base_link to odom: %s", ex.what());
    // }

    this->current_pos_ = msg->pose.pose;
    this->current_vel_ = msg->twist.twist;
}

void SimpleManager::vision_callback(const yolo_msgs::msg::CVDetections::SharedPtr msg) {
    this->detected_ = msg->detected;

    if(!gate_complete) {
        yolo_msgs::msg::CVDetection buoy_detection;

        for(int i = 0; i<this->detected_.size(); i++) {
            if(this->detected_[i].label == YOLO_BUOY) {
                if(this->detected_[i].bbox.pose.position.x > ZED_WIDTH / 2) {
                    this->buoy_is_left_ = false;
                } else {
                    this->buoy_is_left_ = true;
                }
                break;
            }
        }
    }
}

void SimpleManager::set_goal_pose(geometry_msgs::msg::Pose target_pos) {
    this->goal_pose_ = target_pos;
}

void SimpleManager::publish_joy_msg(sensor_msgs::msg::Joy joy_msg) {
    this->joy_pub_->publish(joy_msg);
}

void SimpleManager::publish_odometry_msg(nav_msgs::msg::Odometry odometry_msg) {
    this->odometry_pub_->publish(odometry_msg);
}


void SimpleManager::publish_goal_pose() {
    geometry_msgs::msg::PoseStamped msg;
    msg.pose = this->goal_pose_;
    this->goal_pose_pub_->publish(msg);
}

void SimpleManager::tick_behavior() {
    BT::NodeStatus status = this->behavior_tree_.tickOnce();

    if(status == BT::NodeStatus::SUCCESS &&
        this->get_parameter("auto_shutdown").as_bool()) {
        rclcpp::shutdown();
    } else if (status == BT::NodeStatus::FAILURE) {
        RCLCPP_INFO(this->get_logger(), "Tree failed");
        rclcpp::shutdown();
    }
}

int main(int argc, char * argv[])
{

    rclcpp::init(argc, argv);

    BT::BehaviorTreeFactory factory;

    auto manager = std::make_shared<SimpleManager>();

    sensor_msgs::msg::Joy submerge_msg;

    std::vector<double> values(9, 0);
    std::vector<int> buttons(10, 0);

    values[2] = -0.7;
    buttons[9] = 1;
    for (size_t i = 0; i < values.size(); i++) {
            submerge_msg.axes.push_back(values[i]);
    }
    for (size_t i = 0; i < buttons.size(); i++) {
            submerge_msg.buttons.push_back(buttons[i]);
    }

    sensor_msgs::msg::Joy forward_msg;

    values = std::vector<double>(9, 0);
    buttons = std::vector<int>(10, 0);
    
    values[2] = -0.7;
    values[0] = 1.0;
    buttons[9] = 1;
    for (size_t i = 0; i < values.size(); i++) {
            forward_msg.axes.push_back(values[i]);
    }
    for (size_t i = 0; i < buttons.size(); i++) {
            forward_msg.buttons.push_back(buttons[i]);
    }

    sensor_msgs::msg::Joy yaw_roll_msg;

    values = std::vector<double>(9, 0);
    buttons = std::vector<int>(10, 0);

    values[5] = -1.0;
    values[0] = 1.0;
    buttons[9] = 1;
    for (size_t i = 0; i < values.size(); i++) {
            yaw_roll_msg.axes.push_back(values[i]);
    }
    for (size_t i = 0; i < buttons.size(); i++) {
            yaw_roll_msg.buttons.push_back(buttons[i]);
    }

    factory.registerNodeType<DriveForDuration>("Submerge", manager, submerge_msg, 5);
    factory.registerNodeType<DriveForDuration>("GoToGate", manager, forward_msg, 15);
    factory.registerNodeType<DriveForDuration>("YawRoll", manager, yaw_roll_msg, 15);
    factory.registerNodeType<DriveForDuration>("GoPastGate", manager, forward_msg, 5);

    factory.registerNodeType<TurnTowardsBuoy>("TurnTowardsBuoy", manager);
    factory.registerNodeType<DriveAtDetected>("DriveAtBuoy", manager, YOLO_BUOY);
    factory.registerNodeType<DriveForDuration>("FireTorpedoes", manager, forward_msg, 1);
    factory.registerNodeType<DriveForDuration>("DriveIntoBuoy", manager, forward_msg, 5);


    manager->initialize_tree(factory);

    rclcpp::spin(manager);

    return 0;
}
