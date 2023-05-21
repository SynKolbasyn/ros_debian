#include <ros/ros.h>
#include <std_msgs/String.h>

using ros::init;
using ros::NodeHandle;
using ros::Subscriber;
using ros::spin;

using std_msgs::String;

void callback(const String::ConstPtr& msg) {
    ROS_INFO("%s", msg->data.c_str());
}

int main(int argc, char** argv) {
    ROS_INFO("Settings up listener...");
    init(argc, argv, "listener");
    NodeHandle node_handle;
    Subscriber subscriber = node_handle.subscribe("topic", 1, callback);
    ROS_INFO("Start listening...");
    spin();

    return 0;
}
