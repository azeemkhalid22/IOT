#include<Arduino.h>
#include<Wire.h>
#include"whomi.h"
void alpha(){
    Serial.begin(9600);
    Wire.begin();

}
void whomi(){
    uint8_t Sensor_value1=0;
    uint8_t Sensor_value2=0;
    int temp=0;
    Wire.beginTransmission(0x68);//acces on this device 7 bit address as shown in notebook diagram
    Wire.write(0x41);
    Wire.requestFrom(0x68 , 8);
    Sensor_value1 = Wire.read();


    Wire.write(0x42);
    delay(10);
    Wire.requestFrom(0x68 , 8);
    Sensor_value2 = Wire.read();


    temp = Sensor_value1<<8 |Sensor_value2;
    temp = (temp/333)+21;

    
    Wire.endTransmission();
    Serial.println("value of temperature ");
    Serial.println(temp);
    delay(1000);


}