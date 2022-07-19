#include <Arduino.h>
#include "fastpwmo.h"
bool flag=false;
int i=2;
double now=0;
double prev=0;

void setup() {
  Serial.begin(9600);
  SREG=1<<SREG_I;
    DDRB = 1<<PB1;
    TCCR1A = 1<<COM0A1|1<<WGM10;
    TCCR1B = 1<<CS10|1<<CS12|1<<WGM12;// last two bits setting prescaler
    OCR0A = i;
    TIMSK1=1<<OCIE1A;
    //analogWrite(6,OUTPUT);

  // put your setup code here, to run once:
}

void loop() {
  if (flag)
  {now=millis();
  Serial.println(now-prev);
    Serial.println("Interupt Happen");
    flag=false;
  }
  // put your main code here, to run repeatedly:
}
ISR(TIMER1_COMPA_vect)
{
  flag=true;
  if(i==255)
  {
    i=2;
    OCR0A = i;
  } 
  else{
    OCR0A = i;
    i++;

  }
}