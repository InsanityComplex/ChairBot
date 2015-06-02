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
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, state);
  cb.turn_to_heading(90);
	/*
  Serial.print(cb.distance_left());
  Serial.print(",");
  Serial.print(cb.distance_center());
  Serial.print(",");
  Serial.println(cb.distance_right());
*/
  state=!state;
  Serial.println(state);
  delay(1000);
}
