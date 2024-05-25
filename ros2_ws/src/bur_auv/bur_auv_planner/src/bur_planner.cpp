#include "behaviortree_cpp_v3/bt_factory.h"

#include "bur_planner.h"
#include "rclcpp/rclcpp.hpp"

using namespace BurNodes;

int main(int argc, char * argv[])
{
    BehaviorTreeFactory factory;

    factory.registerNodeType<nav2_behavior_tree::PipelineSequence>("PipelineSequence");

    factory.registerSimpleCondition("FireTorpedo", [&](TreeNode&) { return FireTorpedo(); });

    factory.registerSimpleCondition("GateVisited", [&](TreeNode&) { return GateVisited(); });
    factory.registerSimpleCondition("BuoyVisited", [&](TreeNode&) { return BuoyVisited(); });
    factory.registerSimpleCondition("BinVisited", [&](TreeNode&) { return BinVisited(); });
    factory.registerSimpleCondition("TorpedoVisited", [&](TreeNode&) { return TorpedoVisited(); });
    factory.registerSimpleCondition("SamplesVisited", [&](TreeNode&) { return SamplesVisited(); });

    rclcpp::init(argc, argv);

    std::shared_ptr<LocationTracker> location_tracker;

    factory.registerSimpleAction("VisitGate", [&](TreeNode&){ return location_tracker->visit_gate(); } );
    factory.registerSimpleAction("VisitBuoy", [&](TreeNode&){ return location_tracker->visit_buoy(); } );
    factory.registerSimpleAction("VisitBin", [&](TreeNode&){ return location_tracker->visit_bin(); } );
    factory.registerSimpleAction("VisitTorpedo", [&](TreeNode&){ return location_tracker->visit_torpedo(); } );
    factory.registerSimpleAction("VisitSamples", [&](TreeNode&){ return location_tracker->visit_samples(); } );

    factory.registerBehaviorTreeFromFile(argv[1]);
    auto tree = factory.createTree("MainTree");
    
    while(true) {
        tree.tickRootWhileRunning();
    }

    rclcpp::spin(location_tracker);
    rclcpp::shutdown(); 

    return 0;
}
