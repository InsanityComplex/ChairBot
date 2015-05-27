#include <SoftwareSerial.h>
#include <NewPing.h>
#include <Wire.h>
#include <compass.h>
#include <ChairBot.h>

ChairBot cb;
boolean state=0;

void setup() {
  Serial.begin(9600);
  cb.begin();
}

void loop() {
  digitalWrite(13, state);
  Serial.println(cb.get_heading());
  state=!state;
  delay(100);
  /*
  cb.drive(2000, 2000); 
  delay(500);
  cb.drive(-2000, 2000);
  delay(500); 
  cb.drive(2000, -2000);
  delay(500); 
  */
}
