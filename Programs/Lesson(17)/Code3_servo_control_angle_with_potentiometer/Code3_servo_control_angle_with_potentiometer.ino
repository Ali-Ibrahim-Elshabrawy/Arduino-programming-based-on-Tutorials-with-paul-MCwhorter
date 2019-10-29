#include <Servo.h>  //Loading servo library
int pos =0;  //Declare and initialize the pos variable
int servoPin =9;  //Tell arduino that servo is hooked to pin9
int servoDelay = 25;
int potPin = A0;  //Connect potentiometer to pin A0
int readValue;

Servo myPointer; //Create a Servo object called myPointer
void setup() {
 Serial.begin(9600);
 myPointer.attach(servoPin);
 pinMode(potPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
readValue= analogRead(potPin);  //Read potentiometer
pos = (155./1023.)*readValue +15 ; //Calculate position it is calculated based on safe position from 15 to 170 deg only
myPointer.write(pos);  //write pos to servo
}
