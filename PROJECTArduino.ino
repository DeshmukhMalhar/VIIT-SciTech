/*
 * People Counter using Arduino and Two LDRs and Two lasers
 * Code for Standalone arduino
 * The count will be displayed on 16X02 LCD display connected uaing I2C interface
 * Last Edit -DEshmukhMalhar(MalharD)
 */
#define DEBUG
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "IICLCDsetup.h"
int count = 0;
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(250000);
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
  lcd.print("Count is : ");
  lcd.setCursor(0, 11);
  lcd.print (count);

}
