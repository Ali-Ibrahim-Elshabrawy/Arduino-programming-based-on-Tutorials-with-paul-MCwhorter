void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int j =1; //Declare that j in an int and set it equal to 1
while (j<=10){
Serial.print("You are on loop number ");
Serial.println(j);
j=j+1;
delay(500);
}
Serial.println(" ");
}
