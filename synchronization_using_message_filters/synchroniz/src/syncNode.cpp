#include "ros/ros.h"
#include <sstream>
#include <bits/stdc++.h>
#include <synchroniz/custommsg.h>
#include <message_filters/subscriber.h>
#include <message_filters/synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <std_msgs/String.h>

using namespace message_filters;

void callback(const synchroniz::custommsg::ConstPtr& f1, const synchroniz::custommsg::ConstPtr& s1){
    std_msgs::String out_String;
    out_String.data= f1->st+ s1->st;
    ROS_INFO_STREAM(out_String);
}

int main(int argc, char** argv){
    ros::init(argc,argv,"syncNode");
    ros::NodeHandle n;
    message_filters::Subscriber<synchroniz::custommsg> f_sub(n,"talker",1);
    message_filters::Subscriber<synchroniz::custommsg> s_sub(n,"talker2",1);

    typedef sync_policies::ExactTime<synchroniz::custommsg, synchroniz::custommsg> MySyncPolicy;

    Synchronizer<MySyncPolicy> sync(MySyncPolicy(10), f_sub, s_sub);
    sync.registerCallback(boost::bind(&callback, _1,_2));
    ROS_INFO_STREAM("Check..");
    ros::spin();
    return 0;
}

