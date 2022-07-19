#include<Arduino.h>
#include "fastpwm.h"
void pwminit(){

    DDRD = 1<<6;
    TCCR0A = 1<<7|0<<6|1<<1|1<<0;
    TCCR0B = 0<<3|0<<2|0<<1;// last two bits setting prescaler
    OCR0A = 128;
}