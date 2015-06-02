#include "Arduino.h"
#include <SoftwareSerial.h>
#include <NewPing.h>
#include <compass.h>
#include "ChairBot.h"

int MAX_SPEED=1028;
int MAX_PING=500;  //Reduce this if pings are causing lag

SoftwareSerial motor(2,3);
compass compass;

NewPing sensors[3]={
	NewPing(4,5, MAX_PING),
	NewPing(6,7, MAX_PING), //Trigger pin, echo pin, max wait time
	NewPing(8,9, MAX_PING)
};

ChairBot::ChairBot(){
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

void ChairBot::turn(){
	
	}

void ChairBot::turn_to_heading(){

	}


unsigned int ChairBot::distance_left(){
	return sensors[0].ping_cm();
	}

unsigned int ChairBot::distance_center(){
	return sensors[1].ping_cm();
	}

unsigned int ChairBot::distance_right(){
	return sensors[2].ping_cm();
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
