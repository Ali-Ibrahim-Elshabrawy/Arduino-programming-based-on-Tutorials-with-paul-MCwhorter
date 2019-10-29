#include <Servo.h>

int trigPin =5; //Declare trig pin to be 5
int echoPin =6; //Declare echo pin to be 6
int speedOfSound = 343; //Declare speed of sound to be 343 m/s
float pingTime ; //Declare this value to save time
float distance;  //Declare variable to save distance to it
int pos; //Declare this value to save the pos of the servo motor
int servoControlPin=9;

Servo myservo;  //Declare this servo object to save the variable my servo


void setup() {
Serial.begin(9600);
pinMode(trigPin,OUTPUT);  //make trig pin to be an output
pinMode(echoPin,INPUT);   //make echopin to be an input
pinMode(servoControlPin,OUTPUT);
myservo.attach(servoControlPin); //Make my servo to be attached to pin servoControlPin

}

void loop() {
digitalWrite(trigPin,LOW); // Stops trigger to settle any sound waves
delayMicroseconds(5000);   // Wait for 50ms (minimum time between any triggers)
digitalWrite(trigPin,HIGH); //Turn trigger on
delayMicroseconds(10);      //Wait 10 microsecond(minimum time trigger can work with)
digitalWrite(trigPin,LOW);  //Turn trigger off
pingTime= pulseIn(echoPin,HIGH); //Read pulsewidth in microseconds
distance = (speedOfSound*pingTime)/20000.; //calculate distance value
pos = (155./6.) * (distance) - 36.67;  //Calculate pos of servo in degrees
Serial.println(pingTime);
Serial.print ("The measured distance is: ");
Serial.println(distance);
Serial.print("The Servo angle is: ");
Serial.println(pos);

if ( pos<15 || pos >170) {
  Serial.println ("Distance is out of Range");
 
}
else {
myservo.write(pos);
Serial.print ("The measured distance is: ");
Serial.println(distance);
Serial.print("The Servo angle is: ");
Serial.println(pos);
}
delay(1000);
}

