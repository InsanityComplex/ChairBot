#include "Arduino.h"

class ChairBot{
	public:
	long heading;
	int leftSpeed;
	int rightSpeed;
	int MAX_SPEED;	
	int left_sonar;
	int right_sonar;
	ChairBot();
	void drive(int left, int right);
	/*
	void forward(int forwardSpeed);
	void backward(int backwardSpeed);
	void turnLeft(int degrees);
	void turnRight(int degrees);
	void spinLeft(int degrees);
	void spinRight(int degrees);
	*/
	void get_heading();
	void check_sonar();
	
};

