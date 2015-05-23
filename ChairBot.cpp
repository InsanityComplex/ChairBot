#include "Arduino.h"
#include <SoftwareSerial.h>
#include <NewPing.h>
#include <compass.h>
#include "ChairBot.h"

int MAX_SPEED=1028;
SoftwareSerial motor(2,3);
compass compass;
//NewPing left_sonar(7,8);

ChairBot::ChairBot(){
//	attachInterrupt(0, ChairBot::count_pulse, CHANGE);
	}

void ChairBot::begin(){
	motor.begin(9600);
	compass.begin();
	}

void ChairBot::drive(int left, int right){
	//left=max( -MAX_SPEED, min( MAX_SPEED, left) );
	//right=max( -MAX_SPEED, min( MAX_SPEED, right) );
	motor.print("M1:");
	motor.println(left);
	motor.print("M2:");
	motor.println(right);
	}

void ChairBot::check_sonar(){
	
	}

int ChairBot::get_heading(){
	return compass.get_heading();
	}
/*
void ChairBot::count_pulse(){
	if (pulse_toggle){
		pulse_stop=micros();
		}
	else{
		pulse_start=micros();
		}
	}
*/
