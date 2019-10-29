int potPin = A0; //Assigning potrpin to A0
int readValue;   //Declaring our readValue Variable
float Voltage; //Declare our Voltage as float so we can make calculations on it
int LEDPIN = 9;
int LEDPIN1 = 10;
int writeValue;
void setup() {
pinMode(potPin,INPUT); // Declare potPin as output
pinMode(LEDPIN,OUTPUT);//Declare LEDPIN as output
Serial.begin(9600);    // Start your Serial Port
}

void loop() {
readValue = analogRead(potPin); // Read 'potPin' and put value in readValue
Voltage = (5./1023.)*readValue; // convert readValue to Voltage we add . after 5 and 1023 so arduino read it as a float number
Serial.println(Voltage);//Print results to serial monitor
writeValue = 51*Voltage;
analogWrite(LEDPIN,writeValue);
analogWrite(LEDPIN1,writeValue);
//delay(500);                     //delay 500 milliseconds
}
