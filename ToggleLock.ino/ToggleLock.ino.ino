/*
  Opens door lock when ROS topic /toggle_lock (std_msgs::Bool) is True, closes door when it's False
*/

#include <ros.h>
#include <std_msgs/Bool.h>
#define BAUD 9600

ros::NodeHandle nh;

void messageCb( const std_msgs::Bool& toggle_msg) {
  if (toggle_msg.data){
    digitalWrite(10, HIGH);   // Open the door lock when the signal topic is True
    digitalWrite(LED_BUILTIN, HIGH);  // For debug
  }
  else {
    digitalWrite(10, LOW);    // Close the door lock when the signal topic is False
    digitalWrite(LED_BUILTIN, LOW);  //For debug
  }
}

ros::Subscriber<std_msgs::Bool> sub("toggle_lock", &messageCb);


void setup() {
  // Initialize digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(10, OUTPUT);
  digitalWrite(10, LOW);  // Door closed at the beginning

  // Set baud rate, initialize node, and subscribe topic
  nh.getHardware()->setBaud(BAUD);
  nh.initNode();
  nh.subscribe(sub);
}


void loop() {
  nh.spinOnce();
  delay(1);
}
