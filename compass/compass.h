#include <Arduino.h>

class compass{
	public:
	float heading;
	
	compass();
	void begin();
	int get_heading();
};
