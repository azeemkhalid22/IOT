#include<Arduino.h>
#include "fastPWMisr.h"
int count;
void fastPWMisr(){
    DDRB = 1<<5;//D13 as output
    TCCR0A = 1<<7|1<<6|1<<1|1<<0;//fastPWM mode selection also wavebits() 
    TCCR0B = 0<<3|0<<2|0<<1|1<<0;//last 3 bit are used for setting prescaler
    OCR0A = 45;
    SREG = 1<<7;
    TIMSK0 = 1<<1;
}
ISR(TIMER0_COMPA_vect){
    count++;
    if (count>100){
        PORTB^=1<<5;
    }

}