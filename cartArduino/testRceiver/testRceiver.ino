

#include <ros.h>
//#include <std_msgs/Empty.h>
#include <ros_essentials_cpp/Master.h>

int i = 0;
ros::NodeHandle nh;

void messageCartArduino( const ros_essentials_cpp::Master &cartArduino_msg){

  /*test1 = cartArduino_msg.deliverySwitch;
  test2 = cartArduino_msg.hopperSwitch;
  test3 = cartArduino_msg.doserSwitch;
  test4 = cartArduino_msg.wettingSwitch;
  test5 = cartArduino_msg.mixerSwitch;
  test6 = cartArduino_msg.pumpSwitch;
  nh.loginfo(msg.deliverySwitch);*/
  digitalWrite(10,cartArduino_msg.deliverySwitch);
  digitalWrite(11,cartArduino_msg.hopperSwitch);
  digitalWrite(12,cartArduino_msg.doserSwitch);
  digitalWrite(13,cartArduino_msg.wettingSwitch);
  nh.loginfo("1");
  delay(100);
}

//ros::Subscriber<std_msgs::Empty> sub("toggle_led", &messageCb );
ros::Subscriber<ros_essentials_cpp::Master> sub("Master_topic", &messageCartArduino );

void setup()
{
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{
  digitalWrite(10,1);
  digitalWrite(11,1);
  digitalWrite(12,1);
  digitalWrite(13,1);
  delay(100);
  nh.spinOnce();
  
}
