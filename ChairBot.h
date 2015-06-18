#ifndef ChairBot_h
#define ChairBot_h

#include "Arduino.h"
#include "compass.h"

class ChairBot{
	public:
	long heading;
	int leftSpeed;
	int rightSpeed;
	int MAX_SPEED;	
	int left_sonar;
	int right_sonar;

	int pulse_start;
	int pulse_stop;
	int pulse_toggle;


	ChairBot();
	void begin();
	void drive(int left, int right);
	/*
	void forward(int forwardSpeed);
	void backward(int backwardSpeed);
	void turnLeft(int degrees);
	void turnRight(int degrees);
	void spinLeft(int degrees);
	void spinRight(int degrees);
	*/
	int get_heading();
	void turn(int degrees);
	void turn_to_heading(int degrees);
	unsigned int distance_left();
	unsigned int distance_center();
	unsigned int distance_right();
};

#endif //ChairBot_H
