float grades [25];  //Declare a float array variable with max limit of 25 Elements
int numGrades;
float sumGrades;
float avg = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:t
 
  Serial.println("How many Grades? ");  //prompt the user to put How many grades there are?
  while (Serial.available() == 0) { }   //Wait for the user input
  numGrades = Serial.parseInt();
  Serial.print("Number of grades Entered are:");
  Serial.println(numGrades);
  for (int i = 0; i < numGrades; i++)
  {
   Serial.println("please Input Your Grade ");
   
   while (Serial.available() == 0){ };
   grades[i] = Serial.parseFloat();
  Serial.print("You Entered :");
  Serial.println(grades[i]);
  }
  for (int i =0; i<numGrades ; i++) {
  sumGrades = sumGrades + grades[i];
  }
  avg = sumGrades/numGrades ;
  Serial.print("Your Average is ");
  Serial.println (avg);
  Serial.println(" ");
  sumGrades = 0;
}
