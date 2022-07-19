#include <Arduino.h>
#include "fastpwm.h"

// bool state=true;

void setup() {
    pwminit();
}
//   // put your setup code here, to run once:
//    pinMode(5,OUTPUT);
//    digitalWrite(5,state);
//     SREG   = 1<<SREG_I;
//     TCCR1A = 1<<COM1A0;//CTC enabled
//     TCCR1B = 1<<CS10|1<<CS12|1<<WGM12;//PRESCALER IS SET
//     TCNT1=0x00;
//     // OCR1A  =7812;//COMPARE REGISER VALUE
//    /// OCR0A  = 128;//COMPARE REGISER VALUE
//     //GLOBAL INTERRUPT ENABLE
//     TIMSK1 = 1<<OCIE1A;//TIMER0 OCROA INTERRUPT ENABLE

//     //DDRB = 1<<PD1;

// }

// void loop() {
//   // put your main code here, to run repeatedly:
// }
// ISR(TIMER1_COMPA_vect){
//   if(state)
//   {
//     state=!state;
//    digitalWrite(5,state);
//    TCNT1=0x00;
//    OCR1A  =2000;
//   }
//   else{
//      state=!state;
//    digitalWrite(5,state);
//    TCNT1=0x00;
//    OCR1A  =7812;
//   }
   
// }