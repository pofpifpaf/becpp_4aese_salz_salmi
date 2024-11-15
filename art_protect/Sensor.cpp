#include "Sensor.h"

int Sensor::nbSensors = 0;

Sensor::Sensor()
 : marginLow(-1)
 , marginHigh(-1)
{
}

Sensor::Sensor(long mL, long mH)
 : marginLow(mL)
 , marginHigh(mH)
{
}

long Sensor::operator[](int i)
{
	// if (i < 0 && i >= history.size()) throw ERR_OUT_OF_RANGE;
	 
	return history[i];
}


bool Sensor::isOutOfMargin()
{
	// if (marginLow == -1 && marginHigh == -1) throw MARGINS_UNDEFINED; 
	long buff = getValue();
	return buff < marginLow || buff > marginHigh;
}
