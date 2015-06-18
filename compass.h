#ifndef compass_h
#define compass_h

#include <Arduino.h>

class compass{
	public:
	float heading;
	
	compass();
	void begin();
	int get_heading();
};

#endif //compass_h
