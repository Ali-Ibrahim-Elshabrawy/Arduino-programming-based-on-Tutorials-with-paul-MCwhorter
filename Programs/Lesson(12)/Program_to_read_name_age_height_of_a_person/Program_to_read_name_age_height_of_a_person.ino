String myName;  //Declare a string variable to hold name
int age ;       //Declare int variable to hold your age
float height;   //Declare float variable to hold your height

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);  //Turning on serial port at 9600 baud rate
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("Please enter your name: "); //prompt the user input
while(Serial.available()==0){}  //wait until user input
myName = Serial.readString();  //Read user input and save it to myName

Serial.println("How old are you?"); //prompt the user input
while(Serial.available()==0){}  //wait until user input
age = Serial.parseInt();  //Read user input and save it to age

Serial.println("How tall are you? "); //prompt the user input
while(Serial.available()==0){}  //wait until user input
height = Serial.parseFloat();  //Read user input and save it to height
Serial.print("Hello ");
Serial.print(myName);
Serial.print(", you are ");
Serial.print(age);
Serial.print(" years old");
Serial.print(", you are ");
Serial.print(height);
Serial.print(" cm tall.");
Serial.println(" ");
while(Serial.available()==0){} 
}

