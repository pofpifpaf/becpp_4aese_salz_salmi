#include "Proximity.h"

Proximity::Proximity(uint8_t pin, long mL, long mH) 
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

long Proximity::getValue() 
{
	long buff = ultrasonic.MeasureInCentimeters();
	history.push_back(buff);
	return buff; 
}

long Proximity::operator[](int i)
{
	if (i < 0 && i >= history.size()) {
		throw ERR_OUT_OF_RANGE;
	} 

	return history[i];
}
