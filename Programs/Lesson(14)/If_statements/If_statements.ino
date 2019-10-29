int redPin = 11; //Declare red pin and set it to 11
int greenPin=10; //Declare green pin and set it to 10
int bluePin = 6; //Declare blue pin and set it to 6
int brightness =255; //Declare brightness and set it to 255
String colorChoise;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); //turn on serial port
pinMode(redPin,OUTPUT); //set red pin to be an output
pinMode(greenPin,OUTPUT); //set red pin to be an output
pinMode(bluePin,OUTPUT); //set red pin to be an output
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Please input your color choise (red, green or blue) ");//prompt user for input
  while(Serial.available()==0){};      //wait for user input
  colorChoise = Serial.readString();   //read string from serial port
  if(colorChoise == "red") {
    analogWrite(redPin,brightness); //Turn red on
    analogWrite(bluePin,0);         //Turn blue off
    analogWrite(greenPin,0);        //Turn green off
  }
 if(colorChoise == "blue") {
    analogWrite(redPin,0);           //Turn red off
    analogWrite(bluePin,brightness); //Turn blue on
    analogWrite(greenPin,0);         //Turn green off
  }
 if(colorChoise == "green") {
    analogWrite(redPin,0);           //Turn red off
    analogWrite(bluePin,0);          //Turn blue off
    analogWrite(greenPin,brightness);//Turn green on
  }
if ( colorChoise != "red" && != "blue" && != "green"){
Serial.println("");
Serial.println("You have not entered a valid color please enter red, green or blue" );
Serial.println("");
}

}
