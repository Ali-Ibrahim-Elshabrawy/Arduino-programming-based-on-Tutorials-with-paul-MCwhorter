int redLED = 9; //Declaring redLED as an int gloabal variable and set it to 9
int yellowLED = 10; //Declaring yellowLED as an int gloabal variable and set it to 6
int redOnTime = 500; //red led on time
int redOffTime = 500; // red led off time
int yellowOnTime = 400; //yellow led on time
int yellowOffTime = 500; //yellow led off time
int numRedBlinking;    //Number of times to blink red
int numYellowBlinking;  //Number of times to blink yellow
String redMessage = "The Red Led is on Blink#: ";//Declare a string variable
String yellowMessage= "The yellow Led is on Blink#: "; //Declare a string variable
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
 Serial.println("How many times do you want the Red LED to blink? ");//Prompt user for input
 while(Serial.available()==0){} //Wait untill user puts the input
 numRedBlinking = Serial.parseInt(); //Reading the input of the user
 Serial.println("How many times do you want the Yellow LED to blink? "); //Prompt user for input
 while(Serial.available()==0){} //Wait untill user puts the input
 numYellowBlinking = Serial.parseInt(); //Reading the input of the user
}

void loop() {
  // put your main code here, to run repeatedly:
int j =1;
while(j<=numRedBlinking){
 Serial.print(redMessage);
  Serial.println(j);
  digitalWrite(redLED,HIGH);//Turn red LED on
  delay(redOnTime);         //Wait
  digitalWrite(redLED,LOW); //Turn red LED off
  delay(redOffTime);        //Wait
  j=j+1;
  }

 Serial.println(" ");
  for (int j=1 ; j<=numYellowBlinking ; j=j+1) {
   Serial.print(yellowMessage);
  Serial.println(j);
  digitalWrite(yellowLED,HIGH);
  delay(yellowOnTime);
  digitalWrite(yellowLED,LOW);
  delay(yellowOffTime);
  }
  Serial.println(" ");
}
