#include <TimerOne.h>  //Load interrupt library
String LEDStatus = "OFF"; //Declare a variable showing LED statu
int REDLED=13;
int YellowLED=10;

void setup() {
  // put your setup code here, to run once:
pinMode(YellowLED,OUTPUT);
pinMode(REDLED,OUTPUT);
Timer1.initialize(1000); //Defines the time of the interrupt inside the bracket in microseconds
Timer1.attachInterrupt(BlinkYellow); //Define the function the program does in the interrupt
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(REDLED,HIGH);
delay(250);
digitalWrite(REDLED,LOW);
delay(250);
}
void BlinkYellow()
{
if (LEDStatus =="ON") {
  digitalWrite(YellowLED,LOW);
  LEDStatus = "OFF";
  return; //why do we need return here?
}
if (LEDStatus =="OFF") {
  digitalWrite(YellowLED,HIGH);
  LEDStatus = "ON";
  return;
}
  
}

