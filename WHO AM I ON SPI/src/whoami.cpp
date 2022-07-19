#include<Arduino.h>
#include"whoami.h"
#include<SPI.h>
uint16_t high = 0;
uint8_t low = 0;
uint16_t x_valu = 0;
uint16_t y_valu = 0;
uint16_t z_valu = 0;
uint16_t temp = 0;
void alpha(){
    Serial.begin(9600);
    SPI.begin();
    pinMode(10,OUTPUT); //to enable spi (by selecting pin 10 on arduino board,and set it to low)
}


//for readuing value in spi
void who_am_i(){
    digitalWrite(10, LOW);//to activate slave we put it to high
    SPI.transfer(0X75 | (1<<7));//bcz we use same transfer funtion for read and write in SPI so to read value we have to set 7 bit to 1 to read
    high = SPI.transfer(0x00);
    digitalWrite(10, HIGH);//to end transmission instead of using begin transmission and end transmission
    Serial.println(high,HEX);
}


//for reading temperature
void who_am_i(){
    digitalWrite(10, LOW);//to activate slave we put it to high
    SPI.transfer(0X41 | 1<<7);//bcz we use same transfer funtion for read and write in SPI so to read value we have to set 7 bit to 1 to read
    high = SPI.transfer(0x00);
    low = SPI.transfer(0x00);
    digitalWrite(10, HIGH);//to end transmission instead of using begin transmission and end transmission
    temp = high<<8|low;
    temp = (temp/333)+21;
    Serial.println(temp);
}

//  gyroscpe
// void who_am_i(){
// //for x
//     digitalWrite(10, LOW);
//     //to activate slave we put it to high
//     SPI.transfer(0X0F | 1<<7);//bcz we use same transfer funtion for read and write in SPI so to read value we have to set 7 bit to 1 to read
//     high = SPI.transfer(0x00);
//     low = SPI.transfer(0x00);
//     x_valu = high<<8|low;
// //for y
    
//     high = SPI.transfer(0x00);
//     low = SPI.transfer(0x00);
//     y_valu = high<<8|low;
    

    
// //for z
//     high = SPI.transfer(0x00);
//     low = SPI.transfer(0x00);
//     z_valu = high<<8|low;

//     digitalWrite(10, HIGH);//to end transmission instead of using begin transmission and end transmission
    
    
//     Serial.println(x_valu);
//     Serial.println(y_valu);
//     Serial.println(z_valu);
// }