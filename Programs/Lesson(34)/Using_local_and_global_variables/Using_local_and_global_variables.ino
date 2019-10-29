int x=7;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
delay(100);
Serial.print("You are in the void setup,and x=");
Serial.println(x);

}

void loop() {
  // put your main code here, to run repeatedly :
Serial.print("You are in the void loop,and x=");
Serial.println(x);
hello();
delay(2000);

}
void hello(){
  Serial.print("The hello Function has x=");
  Serial.println(x);
  x=x+1;
}

