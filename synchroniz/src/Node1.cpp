#include "ros/ros.h"
#include <sstream>
#include <bits/stdc++.h>
#include <synchroniz/custommsg.h>

int main (int argc,char** argv) {
    ros::init(argc, argv, "Node1");
    ros::NodeHandle n;
    ROS_INFO_STREAM("Node 1 has started running");
    ros::Publisher pub=n.advertise<synchroniz::custommsg>("talker",5);
    ros::Rate loop_rate(5);



    while(ros::ok()){
        synchroniz::custommsg msg;
        msg.header.stamp=ros::Time::now();
        msg.header.frame_id="/myworld";
        std::stringstream ss;
        ss<<"Synchronous ";
        msg.st=ss.str();
        pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();

    }
    return 0;
}