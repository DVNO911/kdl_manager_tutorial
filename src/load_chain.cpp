#include <ros/ros.h>
#include <generic_control_toolbox/kdl_manager.hpp>

int main (int argc, char ** argv)
{
	ros::init(argc, argv, "load_chain");
	generic_control_toolbox::KDLManager manager("yumi_base_link");

	manager.initializeArm("yumi_link_7_r");
	KDL::Frame pose;
	sensor_msgs::JointState state;

	state = *ros::topic::waitForMessage<sensor_msgs::JointState>("/joint_states");

	manager.getEefPose("yumi_link_7_r", state, pose);
	ROS_INFO_STREAM("The right hand base position is " << pose.p.x() << ", " << pose.p.y() << ", " << pose.p.z());
	manager.setGrippingPoint("yumi_link_7_r", "gripper_r_base");
	manager.getGrippingPoint("yumi_link_7_r", state, pose);
	ROS_INFO_STREAM("The right hand gripping point is" << pose.p.x() << ", " << pose.p.y() << ", " << pose.p.z());
}
