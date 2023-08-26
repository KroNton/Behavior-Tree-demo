#include <iostream>
#include <chrono>
#include "behaviortree_cpp/action_node.h"
#include "behaviortree_cpp/bt_factory.h"

using namespace std::chrono_literals;

/* find ball subtree */


//condition node
BT::NodeStatus BallFound()
{
  std::cout << "Ball not found" << std::endl;
  return BT::NodeStatus::FAILURE;
}

//action node
class FindBall : public BT::SyncActionNode
{
public:
  explicit FindBall(const std::string &name) : BT::SyncActionNode(name, {})
  {
  }

  BT::NodeStatus tick() override
  {
   

    std::this_thread::sleep_for(3s);
     std::cout << "Ball Found"<< std::endl;
    return BT::NodeStatus::SUCCESS;
    
  }
};


/* approach ball subtree */


//condition node
BT::NodeStatus BallApproached()
{
  std::cout << "Ball not Approached" << std::endl;
  return BT::NodeStatus::FAILURE;
}

//action node
class ApproachBall : public BT::SyncActionNode
{
public:
  explicit ApproachBall(const std::string &name) : BT::SyncActionNode(name, {})
  {
  }

  BT::NodeStatus tick() override
  {
   

    std::this_thread::sleep_for(3s);
     std::cout << "Ball Approached"<< std::endl;
    return BT::NodeStatus::SUCCESS;
    
  }
};

/* grasp ball subtree */

//condition node
BT::NodeStatus BallGrasped()
{
  std::cout << "Ball not Grasped" << std::endl;
  return BT::NodeStatus::FAILURE;
}

//action node
class GraspBall : public BT::SyncActionNode
{
public:
  explicit GraspBall(const std::string &name) : BT::SyncActionNode(name, {})
  {
  }

  BT::NodeStatus tick() override
  {
   

    std::this_thread::sleep_for(3s);
     std::cout << "Ball Grasped"<< std::endl;
    return BT::NodeStatus::SUCCESS;
    
  }
};


/* approach bin subtree */

//condition node
BT::NodeStatus BinApproached()
{
  std::cout << "Bin not Approached" << std::endl;
  return BT::NodeStatus::FAILURE;
}

//action node
class ApproachBin : public BT::SyncActionNode
{
public:
  explicit ApproachBin(const std::string &name) : BT::SyncActionNode(name, {})
  {
  }

  BT::NodeStatus tick() override
  {
   

    std::this_thread::sleep_for(3s);
     std::cout << "Bin Approached"<< std::endl;
    return BT::NodeStatus::SUCCESS;
    
  }
};


/* place ball subtree */

//condition node
BT::NodeStatus BallPlaced()
{
  std::cout << "Ball not placed" << std::endl;
  return BT::NodeStatus::FAILURE;
}


//action node
class PlaceBall : public BT::SyncActionNode
{
public:
  explicit PlaceBall(const std::string &name) : BT::SyncActionNode(name, {})
  {
  }

  BT::NodeStatus tick() override
  {
   

    std::this_thread::sleep_for(3s);
     std::cout << "Ball Placed"<< std::endl;
    return BT::NodeStatus::SUCCESS;
    
  }
};

/* Ask for Help! */

//action node
class AskForHelp : public BT::SyncActionNode
{
public:
  explicit AskForHelp(const std::string &name) : BT::SyncActionNode(name, {})
  {
  }

  BT::NodeStatus tick() override
  {
   
    std::cout << "Askin for help"<< std::endl;
    std::this_thread::sleep_for(10s);
    return BT::NodeStatus::SUCCESS;
    
  }
};



int main()
{
  BT::BehaviorTreeFactory factory;


  factory.registerSimpleCondition("BallFound", std::bind(BallFound));
  factory.registerNodeType<FindBall>("FindBall");

  factory.registerSimpleCondition("BallApproached", std::bind(BallApproached));
  factory.registerNodeType<ApproachBall>("ApproachBall");

  factory.registerSimpleCondition("BallGrasped", std::bind(BallGrasped));
  factory.registerNodeType<GraspBall>("GraspBall");  

  factory.registerSimpleCondition("BinApproached", std::bind(BinApproached));
  factory.registerNodeType<ApproachBin>("ApproachBin");
  
  factory.registerSimpleCondition("BallPlaced", std::bind(BallPlaced));
  factory.registerNodeType<PlaceBall>("PlaceBall");

  factory.registerNodeType<AskForHelp>("AskForHelp");

  //Create Tree
  auto tree = factory.createTreeFromFile("./../bt_tree.xml");

  //execute the tree
  tree.tickWhileRunning();

  return 0;
}