# continue

## 常用命令

rosnode : 操作节点
rostopic : 操作话题
rosservice : 操作服务
rosmsg : 操作msg消息
rossrv : 操作srv消息
rosparam : 操作参数

### rosnode

rosnode 是用于获取节点信息的命令

```bash
rosnode ping    测试到节点的连接状态
rosnode list    列出活动节点
rosnode info    打印节点信息
rosnode machine    列出指定设备上节点
rosnode kill    杀死某个节点
rosnode cleanup    清除无用节点，启动乌龟节点，然后 ctrl + c 关闭，该节点并没被彻底清除，可以使用 cleanup 清除节点
```

### rostopic

用于显示有关ROS 主题的调试信息，包括发布者，订阅者，发布频率和ROS消息

```bash
rostopic list [-v]                              获取话题详情(比如列出：发布者和订阅者个数...)
rostopic pub /主题名称 消息类型 消息内容          可以直接调用命令向订阅者发布消息
rostopic bw                                     显示主题使用的带宽
rostopic delay                                  显示带有 header 的主题延迟
rostopic echo                                   获取指定话题当前发布的消息
rostopic find                                   根据消息类型查找话题
rostopic hz                                     显示主题的发布频率
rostopic info                                   显示主题相关信息
rostopic list                                   显示所有活动状态下的主题
rostopic pub                                    将数据发布到主题
rostopic type                                   列出话题的消息类型
```

### rosmsg

```bash
rosmsg show             显示消息描述
rosmsg info             显示消息信息
rosmsg list             列出所有消息
rosmsg md5              显示 md5 加密后的消息
rosmsg package 包名     显示某个功能包下的所有消息
rosmsg packages         列出包含消息的功能包
```

### rosservice

```bash
rosservice list     列出所有活动的 service
rosservice args     打印服务参数
rosservice call     使用提供的参数调用服务
rosservice find     按照服务类型查找服务
rosservice info     打印有关服务的信息
rosservice list     列出所有活动的服务
rosservice type     打印服务类型
rosservice uri      打印服务的 ROSRPC uri
```

### rossrv

```bash
rossrv show             显示服务消息详情
rossrv info             显示服务消息相关信息
rossrv list             列出所有服务信息
rossrv md5              显示 md5 加密后的服务消息
rossrv package          显示某个包下所有服务消息
rossrv packages         显示包含服务消息的所有包
```

### rosparam

```bash
rosparam set        设置参数
rosparam get        获取参数
rosparam load       从外部文件(yaml文件)加载参数
rosparam dump       将参数写出到外部文件(yaml文件)
rosparam delete     删除参数
rosparam list       列出所有参数
```

## 坐标轴和坐标系

右手坐标系

通常相对于我们的身体而言：

X -> 朝前
Y -> 朝左
Z -> 朝上

三维坐标轴旋转定义

绕 Z轴 旋转，称之为 航向角，使用yaw表示;
绕 X轴 旋转，称之为 横滚角，使用roll表示;
绕 Y轴 旋转，称之为 俯仰角，使用pitch表示;
我们通常用来表述小车运动的二维平面指的是 X-Y平面，也就是X轴和Y轴张成的平面，在这个平面中，用来描述 小车转弯的角就是绕Z轴的旋转，也就是经常说的航向角。Z轴朝上，所以按照右手法则可以知道小车向 左转为正，右转为负。

## 话题发布_自定义控制节点控制乌龟做圆周运动

1. 了解控制节点与显示节点使用的话题和消息，使用 ros 命令
    
    ```bash
    rqt_graph   # 获取话题
    rostopic type /turtle1/cmd_vel  # 获取消息类型
    rosmsg info geometry_msgs/Twist # 获取消息格式
    ```


```c++
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "control");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
    geometry_msgs::Twist msg;
    msg.linear.x = 1.0;
    msg.linear.y = 0.0;
    msg.linear.z = 0.0;

    msg.angular.x = 0.0;
    msg.angular.y = 0.0;
    msg.angular.z = 2.0;

    ros::Rate r(10);

    while (ros::ok()) {
        pub.publish(msg);
    }

    return 0;
}
```

## 话题订阅_乌龟显示节点发布当前乌龟的位姿

1. 话题获取
    
    ```bash
    rostopic list
    rostipic type /turtle1/pose
    rosmsg info turtlesim/Pose
    ```

```c++
#include "ros/ros.h"
#include "turtlesim/Pose.h"

void doPose(const turtlesim::Pose::ConstPtr &p)
{
    ROS_INFO("%.2f %.2f %.2f %.2f %.2f", p -> x, p -> y, p -> theta, 
    p -> linear_velocity, p -> angular_velocity);
}

int main()
{
    ros::init();
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subsribe<turtlesim::Pose> ("/turtle1/Pose", 1000, doPose);
    ros::spin();
    return 0;
}
```

```python
import rospy
from turtlesim.msg import Pose
do doPose(data):
    rospy.loginfo("%.2f %.2f", data.x, data.y)

if __name__ == "__main__":
    sub = rospy.Subsribe("/turtle1/Pose", Pose, doPose, queue_size = 1000)
    rospy.spin();
```

## 服务调用

1. 获取乌龟生成服务的服务名称以及服务消息类型

    ```bash
    rosservice list
    rosservice type /spawn
    rossrv info turtlesim/Spawn
    ```

```c++
#include "ros/ros.h"
#include "turtlesim/Spawn.h"

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<turtlesim::Spawn>("/spawn");
    ros::service::waitForService("/spawn");
    turtlesim::Spawn spawn;
    spawn.request.x = 1.0;
    spawn.request.y = 1.0;
    spawn.request.theta = 1.57;
    spawn.request.name = "my_turtle";
    bool flag = client.call(spawn);
    if (flag) {
        ROS_INFO("%s", spawn.response.name.c_str());
    } else {
        ROS_INFO("%s", "failed");
    }
    return 0;
}
```

```python
import rospy
from turtlesim.srv import Spawn, SpawnRequest, SpawnResponse

if __name__ == "__main__":
    req = SpawnRequest()
    req.x = 2.0
    req.y = 2.0
    req.theta = -1.57
    req.name = "my_turtle_p"
    try:
        response = client.call(req)
        rospy.loginfo("%s", response.name)
    except expression as identifier:
        rospy.loginfo("调用失败")
```

## 参数服务器的使用

```bash
rosparam list
```

```c++
nh.setParam("background_r", 0);
nh.setParam("background_g", 0);
nh.setParam("background_b", 0);
```

```python
import rospy
if __name__ == "__main__":
    rospy.init_node("hehe")
    rospy.set_param("background_r", 255)
    rospy.set_param("background_g", 255)
    rospy.set_param("background_b", 255)
```

```bash
rosparam set /turtlesim/background_b xxx1
rosparam set /turtlesim/background_g xxx2
rosparam set /turtlesim/background_b xxx3
# ???
rosrun turtlesim turtlesim_node _background_r:=100 _background_g=10
```

```html
<launch>
    <node pkg="turtlesim" type="turtlesim_node" name="set_bg" output="screen">
        <param name="background_b" value="0" type="int" />
    </node>
    <rosparam command="load" file="$(find demo03_test_parameter)/cfg/color.yaml" />

</launch>
```


