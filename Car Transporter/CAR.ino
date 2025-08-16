#include <Servo.h>
#include <AFMotor.h>

Servo myservo,myservo2;

const int Pin = 9; // 
const int Pin2 = 10; // 
char Text;

String Spilt;
String Spilt2;
String angle;
String angle2;
int pos = 0;    // variable to store the servo position

int k1;
int k2;


AF_DCMotor MR(4);
AF_DCMotor ML(3);
AF_DCMotor MBR(1);
AF_DCMotor MBL(2);

char state = 0;


void setup() {



Serial.begin(9600); // Starts the serial communication

pinMode (Pin, OUTPUT); 
pinMode (Pin2, OUTPUT); 

myservo.attach(Pin);
myservo2.attach(Pin2);
Serial.println("1 -> LEFTWARD   2 -> BACKWARD   3 -> RIGHTWARD   5 -> FORWARD   9 -> RELEASE"); 
Stop();

}
void loop() {
   if (Serial.available()>0)
  {
    Text = Serial.read();
    Spilt = Spilt + Text; 
    Spilt2 = Spilt2 + Text;    
    if(Text == 'L')
    {
      MR.run(FORWARD);
      MR.setSpeed(220);
      ML.run(BACKWARD);
      ML.setSpeed(220);
      MBR.run(FORWARD);
      MBR.setSpeed(220);
      MBL.run(BACKWARD);
      MBL.setSpeed(220);
      Serial.println("LEFTWARD");
    }
    else if (Text == 'B')
    {
      MR.run(BACKWARD);
      MR.setSpeed(220);
      ML.run(BACKWARD);
      ML.setSpeed(220);
      MBR.run(BACKWARD);
      MBR.setSpeed(250);
      MBL.run(BACKWARD);
      MBL.setSpeed(250);
      Serial.println("BACKWARD");
    }
    else if (Text == 'R')
    {
      MR.run(BACKWARD);
      MR.setSpeed(220);
      ML.run(FORWARD);
      ML.setSpeed(220);
      MBR.run(BACKWARD);
      MBR.setSpeed(220);
      MBL.run(FORWARD);
      MBL.setSpeed(220);
      Serial.println("RIGHTWARD");
    }
    else if (Text == 'F')
    {
      MR.run(FORWARD);
      MR.setSpeed(220);
      ML.run(FORWARD);
      ML.setSpeed(220);
      MBR.run(FORWARD);
      MBR.setSpeed(220);
      MBL.run(FORWARD);
      MBL.setSpeed(220);
      
      Serial.println("FORWARD");
    }
    else if (Text == 's')
    {
      MR.run(RELEASE);
      ML.run(RELEASE);
      MBR.run(RELEASE);
      MBL.run(RELEASE);
      Serial.println("RELEASE");
    }
if (Text == '*') {
        
      Serial.println(Spilt);

      Spilt = Spilt.substring(0, Spilt.length() - 1); // Delete last char *

      k1 = Spilt.indexOf('*');

      angle = Spilt.substring(0, k1);

      myservo.write(angle.toInt());

      delay(15);  

  

      Spilt = "";   

  }
  else if(Text == '+'){
      Serial.println(Spilt2);

      Spilt2 = Spilt2.substring(0, Spilt2.length() - 1); // Delete last char *

      k2 = Spilt2.indexOf('*');

      angle2 = Spilt2.substring(0, k2);

      myservo2.write(angle2.toInt());

      delay(15);  

  

      Spilt2 = "";   

      }


    
  }

}

void Stop(){
      MR.run(RELEASE);
      ML.run(RELEASE);
      MBR.run(RELEASE);
      MBL.run(RELEASE);
}
