#include "Sensor.h"

int Sensor::nbSensors = 0;

long Sensor::operator[](int i)
{
	if (i < 0 && i >= history.size()) {
		throw ERR_OUT_OF_RANGE;
	} 

	return history[i];
}