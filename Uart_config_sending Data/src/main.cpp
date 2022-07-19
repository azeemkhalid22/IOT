// #include <Arduino.h>
// void uart_init();

// uint8_t num;
// char data[90];
// char ch;
// int index = 0;
// void setup()
// {
//   uart_init();
//   // put your setup code here, to run once:
// }

// void loop() {
//    //apply and operations
//   if (0x80 & UCSR0A)
//   {

//       ch = UDR0;
//       if(ch != '\n' && ch!=NULL)
//         {
//           data[index] = ch;
//           index ++;
//           ch=NULL;
//         }
//         else{
//           for(int i=0; i<index; i++){
//             UDR0= data[i];
//           }
//             index = 0;
//         }
//     }
  
//   delay(100);
//   // for (int i = 0; i < 5; i++)
//   // {
//     // /* code */ UDR0=data[i];
//   // }
//   // if (data[i]==
  
//   // put your main code here, to run repeatedly:
// }
// // }
// void uart_init(){
//   UCSR0A=0x00;
//   UCSR0B = 0x18;
//   UCSR0C = 0x06;
//   UBRR0 = 103;
//   }





  
// void send_Data(){
  

// }  


/*Interupts Test*/

/**
Interrupt example - The Arduino way
For use with Arduino UNO and other 328 Arduino's
- Connect a button to pin 2 (with 10k pulldown)
- Connect a LED to pin 9 (with 220/330 Ohm resistor)

Nov 2013, Jens Brynildsen http://flashgamer.com/arduino/
**/
#include <Arduino.h>
#define  interupt_pin 3;

void pin2ISR()
{
  digitalWrite(13, !digitalRead(13));    // Toggle LED on pin 13

}

void setup(void)
{
  Serial.begin( 9600 );
  pinMode(interupt_pin, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  attachInterrupt(interupt_pin, pin2ISR, FALLING);
}

// Normale Interrupt Service Routine in Arduino


void loop(void)
{
}