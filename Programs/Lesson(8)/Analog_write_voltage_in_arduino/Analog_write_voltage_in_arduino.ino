int redLED = 9; //Declaring redLED as an int gloabal variable and set it to 9
int yellowLED = 10; //Declaring yellowLED as an int gloabal variable and set it to 6
int redOnTime = 500; //red led on time
int redOffTime = 500; // red led off time
int yellowOnTime = 400; //yellow led on time
int yellowOffTime = 500; //yellow led off time
int numRedBlinking=5;    //Number of times to blink red
int numYellowBlinking=5;  //Number of times to blink yellow
String redMessage = "The Red Led is on Blink#: ";//Declare a string variable
String yellowMessage= "The yellow Led is on Blink#: "; //Declare a string variable
int  writeValueRed ;
int writeValueYellow;
void setup() {
  // put your setup code here, to run once:
String wm1 = "Welcome to "; //Declaring a Local string variable and assign a Value
String wm2 ="My Program";  //Declaring a Local string variable and assign a Value
String wm3;                //Declaring a Local string variable without assigning a Value
wm3=wm1+wm2;              //Concatanating wm1 and wm2 into wm3
Serial.println(wm3);
Serial.begin(9600);
pinMode(redLED,OUTPUT);
pinMode(yellowLED,OUTPUT);
 Serial.println("what is the Value you want to write on RED LED (0-255)? ");//Prompt user for input
 while(Serial.available()==0){} //Wait untill user puts the input
 writeValueRed = Serial.parseInt(); //Reading the input of the user
 Serial.println("what is the Value you want to write on YELLOW LED (0-255)? "); //Prompt user for input
 while(Serial.available()==0){} //Wait untill user puts the input
 writeValueYellow = Serial.parseInt(); //Reading the input of the user
}

void loop() {
  // put your main code here, to run repeatedly:
int j =1;
while(j<=numRedBlinking){
 Serial.print(redMessage);
  Serial.println(j);
  analogWrite(redLED,writeValueRed);//Aplly analog voltage to pin
  delay(redOnTime);         //Wait
  analogWrite(redLED,0); //Aplly analog voltage to pin
  delay(redOffTime);        //Wait
  j=j+1;
  }

 Serial.println(" ");
  for (int j=1 ; j<=numYellowBlinking ; j=j+1) {
   Serial.print(yellowMessage);
  Serial.println(j);
  analogWrite(yellowLED,writeValueYellow);//Aplly analog voltage to pin
  delay(yellowOnTime);
  analogWrite(yellowLED,0);//Aplly analog voltage to pin
  delay(yellowOffTime);
  }
  Serial.println(" ");
}
