/*
  Example from WiFi > WiFiScan
  Complete details at https://RandomNerdTutorials.com/esp32-useful-wi-fi-functions-arduino/
*/

#include "WiFi.h"

void setup() {
  Serial.begin(9600);

  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  Serial.println("Setup done");
}

void loop() {
  Serial.println("scan start");

  // WiFi.scanNetworks will return the number of networks found
  int n = WiFi.scanNetworks();
  Serial.println("scan done");
  if (n == 0) {
      Serial.println("no networks found");
  } else {
    Serial.print(n);
    Serial.println(" networks found");
    for (int i = 0; i < n; ++i) {
      // Print SSID and RSSI for each network found
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
      delay(10);
    }
    }
  Serial.println("");

  // Wait a bit before scanning again
  delay(5000);
}




// #include "WiFi.h"
// //#include <AsyncTCP.h>
// #include <ESPAsyncWebServer.h>
// #include <WiFiClient.h> 

// const char *ssid = "ESP32";
// const char *password = "12345678";

// IPAddress Iocal_ip(192, 168, 1, 1);
// IPAddress gateway(192, 168, 1, 1);
// IPAddress subnet(255, 255, 255, 0);

// AsyncWebServer server(80);

// void setup()
// {
//   Serial.begin(9600);
//   WiFi.softAP(ssid, password);
//   WiFi.softAPConfig(Iocal_ip, gateway, subnet);

//   server.on("/hello", HTTP_GET, [](AsyncWebServerRequest *request)
//             {
//     String input1;
//     char buffer[200];
//     if (request->hasParam("input1"))
//     {
//       input1 = request->getParam("input1")->value();
//       sprintf(buffer, "{input1 : %s}",input1);
//       request->send(200,"application/json",buffer);
//     } });
//   server.on("/ledoff", HTTP_GET, [](AsyncWebServerRequest *request)
//             { request->send(200, "text/html", "The led is off"); });
//   server.on("/hell/ledon", HTTP_GET, [](AsyncWebServerRequest *request)
//             { request->send(200, "text/html", "The led is on"); });

//               server.on("/scan", HTTP_GET, [](AsyncWebServerRequest *request){
//     String json = "[";
//     int n = WiFi.scanComplete();
//     if(n == -2){
//       WiFi.scanNetworks(true);
//     } else if(n){
//       for (int i = 0; i < n; ++i){
//         if(i) json += ",";
//         json += "{";
//         json += "\"rssi\":"+String(WiFi.RSSI(i));
//         Serial.println();
//         json += ",\"ssid\":\""+WiFi.SSID(i)+"\"";
//         Serial.println();
//         // json += ",\"bssid\":\""+WiFi.BSSIDstr(i)+"\"";
//         // json += ",\"channel\":"+String(WiFi.channel(i));
//         // json += ",\"secure\":"+String(WiFi.encryptionType(i));
//        // json += ",\"hidden\":"+String(WiFi.isHidden(i)?"true":"false");
//         json += "}";
//       }
//       WiFi.scanDelete();
//       if(WiFi.scanComplete() == -2){
//         WiFi.scanNetworks(true);
//       }
//     }
//     json += "]";
//     request->send(200, "text/json", json);
//     json = String();
//   });
//   server.begin();
// }

// void loop()
// {
// }