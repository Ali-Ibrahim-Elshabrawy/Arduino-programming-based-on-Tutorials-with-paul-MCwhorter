int LEDpin = 9;
int onTime = 1000;
int offTime = 500;
void setup() {
  // put your setup code here, to run once:
pinMode (LEDpin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(LEDpin,HIGH);
delay(onTime);
digitalWrite(LEDpin,LOW);
delay(offTime);

}
