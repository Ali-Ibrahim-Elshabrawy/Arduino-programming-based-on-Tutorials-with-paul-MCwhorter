int trigPin = 13; //Sensor trig pin is connected to arduino 13
int echoPin = 11; //Sensor echo pin is connected to arduino 11
float pingTimw;   //Time for pint to hit target and return
float speedOfSound;  //We will calculate the speed of sound
float targetDistance = 6; //Our distance

void setup() {
  Serial.begin(9600); //Turn on Serial Port
  pinMode(trigPin, OUTPUT); //set trig pin as an output
  pinMode(echoPin, INPUT);  //set echo pin as an input
}

void loop() {
digitalWrite(trigPin,LOW); // Set Trigger Pin Low
delayMicroseconds(2000); //pause to let signal settle
digitalWrite(trigPin,HIGH); //Take trip pin HIGH
delayMicroseconds(10);  //pause with trigger pin HIGH
digitalWrite(trigPin,LOW); //finish trigger pulse by bringing it low
/* Note that after this line the transmitter starts to work to send 8 sound pulses at 40KHZ
   the sensor doesn't work as you can imagine if you send high to trigger it gives you sound waves
   actually it waits till trigger signal becomes low so it stars sending 8 sound pulses
   at the same time it makes the Echo pin high untill first sound pulses return to the reciever
   at this moment it makes the echo pin low
 */
pingTime = pulseIn(echoPin, HIGH); //Measure ping travel time in microseconds
speedOfSound = (2*targetDistance)/pingTime; //calculate speed of sound in cm/microseconds
speedOfSound = 10000*speedOfSound; //calculate speed of sound in m/seconds
Serial.print("The speed of Sound is: ");
Serial.print(speedOfSound);
Serial.println(" m/s.");
delay(3000);
}
