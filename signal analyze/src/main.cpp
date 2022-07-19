#include <Arduino.h>

void setup() {
  DDRB = 1<<0;   // select pins from 8 to 13 for PORTB and 0-5 for portD
  // put your setup code here, to run once:
}

void loop() {
  PORTB = 1<<0;
  delay(2000);
  PORTB = 0<<0;
  delay(2000);
  
  
  // put your main code here, to run repeatedly:
}