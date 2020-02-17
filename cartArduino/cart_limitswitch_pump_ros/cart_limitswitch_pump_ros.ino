//include ros packages
#include <ros.h>
//#include <Wire.h>
//#include <Arduino.h>
#include <ros_essentials_cpp/ARDUINO_I.h>

#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>
//this code is for the gantry module

//Includes required to use Roboclaw library
#include <SoftwareSerial.h>
#include "RoboClaw.h"

//See limitations of Arduino SoftwareSerial
SoftwareSerial serial(5,6);	
RoboClaw roboclaw(&serial,10000);

#define address0 0x80
#define address1 0x81

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";
int limitPin = 9;


//initialize ROS
bool upDown = false;
bool turn = false;
bool gutter = false;
//long spe = 0;
ros::NodeHandle nh;
//ros_essentials_cpp::ARDUINO_I arduino_i;  //sub

//arduino subscribe message input
void messageARDUINO_I( const ros_essentials_cpp::ARDUINO_I &arduino_i_msg){
  upDown = arduino_i_msg.relay1;
  turn = arduino_i_msg.relay2;
  gutter = arduino_i_msg.relay3;
  //spe = arduino_i_msg.RoboClaw1ASpeed *10000;
}

//initialize subscriber
ros::Subscriber<ros_essentials_cpp::ARDUINO_I> arduino_input("Arduino_Input_Topic", &messageARDUINO_I);

void setup() {
  //Open Serial and roboclaw serial ports
  roboclaw.begin(38400);

  pinMode(limitPin, INPUT);
  Serial.begin(9600);
  
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX); //should be default but not sure
  radio.stopListening();
  
  //Set PID Coefficients
  roboclaw.SetM1VelocityPID(address0,0.20842,0.01476,0,250000);
  roboclaw.SetM2VelocityPID(address0,0.20842,0.01476,0,250000);  
  nh.initNode();
  nh.subscribe(arduino_input);
}

void loop() {
  if (upDown == true){
    roboclaw.SpeedM1(address0,75000);
  }
  else{
    roboclaw.SpeedM1(address0,0);
  }
  if (turn == true){
    roboclaw.SpeedM2(address0,100000);
  }
  else{
    roboclaw.SpeedM2(address0,0);
  }
  if (gutter == true){
    roboclaw.BackwardM1(address1,127);
  }
  else{
    roboclaw.BackwardM1(address1,0);
  }
  int limitSwitch = digitalRead(limitPin);
  int data = 2000*limitSwitch;
  radio.write(&data, sizeof(data));
  //Serial.println(limitSwitch);
  nh.spinOnce();
  delay(5); 
}
