int LEDpin = 13;
void setup() {
  // put your setup code here, to run once:
pinMode(LEDpin,OUTPUT); //Defines pin 13 as output
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite (LEDpin,HIGH); // Turns LED ON
digitalWrite (LEDpin,LOW); //Turns LED off
}
