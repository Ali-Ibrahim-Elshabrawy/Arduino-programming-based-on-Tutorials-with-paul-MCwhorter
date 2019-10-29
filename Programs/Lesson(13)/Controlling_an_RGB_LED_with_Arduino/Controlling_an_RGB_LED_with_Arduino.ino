int redPin=11;    //set red LED pin to 11
int greenPin=10;  //set green LED pin to 10
int bluePin=6;    //set Blue Led pin to 6
int rbrightness;//set brightness to 75 
int gbrightness;//set brightness to 75 
int bbrightness;//set brightness to 75 
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(redPin,OUTPUT); //set redPin to be an output
pinMode(greenPin,OUTPUT); //set redPin to be an output
pinMode(bluePin,OUTPUT); //set redPin to be an output
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Write strength of red color(0-255)");
  while(Serial.available()==0){};
  rbrightness = 255- Serial.parseInt();
    Serial.println("Write strength of green color(0-255)");
  while(Serial.available()==0){};
  gbrightness = 255- Serial.parseInt();
    Serial.println("Write strength of blue color(0-255)");
  while(Serial.available()==0){}
  bbrightness = 255- Serial.parseInt();
analogWrite(redPin,rbrightness); //turn off red pin
analogWrite(greenPin,gbrightness); //turn off green pin
analogWrite(bluePin,bbrightness); //Write 75 to blue pin
Serial.println("");

}
