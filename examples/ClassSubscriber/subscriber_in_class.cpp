#include <ros.h>
#include <std_msgs/String.h>

class SubscriberWrapper {
 public:
  SubscriberWrapper(
      ros::NodeHandle &node_handler,
      const char *topic_name)
      : node_handler_(node_handler),
        str_sub_(topic_name, &SubscriberWrapper::SubscriberCallback, this) { // <- can use class method as callback avoiding statics usage
    node_handler_.subscribe(str_sub_);
  }

 private:
  ros::NodeHandle &node_handler_;
  ros::Subscriber<std_msgs::String, SubscriberWrapper> str_sub_;
  void SubscriberCallback(const std_msgs::String &received_ros_str) {
    Serial.println(received_ros_str.data);
  }
};

ros::NodeHandle nh;
SubscriberWrapper my_wrapped_subscriber(nh, "arduino_topic");

void setup() {
  nh.getHardware()->setBaud(57600);
  nh.initNode();
}

void loop() {
  nh.spinOnce();
}
