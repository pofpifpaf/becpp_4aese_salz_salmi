#include "Proximity.h"

Proximity::Proximity(uint8_t pin, float mL, float mH) 
	: Sensor("Distance", "D", "cm", mL, mH)
	, ultrasonic(pin)
{
}


Proximity::Proximity(uint8_t pin) 
	: Sensor("Distance", "D", "cm")
	, ultrasonic(pin)
{
}

float Proximity::getValue() 
{
	float buff = ultrasonic.MeasureInCentimeters();
	//history.push_back(buff);
	return buff; 
}

