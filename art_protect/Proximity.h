#ifndef PROXIMITY_HPP
#define PROXIMITY_HPP

#include "Sensor.h"
#include "Ultrasonic.h"

class Proximity : public Sensor
{
private : 
	Ultrasonic ultrasonic;
	long marginHigh;
	long marginLow;

public:
	Proximity(uint8_t pin, long mH, long mL);

	long getValue();

	bool isOutOfMargin();

	long operator[](int i);


};




#endif