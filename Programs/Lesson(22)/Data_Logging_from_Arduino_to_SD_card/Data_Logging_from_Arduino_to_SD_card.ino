#include <SD.h>  //Load the SD Library
#include <SPI.h> //Load the SPI Library

//SD card Variables
int chipSelect=53;  //Set chipSelect = 4
File mySensorData; //Variable for working with our file object
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

pinMode(53,OUTPUT); //Reserve pin 10 as an output, don't use it for other parts of circuit
SD.begin(chipSelect); //Initialize the SD card with chipSelect connected to pin 4
}

void loop() {
 mySensorData = SD.open("PTData.txt" , FILE_WRITE); //Open PTData.txt on the SD card as a fike to write to
 if (mySensorData)  //Check that File is open
 {
  mySensorData.println("My name is Ali Shabrawy");
  mySensorData.close(); //Close the file  
  Serial.println("it really works");
 }
 delay(1000); 
}
