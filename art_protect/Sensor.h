#ifndef SENSOR_H
#define SENSOR_H

#define ERR_OUT_OF_RANGE 1;

#include <vector>
#include <Arduino.h>

class Sensor 
{
protected :
	std::vector<float> history;

	float marginHigh;
	float marginLow;

	String name;
	String abbreviation;
	String unit;

	static int nbSensors; 

public :
	virtual float getValue() = 0;
	
	float operator[](int i);
	int getHistorySize();

	Sensor(String n, String ab, String u);
	Sensor(String n, String ab, String u, float mL, float mH);

	String getName();
	String getAbbreviation();
	String getUnit();

	bool isOutOfMargin();

};

#endif
