//include ros packages
#include <ros.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include "Adafruit_HTU21DF.h"
#include <ros_essentials_cpp/Arduino_I.h>
#include <ros_essentials_cpp/Arduino_O.h>

//define arduino pins
int relay1 = 38; int relay1Error = 39;  int relay2 = 40; int relay2Error = 41;
int relay3 = 42; int relay3Error = 43;  int relay4 = 44; int relay4Error = 45;
int relay5 = 46; int relay5Error = 47;  int relay6 = 48; int relay6Error = 49;
int relay7 = 50; int relay7Error = 51;  int relay8 = 52; int relay8Error = 52;
int sensor1 = 28; int sensor2 = 29; int sensor3 = 30; int sensor4 = 31;
int sensor5 = 32; int sensor6 = 33; int sensor7 = 34; int sensor8 = 35;
int servo1 = 24; int servo2 = 25; int servo3 = 26; int servo4 = 27; 

//define sensor parameters
int temperature = 0;
int humidity = 0;
int concreteTemperature = 0;
int accelXNozzle = 0;
int accelYNozzle = 0;
int accelZNozzle = 0;
int accelXCart = 0;
int accelYCart = 0;
int accelZCart = 0;

//initialize ROS
ros::NodeHandle nh;
ros_essentials_cpp::Arduino_I arduino_i;
ros_essentials_cpp::Arduino_O arduino_o;
ros::Publisher arduino_output("Arduino_Output_topic", &arduino_o);

//Set up IMU
uint16_t BNO055_SAMPLERATE_DELAY_MS = 1000;
Adafruit_BNO055 bno = Adafruit_BNO055(55);

//Set up BNO055 acceleration
double x = -1000000, y = -1000000 , z = -1000000; //dumb values, easy to spot problem
double sum = -1000000; //sum value
double maxAccel = -100000;

void printEvent(sensors_event_t* event) {
  double x = -1000000, y = -1000000 , z = -1000000; //dumb values, easy to spot problem
  double sum = -1000000; //sum value
  if (event->type == SENSOR_TYPE_ACCELEROMETER) {
    x = event->acceleration.x;
    y = event->acceleration.y;
    z = event->acceleration.z;
    sum = sqrt(x*x + y*y + z*z);
  }
  if (sum > maxAccel) maxAccel = sum;
}

//Set up temperature and humidity sensor
Adafruit_HTU21DF htu = Adafruit_HTU21DF();

//arduino subscribe message input
void messageArduino_I( const ros_essentials_cpp::Arduino_I &arduino_i_msg){
  digitalWrite(relay1,arduino_i_msg.relay1);  digitalWrite(relay2,arduino_i_msg.relay2);
  digitalWrite(relay3,arduino_i_msg.relay3);  digitalWrite(relay4,arduino_i_msg.relay4);
  digitalWrite(relay5,arduino_i_msg.relay5);  digitalWrite(relay6,arduino_i_msg.relay6);
  digitalWrite(relay7,arduino_i_msg.relay7);  digitalWrite(relay8,arduino_i_msg.relay8);
  digitalWrite(servo1,arduino_i_msg.RCServo1);  digitalWrite(servo2,arduino_i_msg.RCServo2);
  digitalWrite(servo3,arduino_i_msg.RCServo3);  digitalWrite(servo4,arduino_i_msg.RCServo4);
}

void update_sensor(){
  arduino_o.relay1Error = random(2);  arduino_o.relay2Error = random(2);
  arduino_o.relay3Error = random(2);  arduino_o.relay4Error = random(2);
  arduino_o.relay5Error = random(2);  arduino_o.relay6Error = random(2);
  arduino_o.relay7Error = random(2);  arduino_o.relay8Error = random(2);
  arduino_o.sensor1 = random(2);  arduino_o.sensor2 = random(2);
  arduino_o.sensor3 = random(2);  arduino_o.sensor4 = random(2);
  arduino_o.sensor5 = random(2);  arduino_o.sensor6 = random(2);
  arduino_o.sensor7 = random(2);  arduino_o.sensor8 = random(2);
  arduino_o.temperature = random(100);  arduino_o.humidity = random(100);
  arduino_o.windSpeed = random(100);  arduino_o.concreteTemperature = random(100);
  arduino_o.accelXNozzle = random(1000);  arduino_o.accelYNozzle = random(1000);  arduino_o.accelZNozzle = random(1000);
  arduino_o.accelXCart = random(1000);  arduino_o.accelYCart = random(1000);  arduino_o.accelZCart = random(1000);
}

//initialize subscriber
ros::Subscriber<ros_essentials_cpp::Arduino_I> sub("Arduino_Input_topic", &messageArduino_I );

//system setup
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
  nh.advertise(arduino_output);ionroboclar
  jetson
}

void loop()
{
  float temp = htu.readTemperature();
  float rel_hum = htu.readHumidity();
  //could add VECTOR_ACCELEROMETER, VECTOR_MAGNETOMETER,VECTOR_GRAVITY...
  sensors_event_t linearAccelData;
  bno.getEvent(&linearAccelData, Adafruit_BNO055::VECTOR_LINEARACCEL);
  printEvent(&linearAccelData);

  
  update_sensor();
  arduino_output.publish( &arduino_o );
  delay(50);  //refresh every 50 ms
  nh.spinOnce();
  
}
