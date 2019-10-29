#include <Adafruit_GPS.h>     //Install adafruit GPS library
#include <SoftwareSerial.h>   //Load the Software serial Library
SoftwareSerial mySerial(3, 2); //Initialize the Softwarehz Serial port
Adafruit_GPS GPS(&mySerial) ; //Create the GPS Object

String NMEA1; //Variable for first NMEA sentence
String NMEA2; //Variable for second NMEA sentence
char c;       //to read characters coming from the GPS

void setup() {
  Serial.begin(9600); //Turn on serial monitor
  GPS.begin(9600); //Turn on GPS at 9600 baud
  GPS.sendCommand("$PGCMD,33,0*6D"); //Turn on antenna update nuisance data
  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_10HZ); //set update rate to 10hz
  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA); //Request RMC and GGA sentences only
  delay(1000); //Give it time to get all these information
}

void loop() {
  readGPS();
  delay(250);
}

void readGPS() {//Void type means don't expect any data return from it
  clearGPS();
  while (!GPS.newNMEAreceived()) {
    //loop till you have a good NMEA sentence
    c = GPS.read(); //read character by c
  }
  GPS.parse(GPS.lastNMEA()); //parse the last good NMEA sentence
  NMEA1 = GPS.lastNMEA();

  while (!GPS.newNMEAreceived()) {
    //loop till you have a good NMEA sentence
    c = GPS.read(); //read character by c
  }
  GPS.parse(GPS.lastNMEA()); //parse the last good NMEA sentence
  NMEA2 = GPS.lastNMEA();

  Serial.println(NMEA1);
  Serial.println(NMEA2);
  Serial.println("");
}
void clearGPS() { //Clear old and corrupt data from serial port

  while (!GPS.newNMEAreceived()) {
    //loop till you have a good NMEA sentence
    c = GPS.read(); //read character by c
  }
  GPS.parse(GPS.lastNMEA()); //parse the last good NMEA sentence

  while (!GPS.newNMEAreceived()) {
    //loop till you have a good NMEA sentence
    c = GPS.read(); //read character by c
  }
  GPS.parse(GPS.lastNMEA()); //parse the last good NMEA sentence

  while (!GPS.newNMEAreceived()) {
    //loop till you have a good NMEA sentence
    c = GPS.read(); //read character by c
  }
  GPS.parse(GPS.lastNMEA()); //parse the last good NMEA sentence
}

