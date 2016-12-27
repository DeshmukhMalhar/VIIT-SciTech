/*
 * IoT People Counter Using ESP8266-12 [NodeMCU 0.9]
 * This will connect to http://thingspesk.com/channels/207120
 * So, everyone can see an application of IoT and Arduino
 * Last edit by DeshmukhMalhar (@MalharD)
 */
#include <ThingSpeak.h>

#include <ESP8266WiFi.h>

#define ESP8266
#define DEBUG

int count = 0;
const char * ssid = "0x32";
const char * passphrase = "00110010";

unsigned long myChannelNumber = 207120;//your channel number
const char * myWriteAPIKey = "<YourAPIKey";//APIkey not shown IT is PRIVATE!
WiFiClient  client;
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(250000);

  WiFi.begin(ssid, passphrase);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  //read the input on analog pin 0:
  int sensorValueA = digitalRead(12);
  int sensorValueB = digitalRead(13);
#ifdef DEBUG
  Serial.println(sensorValueA);
  Serial.println(sensorValueB);
#endif
  delay(1);
  if (sensorValueA == HIGH) {
    delay(10);
    if (sensorValueB == HIGH) {
      count ++;
    }
  }
  if (sensorValueB == HIGH) {
    delay(10);
    if (sensorValueA == HIGH) {
      count--;
    }
  }

  delay (30);

  ThingSpeak.writeField(myChannelNumber, 1, count, myWriteAPIKey);

}
