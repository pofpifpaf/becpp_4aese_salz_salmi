#include "Proximity.h"

Proximity::Proximity(uint8_t pin, float mL, float mH) 
	: Sensor("Distance", "D", "cm", mL, mH)
	, ultrasonic(pin)
{
	nbSensors++;
}


Proximity::Proximity(uint8_t pin) 
	: Sensor("Distance", "D", "cm")
	, ultrasonic(pin)
{
	nbSensors++;
}

float Proximity::getValue()
{
	float buff = ultrasonic.MeasureInCentimeters();
	//history.push_back(buff);
	return buff; 
}

