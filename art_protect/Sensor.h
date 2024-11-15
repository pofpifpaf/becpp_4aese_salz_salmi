#ifndef SENSOR_H
#define SENSOR_H

#define ERR_OUT_OF_RANGE 1;

#include <vector>

class Sensor 
{
protected :
	std::vector<float> history;

	float marginHigh;
	float marginLow;

	static int nbSensors; 

public :
	virtual float getValue() = 0;
	
	float operator[](int i);
	int getHistorySize();

	Sensor();
	Sensor(float mL, float mH);

	bool isOutOfMargin();

};

#endif
