// #include <WiFi.h>
// #include "ESPAsyncWebServer.h"
//  int input1,input2;
// const char *ssid = "epT";
// const char *password = "112233";

// AsyncWebServer server(80);

// void setup(){
//   Serial.begin(9600);
//   WiFi.softAP(ssid, password);

  
//   Serial.print("IP address: ");
//   Serial.println(WiFi.softAPIP());

//   server.on("/azeem", HTTP_GET, [](AsyncWebServerRequest *request){
//     request->send(200, "text/html", "Hello welcome to this new world!");
//   });


  
//   server.begin();
// }

// void loop(){}
#include <WiFi.h>
#include "ESPAsyncWebServer.h"
 
const char* ssid = "EPT";
const char* password =  "hello123";
 
AsyncWebServer server(80);
 
void setup(){
  Serial.begin(9600);
 
  WiFi.softAP(ssid, password);
 
  // while (WiFi.status() != WL_CONNECTED) {
  //   delay(1000);
  //   Serial.println("Connecting to WiFi..");
  // }
 
  Serial.println(WiFi.softAPIP());
 
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    char buffer[200];
    String test="her is the valule"; 
    String input1 =request->getParam("param1")->value(); 
    String input2 =request->getParam("param2")->value();
    sprintf(buffer, "{\"input1\":%s, {\"input-test\":%s},\"input2\":%s}",input1,test,input2);
    request->send(200,"application/json",buffer);

    int paramsNr = request->params();
    Serial.println(paramsNr);


 

    for(int i=0;i<paramsNr;i++){
 
        AsyncWebParameter* p = request->getParam(i);
        Serial.print("Param name: ");
        Serial.println(p->name());
        Serial.print("Param value: ");
        Serial.println(p->value());
        Serial.println("------");
        
    }
    

 
    request->send(200, "text/plain", "message received");
  });
 
  server.begin();
}
 
void loop(){}