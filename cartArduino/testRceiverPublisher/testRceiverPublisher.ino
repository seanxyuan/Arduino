

#include <ros.h>
//#include <std_msgs/Empty.h>
#include <ros_essentials_cpp/Master.h>
#include <ros_essentials_cpp/Arduino_O.h>


int i = 0;
ros::NodeHandle nh;

ros_essentials_cpp::Arduino_O arduino_o;
ros::Publisher arduino_output("Arduino_Output_topic", &arduino_o);

void messageCartArduino( const ros_essentials_cpp::Master &cartArduino_msg){
  digitalWrite(10,cartArduino_msg.deliverySwitch);
  digitalWrite(11,cartArduino_msg.hopperSwitch);
  digitalWrite(12,cartArduino_msg.doserSwitch);
  digitalWrite(13,cartArduino_msg.wettingSwitch);
  nh.loginfo("1");
  delay(1000);
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
  nh.advertise(arduino_output);
  //Serial.begin(9600);
}

void loop()
{
  arduino_o.relay1Error = random(2);
  arduino_o.relay2Error = random(2);
  arduino_o.relay3Error = random(2);
  arduino_o.relay4Error = random(2);
  arduino_output.publish( &arduino_o );
  digitalWrite(10,1);
  digitalWrite(11,1);
  digitalWrite(12,1);
  digitalWrite(13,1);
  //Serial.println(random(2));
  delay(1000);
  nh.spinOnce();
  
}
