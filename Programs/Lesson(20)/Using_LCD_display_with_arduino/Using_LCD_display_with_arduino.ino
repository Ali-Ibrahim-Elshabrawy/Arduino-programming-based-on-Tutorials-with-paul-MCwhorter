#include <LiquidCrystal.h>  //Load the Liquid Crystal Library

LiquidCrystal myLCD (7, 6, 5, 4, 3, 2); //Creating the LiquidCrystal object named LCD
int myCounter =0; //Declare your variable myCounter

void setup() {
  // put your setup code here, to run once:
myLCD.begin(16,2); //Tell Arduino our LCD has 16 columns and 2 rows
myLCD.setCursor(0,0); //Set LCD cursor to upper left corner
myLCD.print("Your Time:  "); //Print our first line
}

void loop() {
for (myCounter=1 ; myCounter<=10 ; myCounter = myCounter=myCounter+1){
  myLCD.setCursor(0,1); //Set Cursor to first column second raw
  myLCD.print("            "); //clear the line
  myLCD.setCursor(0,1); //Set cursor to first column (column 0) and second row (row 1)
  myLCD.print(myCounter); //print your counter
  myLCD.print(" Seconds"); //print units
  delay(1000); //delay by 1000ms which is one second
}
for (myCounter=10 ; myCounter>=1 ; myCounter = myCounter=myCounter-1){
  myLCD.setCursor(0,1); //Set Cursor to first column second raw
  myLCD.print("            "); //clear the line
  myLCD.setCursor(0,1); //Set cursor to first column (column 0) and second row (row 1)
  myLCD.print(myCounter); //print your counter
  myLCD.print(" Seconds"); //print units
  delay(1000); //delay by 1000ms which is one second
}
}
