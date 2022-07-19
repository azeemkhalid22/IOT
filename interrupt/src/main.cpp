#include <Arduino.h>
#include <Wire.h>
#include "mpu.h"

void setup() {
  // put your setup code here, to run once:
   alpha();
}

void loop() {
  // code for sensing the temprature from mpu9250 usimg temperature sensor
  // temp_mpu();
  // gyro_mpu();
     acc_mpu();

 
}
