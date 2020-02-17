

#include <ros.h>
//#include <ros_essentials_cpp/Master.h>
#include <ros_essentials_cpp/Arduino_I.h>
#include <ros_essentials_cpp/Arduino_O.h>


int relay1 = 38; int relay1Error = 39;
int relay2 = 40; int relay2Error = 41;
int relay3 = 42; int relay3Error = 43;
int relay4 = 44; int relay4Error = 45;
int relay5 = 46; int relay5Error = 47;
int relay6 = 48; int relay6Error = 49;
int relay7 = 50; int relay7Error = 51;
int relay8 = 52; int relay8Error = 52;

int sensor1 = 28; int sensor2 = 29; int sensor3 = 30; int sensor4 = 31;
int sensor5 = 32; int sensor6 = 33; int sensor7 = 34; int sensor8 = 35;

int servo1 = 24; int servo2 = 25; int servo3 = 26; int servo4 = 27; 

int temperature = 0;
int humidity = 0;
int concreteTemperature = 0;
int accelXNozzle = 0;
int accelYNozzle = 0;
int accelZNozzle = 0;
int accelXCart = 0;
int accelYCart = 0;
int accelZCart = 0;

ros::NodeHandle nh;
ros_essentials_cpp::Arduino_I arduino_i;
ros_essentials_cpp::Arduino_O arduino_o;
ros::Publisher arduino_output("Arduino_Output_topic", &arduino_o);

void messageArduino_I( const ros_essentials_cpp::Arduino_I &arduino_i_msg){
  digitalWrite(relay1,arduino_i_msg.relay1);  digitalWrite(relay2,arduino_i_msg.relay2);
  digitalWrite(relay3,arduino_i_msg.relay3);  digitalWrite(relay4,arduino_i_msg.relay4);
  digitalWrite(relay5,arduino_i_msg.relay5);  digitalWrite(relay6,arduino_i_msg.relay6);
  digitalWrite(relay7,arduino_i_msg.relay7);  digitalWrite(relay8,arduino_i_msg.relay8);
  digitalWrite(servo1,arduino_i_msg.RCServo1);  digitalWrite(servo2,arduino_i_msg.RCServo2);
  digitalWrite(servo3,arduino_i_msg.RCServo3);  digitalWrite(servo4,arduino_i_msg.RCServo4);
}

ros::Subscriber<ros_essentials_cpp::Arduino_I> sub("Arduino_Input_topic", &messageArduino_I );
//ros::Subscriber<ros_essentials_cpp::Master> sub("Master_topic", &messageCartArduino );

void setup()
{
  pinMode(relay1, OUTPUT);  pinMode(relay2, OUTPUT);  pinMode(relay3, OUTPUT);  pinMode(relay4, OUTPUT);
  pinMode(relay5, OUTPUT);  pinMode(relay6, OUTPUT);  pinMode(relay7, OUTPUT);  pinMode(relay8, OUTPUT);
  pinMode(servo1, OUTPUT);  pinMode(servo2, OUTPUT);  pinMode(servo3, OUTPUT);  pinMode(servo4, OUTPUT);
  pinMode(relay1Error, INPUT);  pinMode(relay2Error, INPUT);  pinMode(relay3Error, INPUT);  pinMode(relay4Error, INPUT);  
  pinMode(relay5Error, INPUT);  pinMode(relay6Error, INPUT);  pinMode(relay7Error, INPUT);  pinMode(relay8Error, INPUT); 
  pinMode(sensor1, INPUT);  pinMode(sensor2, INPUT);  pinMode(sensor3, INPUT);  pinMode(sensor4, INPUT);  
  pinMode(sensor5, INPUT);  pinMode(sensor6, INPUT);  pinMode(sensor7, INPUT);  pinMode(sensor8, INPUT); 
  nh.initNode();
  nh.subscribe(sub);
  nh.advertise(arduino_output);
}

void loop()
{
  arduino_o.relay1Error = digitalRead(relay1Error);  arduino_o.relay2Error = digitalRead(relay2Error);
  arduino_o.relay1Error = digitalRead(relay3Error);  arduino_o.relay2Error = digitalRead(relay4Error);
  arduino_o.relay1Error = digitalRead(relay5Error);  arduino_o.relay2Error = digitalRead(relay6Error);
  arduino_o.relay1Error = digitalRead(relay7Error);  arduino_o.relay2Error = digitalRead(relay8Error);
  arduino_o.relay1Error = digitalRead(sensor1);  arduino_o.relay2Error = digitalRead(sensor2);
  arduino_o.relay1Error = digitalRead(sensor3);  arduino_o.relay2Error = digitalRead(sensor4);
  arduino_o.relay1Error = digitalRead(sensor5);  arduino_o.relay2Error = digitalRead(sensor6);
  arduino_o.relay1Error = digitalRead(sensor7);  arduino_o.relay2Error = digitalRead(sensor8);
  arduino_output.publish( &arduino_o );
  delay(50);
  nh.spinOnce();
  
}
