#ifndef SENSOR_HPP
#define SENSOR_HPP

#define ERR_OUT_OF_RANGE 1;

#include <vector>

class Sensor 
{
protected :
	std::vector<long> history;

	long marginHigh;
	long marginLow;

	static int nbSensors; 

public :
	virtual long getValue() = 0;
	
	long operator[](int i);

	Sensor();
	Sensor(long mL, long mH);

	bool isOutOfMargin();

};

#endif
