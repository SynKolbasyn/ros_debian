#include <ros/ros.h>
#include <std_msgs/String.h>

#include <sstream>

using ros::init;
using ros::NodeHandle;
using ros::Publisher;
using ros::Rate;
using ros::ok;
using ros::spinOnce;

using std_msgs::String;

using std::stringstream;

int main(int argc, char** argv) {
    ROS_INFO("Settings up talker...");
    init(argc, argv, "talker");
    NodeHandle node_handle;
    Publisher publisher = node_handle.advertise<String>("topic", 1);
    Rate loop_rate(2);

    ROS_INFO("Start talking...");
    while(ok()) {
        String msg;
        stringstream ss;
        ss << "Hello world!";
        msg.data = ss.str();
        publisher.publish(msg);
        ROS_INFO("%s", msg.data.c_str());
        spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
