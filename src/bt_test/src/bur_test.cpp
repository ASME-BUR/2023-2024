#include "behaviortree_cpp/bt_factory.h"

#include "bur_nodes.h"
#include "rclcpp/rclcpp.hpp"
using namespace BurNodes;

int main(int argc, char * argv[])
{
    BehaviorTreeFactory factory;

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

    factory.registerBehaviorTreeFromFile("./bur_tree.xml");
    auto tree = factory.createTree("MainTree");
    
    while(true) {
        tree.tickWhileRunning();
    }

    rclcpp::spin(location_tracker);
    rclcpp::shutdown(); 

    return 0;
}
