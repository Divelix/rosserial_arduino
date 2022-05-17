#include <ros.h>
#include <std_msgs/String.h>

std_msgs::String ros_str;
ros::NodeHandle nh;
ros::Publisher my_publisher("arduino_topic", &ros_str);

void setup() {
  nh.getHardware()->setBaud(57600);
  nh.initNode();
  nh.advertise(my_publisher);
  ros_str.data = "Hello from arduino!";
}

void loop() {
  if (nh.connected()) {
    my_publisher.publish(&ros_str);
  }
  nh.spinOnce();
  delay(1000);
}