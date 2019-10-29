int redPin=11; //Declare red pin
int greenPin=10; //Declare green pin
int bluePin=6;  //Declare blue pin

int S2=7; //Color sensor pin S2 to arduino pin7
int S3=8; //Color sensor pin S3 to Arduino pin8
int outPin=4; //Color sensor out to Arduino pin4

unsigned int pulseWidth;

int rColorStrength;
int gColorStrength;
int bColorStrength;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); //turn on serial port

pinMode(redPin,OUTPUT); //Set red pin to be an output
pinMode(greenPin,OUTPUT); //Set green pin to be an output
pinMode(bluePin,OUTPUT); //Set bluw pin to be an output

pinMode(S2,OUTPUT); //Set S2 to be an output
pinMode(S3,OUTPUT); //Set S3 to be an output
pinMode(outPin,INPUT); //Set OUT pin to be an output
}

void loop() {
//Lets start by reading Red Component of the Color
//S2 and S3 should be LOW
digitalWrite(S2,LOW);
digitalWrite(S3,LOW);

pulseWidth = pulseIn(outPin,LOW);

rColorStrength = 256-(pulseWidth/400.);

//reading Blue Component of the Color
//S2 should be LOW and S3 should be HIGH
digitalWrite(S2,LOW);
digitalWrite(S3,HIGH);

pulseWidth = pulseIn(outPin,LOW);

bColorStrength = 256-(pulseWidth/400.);

//reading Green Component of the Color
//S2 and S3 should be HIGH
digitalWrite(S2,HIGH);
digitalWrite(S3,HIGH);

pulseWidth = pulseIn(outPin,LOW);

gColorStrength = 256-(pulseWidth/400.);
//The next section of code is only related to sensor bad Manufacturing
if(rColorStrength>gColorStrength && gColorStrength>bColorStrength){
rColorStrength=255;
gColorStrength=gColorStrength/2;
bColorStrength=0;
}

if(rColorStrength>gColorStrength && bColorStrength>gColorStrength){
rColorStrength=255;
gColorStrength=0;
bColorStrength=bColorStrength/2;
}

if(bColorStrength>gColorStrength && gColorStrength>rColorStrength){
rColorStrength=0;
gColorStrength=gColorStrength/2;
bColorStrength=255;
}

if(bColorStrength>gColorStrength && rColorStrength>gColorStrength){
rColorStrength=rColorStrength/2;
gColorStrength=0;
bColorStrength=255;
}

if(gColorStrength>bColorStrength && bColorStrength>rColorStrength){
rColorStrength=0;
gColorStrength=255;
bColorStrength=bColorStrength/2;
}
if(gColorStrength>bColorStrength && rColorStrength>bColorStrength){
rColorStrength=rColorStrength/2;
gColorStrength=255;
bColorStrength=0;
}
bColorStrength=bColorStrength*0.5 //Scaling
gColorStrength=gColorStrength*0.75 //Scaling
analogWrite(redPin,rColorStrength);

analogWrite(bluePin,bColorStrength);

analogWrite(greenPin,gColorStrength);
Serial.print (rColorStrength);
Serial.print(" ' ");
Serial.print (gColorStrength);
Serial.print(" ' ");
Serial.print (bColorStrength);
Serial.println(" ");
delay(500);
}
