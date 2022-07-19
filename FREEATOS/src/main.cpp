#include <Arduino.h>
#include <SPI.h>
#include <Arduino_FreeRTOS.h>


  void alpha();
  void beta();

void setup() {

  Serial.begin(9600);
  pinMode(13, OUTPUT);
  xTaskCreate(alpha,"this is alpha function", 128, NULL, 1, NULL);
  Serial.begin(9600);
  xTaskCreate(beta,"this is beta function", 128, NULL, 2, NULL);
  vTaskStartScheduler();

  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}

void alpha()
{
  for (;;)

  {
    digitalWrite(13, HIGH);
    vTaskDelay(500);
    digitalWrite(13, LOW);
    Serial.println("Hello this is alpha");
    vTaskDelay(500);
    
  }
}

void beta()

{
  for (;;)

  {
    Serial.println("Hello this is beta");
    vTaskDelay(1000);
  }
}
