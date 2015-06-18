#include <Arduino.h>
#include <compass.h>
#include <Wire.h>

#define address 0x1E //Address of magnetometer
int declination = 11;

compass::compass(){
	}

void compass::begin(){
	Wire.begin();
	Wire.beginTransmission(address); //open communication with HMC5883
  	Wire.write(0x02); //select mode register
  	Wire.write(0x00); //continuous measurement mode
 	Wire.endTransmission();
}

int compass::get_heading(){
	int x,y,z;
	Wire.beginTransmission(address);
  	Wire.write(0x03); //select register 3, X MSB register
  	Wire.endTransmission();
 
 //Read data from each axis, 2 registers per axis
  	Wire.requestFrom(address, 6);
  	if(6<=Wire.available()){
    	x = Wire.read()<<8; //X msb
    	x |= Wire.read(); //X lsb
    	z = Wire.read()<<8; //Z msb
    	z |= Wire.read(); //Z lsb
    	y = Wire.read()<<8; //Y msb
  		y |= Wire.read(); //Y lsb
  	}
  	
	heading=atan2(y,x);
  	if (heading<0){ heading += 2*PI; }
  	heading = heading * 180.0/PI;
  	return heading = int(heading + declination)%360;
}

