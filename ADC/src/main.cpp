#include <Arduino.h>

void setup() {
  Serial.begin(9600);
  SREG   = 1<<7; //SREG – AVR Status Register The avr status register – SREG – Bit 7 – I: Global Interrupt Enable
  ADCSRA = 1<<7 | 1<<6 | 1<<5| 1<<3 | 0<<2 | 1<<1 | 0<<0;//23.9.2 ADCSRA – ADC Control and Status Register A
  ADMUX  = 0<<7|1<<6|0<<5|0<<3|0<<2|0<<1|0<<0;// iN the LAST zero bit we use 0000 fri ADC0;//Table 23-3. Voltage Reference Selections for ADC \\0 1 AVCC with external capacitor at AREF pin
  ADCSRB = 0<<2|0<<1|0<<0;//Table 23-6. ADC Auto Trigger Source Selections 0 0 0 For Free running mode
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
}
ISR(ADC_vect)
{
  Serial.println(ADC);
}