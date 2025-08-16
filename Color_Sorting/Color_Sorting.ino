#include <Servo.h>
#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 6
Servo topServo;
Servo bottomServo;
int frequency = 0;
int color = 0;
void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT); 
  digitalWrite(S0, LOW); //20% scalling
  digitalWrite(S1, HIGH);
  topServo.attach(9);
  bottomServo.attach(10);
  Serial.begin(9600);
}

void loop() {
  topServo.write(89); //set top servo at the first hole to catch the candy
  delay(500);
  
  for(int i = 89; i >= 54; i--) { //move top servo with the candy to the color sensor position
    topServo.write(i);
    delay(2);
  }
  delay(500);
  
  color = readColor(); //read the value from color sensor and put the bottom servo in the right path
  delay(10);  
  switch (color) {
    case 1:
    bottomServo.write(15);
    break;
    case 2:
    bottomServo.write(60);
    break;
    case 3:
    bottomServo.write(110);
    break;
   
    case 0:
    break;
  }
  delay(300);
  
  for(int i = 54; i >= 27; i--) { //move top servo with candy from the color sensor position to the second hole position
    topServo.write(i);
    delay(2);
  } 
  delay(200);
  
  for(int i = 27; i <= 89; i++) { //return top servo to the first position to catch another candy
    topServo.write(i);
    delay(2);
  }
  color=0;
}


int readColor() { //color sensor function to read the color
  
  // Setting red
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  frequency = pulseIn(sensorOut, LOW);
  int R = frequency;
  Serial.print("R= ");
  Serial.print(frequency);
  Serial.print("  ");
  delay(50);
  
  // Setting Green
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  frequency = pulseIn(sensorOut, LOW);
  int G = frequency;
  Serial.print("G= ");
  Serial.print(frequency);
  Serial.print("  ");
  delay(50);
  
  // Setting Blue
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  frequency = pulseIn(sensorOut, LOW);
  int B = frequency;
  Serial.print("B= ");
  Serial.print(frequency);
  Serial.println("  ");
  delay(50);
  
  if(R<95 & R>85 & G>110 & G<130 & B>89 & B<106){
    color = 1; // Red
  }
  if(G<70 & G>55 & R<75 & R>65 &B<65 & B>54){
    color = 2; // Green
  }
  if (B<80 &B>70 & G>99 & G<110 & R>100 & R<120){
    color = 3; // Blue
  }
  return color;  
}
