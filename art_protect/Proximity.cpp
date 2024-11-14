#include "Proximity.h"

Proximity::Proximity(uint8_t pin, long mH, long mL) 
	: ultrasonic(pin)
	, marginHigh(mH)
	, marginLow(mL)
{
	nbSensors++;
}

long Proximity::getValue() 
{
	long buff = ultrasonic.MeasureInCentimeters();
	history.push_back(buff);
	return buff; 
}

bool Proximity::isOutOfMargin()
{
	long buff = getValue();
	return buff < marginLow || buff > marginHigh;
}

long Proximity::operator[](int i)
{
	if (i < 0 && i >= history.size()) {
		throw ERR_OUT_OF_RANGE;
	} 

	return history[i];
}
