#include "Arduino.h"

class ChairBot{
	public:
	long heading;
	int leftSpeed;
	int rightSpeed;
	
	ChairBot();

	void forward(int forwardSpeed);
	void backward(int backwardSpeed);
	void turnLeft(int degrees);
	void turnRight(int degrees);
	void spinLeft(int degrees);
	void spinRight(int degrees);
	void check_sonar();
	int read_sonar(int sensor_number);
	
};

