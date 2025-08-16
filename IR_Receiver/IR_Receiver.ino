 #include <IRremote.h>
const int LED = 8;
const int LED2 = 2;
const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
bool turnledon=false;
bool turnledon2=false;
const unsigned long ExpectedHex1 =0xA619148B;
const unsigned long ExpectedHex =0x70E6B703;
void setup(){
  Serial.begin(1200);
  irrecv.enableIRIn();
  pinMode(LED,OUTPUT);
}

void loop(){

  
if (turnledon) 
 { 
   digitalWrite(LED, HIGH); 
   
 } 
 else
 { 
   digitalWrite(LED, LOW); 
  
 }


if (turnledon2) 
 { 
   digitalWrite(LED2, HIGH); 
   
 } 
 else
 { 
   digitalWrite(LED2, LOW); 
  
 }
  
  if (irrecv.decode(&results)){
        Serial.println(results.value,HEX);
        if(results.value==ExpectedHex1)
        {
          turnledon=!turnledon;
          }
 else if(results.value==ExpectedHex)
        {
          turnledon2=!turnledon2;
          }
        irrecv.resume();
  }
}
 
