#include <SoftwareSerial.h>
#include <NewPing.h>
#include <ChairBot.h>

ChairBot cb;

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop() {
  Serial.println(analogRead(0));
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
