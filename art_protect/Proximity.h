#ifndef PROXIMITY_H
#define PROXIMITY_H

#include "Sensor.h"
#include "Ultrasonic.h"

class Proximity : public Sensor
{
private : 
	Ultrasonic ultrasonic;

public:
	Proximity(uint8_t pin, float mL, float mH);
	Proximity(uint8_t pin);

	float getValue();

};

#endif