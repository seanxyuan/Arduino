//include ros packages
#include <ros.h>
#include <Wire.h>
#include <Arduino.h>
//subscribe
#include <ros_essentials_cpp/MASTER.h>
#include <ros_essentials_cpp/CART_MCU_O.h>
//publish
#include <ros_essentials_cpp/TOWER_MCU_O.h>

//Setup Roboclaw
#include <SoftwareSerial.h>
#include "RoboClaw.h"
SoftwareSerial serial(10,11);
RoboClaw roboclaw(&serial,10000);
#define address_tower 0x84

//define limitswitch pins
int limitS2Pin = 2;
int limitS3Pin = 7;
bool limitS2 = false;
bool limitS3 = false;

//aquire input data
bool eStop = false;
bool tower2Cart = false;
bool cart2Tower = false;
bool cart2TowerSlow = false;
int RoboClaw5PWM = 0;
bool lS4 = false;
int uS4 = 0;
// 0: do nothing, 1: 2Cart, 2: 2CartSlow, 3: 2Tower, 4:2TowerSlow
int cur = 0;
int pre = 0;


//ultraSonic distance
int ultraSonic2Pin = A1;
int ultraSonic3Pin = A0;
int ultraSonic2 = 0;
int ultraSonic3 = 0;

//initialize ROS
ros::NodeHandle nh;
ros_essentials_cpp::MASTER master;  //sub
ros_essentials_cpp::CART_MCU_O cart_mcu_o;  //sub
ros_essentials_cpp::TOWER_MCU_O tower_mcu_o;  //pub
ros::Publisher tower_MCU_output("Tower_Output_Topic", &tower_mcu_o);


//arduino subscribe message input
void messageMASTER( const ros_essentials_cpp::MASTER &master_msg){
  eStop = master_msg.eStop;
  tower2Cart = master_msg.tower2Cart;
  cart2Tower = master_msg.cart2Tower;
  RoboClaw5PWM = master_msg.RoboClaw5PWM;
}

//arduino subscribe message input
void messageCART_MCU_O( const ros_essentials_cpp::CART_MCU_O &cart_MCU_o_msg){
  lS4 = cart_MCU_o_msg.limitSwitch4;
  uS4 = cart_MCU_o_msg.ultraSonic4;
  
}

void update_tower(){
  ultraSonic2 = analogRead(ultraSonic2Pin);
  ultraSonic3 = map(analogRead(ultraSonic3Pin), 0, 1023, 0, 100);
  limitS2 = digitalRead(limitS2Pin);
  limitS3 = digitalRead(limitS3Pin);
  tower_mcu_o.limitSwitch2 = true;
  tower_mcu_o.limitSwitch3 = limitS3;
  tower_mcu_o.ultraSonic2 = random(0,100);
  tower_mcu_o.ultraSonic3 = ultraSonic3;
}

//initialize subscriber
ros::Subscriber<ros_essentials_cpp::MASTER> master_input("Master_Topic", &messageMASTER);
ros::Subscriber<ros_essentials_cpp::CART_MCU_O> cart_MCU_input("Cart_Output_Topic", &messageCART_MCU_O);

//system setup
void setup()
{
  pinMode(limitS2Pin, INPUT);
  pinMode(limitS3Pin, INPUT);
  nh.subscribe(master_input);
  nh.subscribe(cart_MCU_input);
  nh.initNode();
  nh.advertise(tower_MCU_output);
  roboclaw.begin(38400);

}

void loop()
{
  update_tower();
  tower_MCU_output.publish( &tower_mcu_o );
  nh.spinOnce();

  if (cart2Tower == true && ultraSonic3 <= 90){
    cart2TowerSlow = true;
  }
  if (cart2TowerSlow == true && limitS3 == true){
    cart2TowerSlow = false;
  }
  
 
  if (eStop == true || (cart2Tower == true && tower2Cart ==true)){
    cur = 0;
    roboclaw.ForwardM2(address_tower,0); 
    delay(1);
    roboclaw.BackwardM2(address_tower,0);
  }
  else if (tower2Cart == true && lS4 == false && uS4 > 90){
    cur = 1;
    roboclaw.BackwardM2(address_tower,RoboClaw5PWM);
    delay(1);
    roboclaw.BackwardM2(address_tower,RoboClaw5PWM);
    
  }
  else if (tower2Cart == true && lS4 == false && uS4 <= 90){
    cur = 2; 
    roboclaw.BackwardM2(address_tower,25); 
    delay(1);
    roboclaw.BackwardM2(address_tower,25); 
  }
  else if (cart2Tower == true && limitS3 == false && ultraSonic3 > 90 && cart2TowerSlow == false){
    cur = 3;
    roboclaw.ForwardM2(address_tower,RoboClaw5PWM); 
    delay(1);
    roboclaw.ForwardM2(address_tower,RoboClaw5PWM);
  }
  else if (cart2Tower == true && limitS3 == false && (ultraSonic3 <= 90 || cart2TowerSlow == true)){
    cur = 4;
    roboclaw.ForwardM2(address_tower,35); 
    delay(1);
    roboclaw.ForwardM2(address_tower,35); 
  }
  else{
    cur = 0;
    roboclaw.ForwardM2(address_tower,0); 
    delay(1);
    roboclaw.ForwardM2(address_tower,0); 
  }


  /*if (cur = 0){
    roboclaw.ForwardM2(address_tower,0); 
    delay(1);
    roboclaw.BackwardM2(address_tower,0); 
    pre = 0;
  }
  else if (cur = 1){
    roboclaw.BackwardM2(address_tower,RoboClaw5PWM); 
    delay(1);
    roboclaw.BackwardM2(address_tower,RoboClaw5PWM); 
    pre = 1;
  }
  else if (cur = 2){
    roboclaw.BackwardM2(address_tower,RoboClaw5PWM / 2); 
    delay(1);
    roboclaw.BackwardM2(address_tower,RoboClaw5PWM / 2); 
    pre = 2;
  }
  else if (cur = 3){
    roboclaw.ForwardM2(address_tower,RoboClaw5PWM); 
    delay(1);
    roboclaw.ForwardM2(address_tower,RoboClaw5PWM); 
    pre = 3;
  }
  else if (cur = 4){
    roboclaw.ForwardM2(address_tower,RoboClaw5PWM / 2); 
    delay(1);
    roboclaw.ForwardM2(address_tower,RoboClaw5PWM / 2); 
    pre = 4;
  }
  else{
    roboclaw.ForwardM2(address_tower,0); 
    delay(1);
    roboclaw.BackwardM2(address_tower,0); 
    pre = 0;
  }*/

  delay(50);  //refresh every 50 ms
}
  /*8if (cur != pre){
    if (lS4 == true){
      roboclaw.BackwardM2(address_tower,0);
      pre = lS4;
    }
    else if (lS4 == false){
      roboclaw.ForwardM2(address_tower,0);
      pre = lS4;
    }
    
    
  }*/
  
  /*if (eStop){

    roboclaw.ForwardM2(address_tower,0); 
  }
  else if(tower2Cart == true && cart2Tower == true){

    roboclaw.ForwardM2(address_tower,0); 
  }
  else if(tower2Cart == true ){

    if (ultraSonic4 > 90){
      roboclaw.BackwardM2(address_tower,RoboClaw5PWM); 
    }
    else{
      roboclaw.BackwardM2(address_tower,0); 
    }
    
  }
  else if(cart2Tower == true){

    if (ultraSonic3 > 90){
      roboclaw.ForwardM2(address_tower,RoboClaw5PWM);
    }
    else{

      roboclaw.ForwardM2(address_tower,0);
    }
    
  }
  else{
    roboclaw.ForwardM2(address_tower,0); 
  }*/
