#include "Sensor.h"

int Sensor::nbSensors = 0;

Sensor::Sensor()
 : marginLow(-1)
 , marginHigh(-1)
{
}

Sensor::Sensor(float mL, float mH)
 : marginLow(mL)
 , marginHigh(mH)
{
}

float Sensor::operator[](int i)
{
	// if (i < 0 && i >= history.size()) throw ERR_OUT_OF_RANGE;

	return history[i];
}

int Sensor::getHistorySize()
{
	return history.size();
}


bool Sensor::isOutOfMargin()
{
	// if (marginLow == -1 && marginHigh == -1) throw MARGINS_UNDEFINED; 
	float buff = getValue();
	return buff < marginLow || buff > marginHigh;
}
