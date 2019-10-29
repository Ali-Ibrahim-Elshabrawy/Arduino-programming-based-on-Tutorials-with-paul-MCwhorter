#include <Servo.h>  //Loading servo library
int pos =0;  //Declare and initialize the pos variable
int servoPin =9;  //Tell arduino that servo is hooked to pin9
int servoDelay = 25;

Servo myPointer; //Create a Servo object called myPointer
void setup() {
 Serial.begin(9600);
 myPointer.attach(servoPin);

}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("Where would you like to position the servo? ");  //Prompt user for input
while (Serial.available()==0){ } //wait for user input
pos = Serial.parseInt(); //Read user input and save it to pos variable

myPointer.writeMicroseconds(pos);  //write pos to servo

}

