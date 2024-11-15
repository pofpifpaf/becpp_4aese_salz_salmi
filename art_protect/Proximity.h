#ifndef PROXIMITY_HPP
#define PROXIMITY_HPP

#include "Sensor.h"
#include "Ultrasonic.h"

class Proximity : public Sensor
{
private : 
	Ultrasonic ultrasonic;

public:
	Proximity(uint8_t pin, long mL, long mH);
	Proximity(uint8_t pin);

	long getValue();

	long operator[](int i);
};

#endif