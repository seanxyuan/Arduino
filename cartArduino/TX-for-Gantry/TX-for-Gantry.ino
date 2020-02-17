#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
//this code is for the gantry module

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";
int limitPin = 9;

void setup() {
  pinMode(limitPin, INPUT);
  Serial.begin(9600);
  
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX); //should be default but not sure
  radio.stopListening();
}
void loop() {

  int limitSwitch = digitalRead(limitPin);
  int data = 2000*limitSwitch;
  radio.write(&data, sizeof(data));
  delay(5);
  
}
