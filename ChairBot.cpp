#include "Arduino.h"
#include <SoftwareSerial.h>
#include "ChairBot.h"

int MAX_SPEED=128;

SoftwareSerial motor(2,3);

ChairBot::ChairBot(){
	}

void ChairBot::drive(int left, int right){
	left=max( -MAX_SPEED, min( MAX_SPEED, left) );
	right=max( -MAX_SPEED, min( MAX_SPEED, right) );
	motor.print("M0:");
	motor.println(left);
	motor.print("M1:");
	motor.println(right);
	}

void ChairBot::check_sonar(){
	
	}
