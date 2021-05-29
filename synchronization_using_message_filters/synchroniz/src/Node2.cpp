#include "ros/ros.h"
#include <sstream>
#include <bits/stdc++.h>
#include <synchroniz/custommsg.h>

int main (int argc,char** argv) {
    ros::init(argc, argv, "Node2");
    ros::NodeHandle n;
    ROS_INFO_STREAM("Node 2 has started running");
    ros::Publisher pub=n.advertise<synchroniz::custommsg> ("talker2",5);
    ros::Rate loop_rate(20); // The update rate is changed to 20 while that of the first talker node is 5

    while(ros::ok()){
        synchroniz::custommsg msg;
        msg.header.stamp=ros::Time::now();
        msg.header.frame_id="/robot";
        std::stringstream ss;
        ss<<"completely";
        msg.st=ss.str();
        pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}