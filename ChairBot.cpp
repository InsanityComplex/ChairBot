#include "Arduino.h"
#include <SoftwareSerial.h>
#include <NewPing.h>
#include "ChairBot.h"

int MAX_SPEED=128;

SoftwareSerial motor(2,3);
NewPing left_sonar(7,8);

ChairBot::ChairBot(){
	attachInterrupt(0, ChairBot::count_pulse, CHANGE);
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

void ChairBot::count_pulse(){
	if (pulse_toggle){
		pulse_stop=micros();
		}
	else{
		pulse_start=micros();
		}
	}

