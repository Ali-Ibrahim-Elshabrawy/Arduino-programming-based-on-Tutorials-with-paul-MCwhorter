//the code isn't complete look on it completely on the Video
void loop(){

digitalWrite(RedLED,HIGH);
delay(1000);
digitalWrite(RedLED,LOW);
delay(1000);


 
if (flag==1){
 
  Timer1.stop();
  NMEA.trim();
  Serial.println(NMEA);
  NMEA="";
  flag=0;
  Timer1.restart();
}
}



void readGPS(){
 if (GPSSerial.available()>0){
  c=GPSSerial.read();
  NMEA.concat(c);
 }
  if(c=='\r'){
   flag=1;
 }
}
