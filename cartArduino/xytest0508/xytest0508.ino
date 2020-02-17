#include <ros.h>
#include <std_msgs/String.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include "Adafruit_HTU21DF.h"

//Set up RoboClaw
#include <SoftwareSerial.h>
#include "RoboClaw.h"
SoftwareSerial serial(10,11);  
RoboClaw roboclaw(&serial,10000);
#define address_pump 0x80
#define address_doser 0x81
#define address_breaker_fan 0x82
#define address_agitator 0x83
long time = 0;
int D1M1 = 0;
int D1M2 = 0;
int D2M1 = 0;
int D2M2 = 0;
int D3M1 = 0;
int D3M2 = 0;
int D4M1 = 0;
int D4M2 = 0;

//Set up ROS
ros::NodeHandle  nh;
std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);
char hello[13] = "hello world!";

//Set up Light Sensor
int light = A0; // Read the light
int lightValue = 0; 

//Set up IMU
uint16_t BNO055_SAMPLERATE_DELAY_MS = 1000;
Adafruit_BNO055 bno = Adafruit_BNO055(55);

//Set up temperature and humidity sensor
Adafruit_HTU21DF htu = Adafruit_HTU21DF();

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

void setup()
{

  //Open roboclaw serial ports
  roboclaw.begin(38400);
  
  nh.initNode();
  nh.advertise(chatter);

  Serial.begin(115200);
  
  Serial.println("Connecting to Sensors");
  /* Initialise the sensor */
  if (!bno.begin())
  {
    Serial.println("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");    //There was a problem detecting the BNO055 ... check your connections
    while (1);
  }

  if (!htu.begin()) {
    Serial.println("Couldn't find sensor!");  //There was a problem detecting the temperature and humidity
    while (1);
  }
  
}

void loop()
{
  
  float temp = htu.readTemperature();
  float rel_hum = htu.readHumidity();
    
  str_msg.data = hello;
  chatter.publish( &str_msg );
  nh.spinOnce();
  
  lightValue = analogRead(light);

  //could add VECTOR_ACCELEROMETER, VECTOR_MAGNETOMETER,VECTOR_GRAVITY...
  sensors_event_t linearAccelData;
  bno.getEvent(&linearAccelData, Adafruit_BNO055::VECTOR_LINEARACCEL);
  printEvent(&linearAccelData);

  //Read motor driver data from somewhere
  
  
  //Sending out signal every 0.2 second
  if (millis()/200 > time){
    time = millis()/200;
    Serial.print("Time: ");Serial.println(time);

    Serial.print("Temp: "); Serial.print(temp); Serial.print(" C. ");
    Serial.print("Humidity: "); Serial.print(rel_hum); Serial.println(" \%");

    Serial.print("light strenght is: ");Serial.println(lightValue);

    Serial.print("Maximum Acceleration= ");
    Serial.println(maxAccel);
    maxAccel = -100000;

    roboclaw.ForwardM1(address_pump,D1M1); 
    roboclaw.ForwardM2(address_pump,D1M2); 
    roboclaw.ForwardM1(address_doser,D2M1); 
    roboclaw.ForwardM2(address_doser,D2M2);
    roboclaw.ForwardM1(address_breaker_fan,D3M1); 
    roboclaw.ForwardM2(address_breaker_fan,D3M2);
    roboclaw.ForwardM1(address_agitator,D4M1); 
    roboclaw.ForwardM2(address_agitator,D4M2);
    
  }
  
  

  
}
