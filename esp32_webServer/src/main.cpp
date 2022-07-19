#include <WiFi.h>
#include "ESPAsyncWebServer.h"

const char *ssid = "EP";
const char *password = "11223300";

AsyncWebServer server(80);

void setup(){
  Serial.begin(9600);
  WiFi.softAP(ssid, password);

  Serial.println();
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());

  server.on("/umer", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html", "Hello welcome to this new world!");
  });

  server.begin();
}

void loop(){}