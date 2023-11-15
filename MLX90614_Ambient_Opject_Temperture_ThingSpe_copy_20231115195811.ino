
#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <WiFi.h>
#include <WiFiMulti.h>
#include "ThingSpeak.h" //Thingspeak Header File:
WiFiMulti wifiMulti;
WiFiClient  client;
unsigned long WriteChannelNumber = 2315372; //Write Channel Number and API Key:
const char * WriteAPIKey = "MQGNWWRVUCXZSBCJ";
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
int DL = 1500; //Delay Period:
int counT = 0;

void setup() 
{
Serial.begin(115200);
Serial.println("Adafruit MLX90614\n\n");  
mlx.begin(); 
ThingSpeak.begin(client);  //Initialize ThingSpeak:
wificonnect();
}

void wificonnect()
 {
  wifiMulti.addAP("Tab11S", "Sowga1966!");
    wifiMulti.addAP("Galaxy A73", "Sowga1966!");
      wifiMulti.addAP("R+ Secure", "ReadingR+22!");
        wifiMulti.addAP("VM5774222", "b3rVddgtbvmp");

    //Serial.println("Connecting Wifi...");
    if(wifiMulti.run() == WL_CONNECTED) {
        //Serial.println("");
        //Serial.print("WiFi connected ");
        //Serial.println(WiFi.SSID());
       // Serial.print("IP address: ");
        //Serial.println(WiFi.localIP());
        delay(500);
 } 
}

void loop() {
  if (wifiMulti.run() == !WL_CONNECTED) 
  {
    wificonnect();
  }
  
  float aMbient =  mlx.readAmbientTempC();
  float tObject =  mlx.readObjectTempC();
  int i = float(tObject);
  //Serial.print("Ambient = "); Serial.print(aMbient); 
  //Serial.print("°C\tObject = "); Serial.print(tObject); Serial.print("°C ");
  //Serial.print("    Ambient int = "); 
  //Serial.println(i); //Serial.println("°C\n");
      Serial.write(i);
  //Serial.print(i);
  ThingSpeak.setField(1, aMbient);
  ThingSpeak.setField(2, tObject); 
  ThingSpeak.setField(3, counT);
  ThingSpeak.writeFields(WriteChannelNumber, WriteAPIKey);
  int statusCode = ThingSpeak.getLastReadStatus();
  if(statusCode == 200)
  {
 counT++;
 //Serial.print("Status Code "); Serial.print(statusCode); Serial.print(" ThingSpeak Write Completed "); Serial.print(WiFi.SSID()); Serial.print(" "); Serial.print(counT); Serial.println("\n");
 delay(DL); 
    }
 }
