## 从官网查阅API的方法

掌握ROS中自定义头文件与源文件的配置

## ROS 中的头文件与源文件

```txt
include_directories(
include
    ${catkin_INCLUDE_DIRS}
)
add_executable(hello src/hello.cpp)
add_dependencies(hello ${${}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(hello ${catkin_LIBRRARIES}
```