#ifndef SENSOR_HPP
#define SENSOR_HPP

#define ERR_OUT_OF_RANGE 1;

#include <vector>

class Sensor 
{
protected :
	std::vector<long> history;

	static int nbSensors; 

public :
	virtual long getValue() = 0;
	
	// Sensor(); 

	long operator[](int i);
};



#endif
