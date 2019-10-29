int LEDpin = 13;
int Waittime = 1000;
void setup() {
  // put your setup code here, to run once:
pinMode(LEDpin,OUTPUT); //Defines pin 13 as output
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite (LEDpin,HIGH); // Turns LED ON
delay(Waittime); //Delay in ms
digitalWrite (LEDpin,LOW); //Turns LED off
delay(Waittime); //Delay in ms
}
