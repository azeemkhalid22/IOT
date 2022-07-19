#include <Arduino.h>

#define Pin 6
void setup() {
  pinMode(Pin,OUTPUT);
  // put your setup code here, to run once:
}

void loop() {

  for(int value1= 0; value1<=255; value1++){
    analogWrite(Pin, value1);
    delay(10);
  }
  
  for(int value= 255; value>0; value--){
    analogWrite(Pin, value);
    delay(10);
  }

}