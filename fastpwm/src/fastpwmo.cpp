#include<Arduino.h>
#include "fastpwmo.h"
void pwminit(){

    DDRD = 1<<6;
    TCCR0A = 1<<COM0A1|0<<COM0A0|1<<WGM01|1<<WGM00;
    TCCR0B = 0<<WGM02|0<<CS02|0<<CS01;// last two bits setting prescaler
    OCR0A = 128;
    analogWrite(6,OUTPUT);
}