#include <ros/ros.h>
#include <generic_control_toolbox/kdl_manager.hpp>

sensor_msgs::JointState state;

void stateCb(const sensor_msgs::JointState::ConstPtr &msg)
{
	state = *msg;
}

int main (int argc, char ** argv)
{
	ros::init(argc, argv, "simple_control");
	ros::NodeHandle nh;

	ros::Subscriber state_sub = nh.subscribe("/joint_states", 1, &stateCb);
	ros::Publisher command_pub = nh.advertise<sensor_msgs::JointState>("/joint_command",1)

	generic_control_toolbox::KDLManager manager("torso");
