#include <ros.h>
#include <std_msgs/String.h>

void subscriber_callback(const std_msgs::String &received_ros_str) {
    Serial.println(received_ros_str.data);
}

const char * topic_name = "arduino_topic";
ros::NodeHandle nh;
ros::Subscriber<std_msgs::String> my_subscriber(topic_name, &subscriber_callback);

void setup() {
  nh.getHardware()->setBaud(57600);
  nh.initNode();
  nh.subscribe(my_subscriber);
}

void loop() {
  nh.spinOnce();
}