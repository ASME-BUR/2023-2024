#include <memory>

#include "geometry_msgs/msg/point.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "rclcpp/rclcpp.hpp"

#include "nav2_behavior_tree/plugins/control/pipeline_sequence.hpp"


using namespace BT;
using std::placeholders::_1;

namespace BurNodes{

bool gateVisited = false;
bool buoyVisited = false;
bool binVisited = false;
bool torpedoVisited = false;
bool samplesVisited = false; 
// Should we have a separate variable to track visiting
// the pinger in the octagon and then descending to the samples?

BT::NodeStatus FireTorpedo()
{
    return BT::NodeStatus::SUCCESS;
}

BT::NodeStatus GateVisited()
{
  std::cout << std::boolalpha << "Gate visited: " << gateVisited << std::endl;
  return gateVisited ? BT::NodeStatus::SUCCESS : BT::NodeStatus::FAILURE;
}

BT::NodeStatus BuoyVisited()
{
  std::cout << std::boolalpha << "Buoy visited: " << buoyVisited << std::endl;
  return buoyVisited ? BT::NodeStatus::SUCCESS : BT::NodeStatus::FAILURE;
}

BT::NodeStatus BinVisited()
{
  std::cout << std::boolalpha << "Bin visited: " << binVisited << std::endl;
  return binVisited ? BT::NodeStatus::SUCCESS : BT::NodeStatus::FAILURE;
}

BT::NodeStatus TorpedoVisited()
{
  std::cout << std::boolalpha << "Torpedo visited: " << torpedoVisited << std::endl;
  return torpedoVisited ? BT::NodeStatus::SUCCESS : BT::NodeStatus::FAILURE;
}

BT::NodeStatus SamplesVisited()
{
  std::cout << std::boolalpha << "Samples visited: " << samplesVisited << std::endl;
  return samplesVisited ? BT::NodeStatus::SUCCESS : BT::NodeStatus::FAILURE;
}

class LocationTracker : public rclcpp::Node
{
    public:
        LocationTracker()
        : Node("location_tracker")
        {
        subscription_ = this->create_subscription<geometry_msgs::msg::PoseStamped>(
        "location", 10, std::bind(&LocationTracker::update_position, this, _1));
        gate_position.x = 1;
        torpedo_position.y = 1;
        }

        geometry_msgs::msg::Point current_position;

        geometry_msgs::msg::Point gate_position;

        geometry_msgs::msg::Point buoy_position;

        geometry_msgs::msg::Point bin_position;

        geometry_msgs::msg::Point torpedo_position;

        geometry_msgs::msg::Point samples_position;

        NodeStatus visit_gate() {
            std::cout<<"visit gate"<<std::endl;
            if(current_position != gate_position) {
                return NodeStatus::SUCCESS;
            }
            return NodeStatus::SUCCESS;
        }

        NodeStatus visit_buoy() {
            std::cout<<"visit buoy"<<std::endl;
            if(current_position != buoy_position) {
                return NodeStatus::SUCCESS;
            }
            return NodeStatus::SUCCESS;
        }

        NodeStatus visit_bin() {
            std::cout<<"visit bin"<<std::endl;
            if(current_position != bin_position) {
                return NodeStatus::SUCCESS;
            }
            return NodeStatus::SUCCESS;
        }

        NodeStatus visit_torpedo() {
            std::cout<<"visit torpedo"<<std::endl;
            if(current_position != torpedo_position) {
                return NodeStatus::SUCCESS;
            }
            return NodeStatus::SUCCESS;
        }

        NodeStatus visit_samples() {
            std::cout<<"visit samples"<<std::endl;
            if(current_position != samples_position) {
                return NodeStatus::SUCCESS;
            }
            return NodeStatus::SUCCESS;
        }

    private:
        rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr subscription_;

        void update_position(const geometry_msgs::msg::PoseStamped::SharedPtr msg) {
            current_position = msg->pose.position;
        }
};
};

