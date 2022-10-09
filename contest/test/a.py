import rospy
from geometry_msgs.msg import Twist

if __name__ == "__main__":
    rospy.init("control_circle_p")
    pub = rospy.Publisher("/turtle/cmd/vel", Twist, queue_size=1000);
    rate = rospy.Rate(10)
    msg = Twist()
    msg.linear.x = 1.0
    msg.linear.y = 0
    msg.linear.z = 0
    msg.angular.x = 0
    msg.angular.y = 0
    msg.angular.z = 0.5
    while not rospy.is_shutdown():
        pub.publish(msg)
        rate.sleep()