#include <Arduino.h>
#include <Wire.h>
#include "mpu.h"

void alpha(){
     Serial.begin(9600);
     Wire.begin();
}

//sensing temperature
 void temp_mpu(){
  uint8_t high = 0;
  uint8_t low = 0;
  uint16_t temp = 0;

  Wire.beginTransmission(0x68);
  
  Wire.write(0x41);
  Wire.requestFrom(0x68,8);
  high = Wire.read();

  Wire.write(0x42);
  Wire.requestFrom(0x68,8);
  low = Wire.read();

  temp = high<<8 | low;
  temp = (temp/333)+21;

  Wire.endTransmission();

  Serial.println("value of temperature is");
   Serial.println(temp);
   delay(1000);
  }

  void gyro_mpu(){
    //for X value
    int gyr_x, gyr_y, gyr_z = 0;
    uint8_t high, low;
    Wire.beginTransmission(0x68);
    Wire.write(0x43);
    Wire.requestFrom(0x68,8);
    high = Wire.read();
    low = Wire.read();
    Wire.endTransmission();
    gyr_x = high<<8|low;
    //for Y value
     high, low = 0;
    Wire.beginTransmission(0x68);
    Wire.write(0x45);
    Wire.requestFrom(0x68,8);
    high = Wire.read();
    low = Wire.read();
    Wire.endTransmission();
    gyr_y = high<<8|low;

    //for Z value
     high, low = 0;
    Wire.beginTransmission(0x68);
    Wire.write(0x47);
    Wire.requestFrom(0x68,8);
    high = Wire.read();
    low = Wire.read();
    Wire.endTransmission();
    gyr_z = high<<8|low;
    

    Serial.print("The value of X is:");
    Serial.println(gyr_x);
    Serial.print("The value of Y is:");
    Serial.println(gyr_y);
    Serial.print("The value of Z is:");
    Serial.println(gyr_z);
    Serial.println("  ");
    delay(5000);
  }

 void acc_mpu()
{
    int acc_x, acc_y, acc_z = 0;
    uint8_t high, low = 0;
    //for X
    Wire.beginTransmission(0x68);
    Wire.write(0x3B);
    Wire.requestFrom(0x68,8);
    high = Wire.read();
    low = Wire.read();
    Wire.endTransmission();
    acc_x = high<<8|low;
    //for Y
    high,low = 0;
    Wire.beginTransmission(0x68);
    Wire.write(0x3D);
    Wire.requestFrom(0x68,8);
    high = Wire.read();
    low = Wire.read();
    Wire.endTransmission();
    acc_y = high<<8|low;

//  for Z
    high,low = 0;
    Wire.beginTransmission(0x68);
    Wire.write(0x3F);
    Wire.requestFrom(0x68,8);
    high = Wire.read();
    low = Wire.read();
    Wire.endTransmission();
    acc_z = high<<8|low;

    Serial.print("The value of acc at x: ");
    Serial.println(acc_x);

    Serial.print("The value of acc at y: ");
    Serial.println(acc_y );

    Serial.print("The value of acc at z: ");
    Serial.println(acc_z);
    delay(5000);
}