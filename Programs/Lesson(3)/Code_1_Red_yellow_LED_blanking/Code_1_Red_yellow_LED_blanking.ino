int redLED = 9; //Declaring redLED as an int gloabal variable and set it to 9
int yellowLED = 10; //Declaring yellowLED as an int gloabal variable and set it to 6
int redOnTime = 500; //red led on time
int redOffTime = 500; // red led off time
int yellowOnTime = 400; //yellow led on time
int yellowOffTime = 500; //yellow led off time
int numRedBlink = 5;    //Number of times to blink red
void setup() {
  // put your setup code here, to run once:
pinMode(redLED,OUTPUT);
pinMode(yellowLED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 
 for (int j=1; j<=10; j=j+1) {
  digitalWrite(redLED,HIGH);//Turn red LED on
  delay(redOnTime);         //Wait
  digitalWrite(redLED,LOW); //Turn red LED off
  delay(redOffTime);        //Wait
 }
  digitalWrite(yellowLED,HIGH);
  delay(yellowOnTime);
  digitalWrite(yellowLED,LOW);
  delay(yellowOffTime);
}
