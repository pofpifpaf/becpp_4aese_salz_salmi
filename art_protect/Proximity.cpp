#include "Proximity.h"

Proximity::Proximity(uint8_t pin, float mL, float mH) 
	: Sensor(mL, mH)
	, ultrasonic(pin)
{
	nbSensors++;
}


Proximity::Proximity(uint8_t pin) 
	: Sensor()
	, ultrasonic(pin)
{
	nbSensors++;
}

float Proximity::getValue() 
{
	float buff = ultrasonic.MeasureInCentimeters();
	history.push_back(buff);
	return buff; 
}

