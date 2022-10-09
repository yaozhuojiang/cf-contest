#include "ros/ros.h"
#include "geometry_msgs/Twists.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "control");
    ros::NodeHandle nh;
    ros::publisher pub = nh.advertise<geometry_msgs::Twist>("Turtle1/cmd_vel", 1000);
    geometry_msgs::Twist msg;
    msg.linear.x = 1.0;
    msg.linear.y = 0;
    msg.linear.z = 0;
    msg.angular.x = 0;
    msg.angular.y = 0;
    msg.angular.z = 1.0;
    ros::Rate r(10);
    while (ros::ok())
    {
        pub.publish(msg);
    }
    return 0;
}