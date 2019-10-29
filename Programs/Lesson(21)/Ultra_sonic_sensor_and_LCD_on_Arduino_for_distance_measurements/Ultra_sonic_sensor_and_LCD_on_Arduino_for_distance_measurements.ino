#include <LiquidCrystal.h>

//Ultrasonic sensor related Variables
int trigPin = 11;
int echoPin = 12;
float pingTime;
float distance;
int speedOfSound=343;

//LCD related variables
LiquidCrystal LCD(10,9,5,4,3,2);


void setup() {
//Ultrasonic pin mode setup
pinMode(trigPin,OUTPUT); //set trigPin to be an output
pinMode(echoPin,INPUT);  //set echoPin to be an input
//LCD setup
LCD.begin(16,2); //turn on the LCD and tell arduino how big it is
LCD.setCursor(0,0); //Set LCD cursor to upper left corner
LCD.print("The target distance is: "); //print first raw
}

void loop() {
  //Getting Distance from ultrasonic sensor
  digitalWrite(trigPin,LOW); //Wait untill the wave setteles
  delayMicroseconds(50000);
  digitalWrite(trigPin,HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  
  pingTime = pulseIn(echoPin,HIGH);  //read ping time of the wave in microseconds
  pingTime = pingTime/1000000.; //read ping time in s
  
  distance = pingTime*speedOfSound ; //distance in m
  distance = distance /2.; //divide by 2 because ping time is taken for double the distance
  distance = distance * 100; //convert m to cm
  
  //Writing distance on LCD
  LCD.setCursor(0,1);  //Set cursor to first column second row
  LCD.print("                "); //clears row two
  
  LCD.setCursor(0,1);  //Set cursor to first column second row
  LCD.print(distance); //print distance to target on LCD
  LCD.print(" cm"); //print units
  delay(250);
  }
