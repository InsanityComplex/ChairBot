#include <SoftwareSerial.h>
#include <NewPing.h>
#include <Wire.h>
#include <compass.h>
#include <ChairBot.h>

ChairBot cb;
boolean state=0;

int distance_threshold=50;
int right;
int left;

void setup() {
  Serial.begin(9600);
  cb.begin();
  pinMode(13, OUTPUT);
}

void loop() {
//	cb.turn(10);
	left=cb.distance_left();
	right=cb.distance_right();
	if (left<distance_threshold && right<distance_threshold && left>0&&right>0){
		cb.drive(-500,-500);
	}
	else if (left<distance_threshold && left>0){
		cb.drive(250,-250);
		delay(500);
	}
	else if (right<distance_threshold && right>0){
		cb.drive(-250,250);
		delay(500);
	}
	else{
		cb.drive(500,500);	
	}
Serial.print(cb.distance_left());
Serial.print(",");
Serial.print(cb.distance_center());
Serial.print(",");
Serial.println(cb.distance_right());
}
