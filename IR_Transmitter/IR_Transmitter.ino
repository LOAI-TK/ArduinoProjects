#include <IRremote.h>
#define cr_pin 3

IRsend irsend;
decode_results results;
unsigned long key_value = 0;
const int buttonPin = 4;  
int buttonState = 0;
const int buttonPin2 = 7;
int buttonState2 = 0;
void setup() {
Serial.begin(1200);  /* Define baud rate for serial communication */
tone(cr_pin, 38000);  /* For modulation at 38kHz */
 pinMode(buttonPin, INPUT);
 pinMode(buttonPin2, INPUT);
}

void loop() {

 buttonState = digitalRead(buttonPin);
buttonState2 = digitalRead(buttonPin2);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
 
  if (buttonState == HIGH)
  {
    irsend.sendNEC(0xFEA857,32);
    Serial.println("I'ts A");
  delay(200);  
  }
 if (buttonState2 == HIGH)
  {
    irsend.sendNEC(0xAEA787,32);
    Serial.println("It's B");
  delay(200);  
  }
}
