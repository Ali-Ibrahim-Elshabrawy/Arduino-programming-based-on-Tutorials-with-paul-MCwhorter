int potPin = A0; //Assigning potrpin to A0
int readValue;   //Declaring our readValue Variable
float Voltage; //Declare our Voltage as float so we can make calculations on it
void setup() {
  // put your setup code here, to run once:
pinMode(potPin,INPUT); // Declare potPin an input
Serial.begin(9600);    // Start your Serial Port
}

void loop() {
  // put your main code here, to run repeatedly:
readValue = analogRead(potPin); // Read 'potPin' and put value in readValue
Voltage = (5./1023.)*readValue; // convert readValue to Voltage we add . after 5 and 1023 so arduino read it as a float number
Serial.println(Voltage);      //P*rint results to serial monitor
delay(500);                     //delay 250 milliseconds
}
