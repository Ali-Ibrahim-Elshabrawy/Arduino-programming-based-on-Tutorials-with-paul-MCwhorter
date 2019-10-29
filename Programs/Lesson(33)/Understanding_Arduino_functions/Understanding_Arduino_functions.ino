int numGrades;
float grades [15];
int j;
float avg;
float sumGrades;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

Read_numGrades();
Read_Grades(numGrades);
avg_Grades();
print_Grades();
  
}
void Read_numGrades() {
  Serial.println("How Many Grades? ");
  while (Serial.available() == 0) {   }
  numGrades = Serial.parseInt();
}
void Read_Grades (int numGrades) {
  for (j = 0; j < numGrades; j++) {
    Serial.println("Please Input a Grade: ");
    while (Serial.available() == 0) {  }
    grades[j] = Serial.parseFloat();
  }
}
void avg_Grades () {
  for (j = 0; j < numGrades; j++) {
    sumGrades = sumGrades + grades[j];
  }
  avg = sumGrades / numGrades;
  sumGrades = 0;
}
void print_Grades(){
Serial.println("Your Grades Are: ");
  for (j = 0; j < numGrades; j++) {
    Serial.println(grades[j]);
  }
  Serial.println(" ");
  Serial.print("Your Average is: ");
  Serial.println(avg);
  Serial.println(" ");
}


