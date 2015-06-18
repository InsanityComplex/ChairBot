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

void ChairBot::turn(int degrees){
	int current_heading=(compass.get_heading()+degrees)%360;
	this->drive(128,-128);
	while(compass.get_heading()!=current_heading){
		}
	this->drive(0,0);
	}

void ChairBot::turn_to_heading(int degrees){
	this->drive(128,-128);
	while(!((degrees-2)>compass.get_heading()>(degrees+2))){}
	this->drive(0,0);
	}


unsigned int ChairBot::distance_left(){
	int reading=sensors[0].ping_cm();
	if(reading==0){reading=1000;}
	return reading;
	}

unsigned int ChairBot::distance_center(){
	if(reading==0){reading=1000;}
	int reading=sensors[1].ping_cm();
	return reading;
	}

unsigned int ChairBot::distance_right(){
	int reading=sensors[2].ping_cm();
	if(reading==0){reading=1000;}
	return reading;
	}

int ChairBot::get_heading(){
	return compass.get_heading();
	}
