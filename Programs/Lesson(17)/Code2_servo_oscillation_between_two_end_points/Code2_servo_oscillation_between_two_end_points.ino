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
for (pos=15 ; pos<=170 ; pos=pos+1) {
  myPointer.write(pos); //send servo to pos
  delay(servoDelay);    //pause a moment
}
for (pos=170 ; pos>=15 ; pos=pos-1) {
  myPointer.write(pos); //send servo to pos
  delay(servoDelay);    //pause a moment
}
}
