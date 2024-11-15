#include "Sensor.h"

int Sensor::nbSensors = 0;

Sensor::Sensor(String n, String ab, String u)
 : name(n)
 , abbreviation(ab)
 , unit(u)
 , marginLow(-1)
 , marginHigh(-1)
{
}

Sensor::Sensor(String n, String ab, String u, float mL, float mH)
 : name(n)
 , abbreviation(ab)
 , unit(u) 
 , marginLow(mL)
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

String Sensor::getName()
{
	return name;
}

String Sensor::getAbbreviation()
{
	return abbreviation;
}

String Sensor::getUnit()
{
	return unit;
}


bool Sensor::isOutOfMargin()
{
	// if (marginLow == -1 && marginHigh == -1) throw MARGINS_UNDEFINED; 
	float buff = getValue();
	return buff < marginLow || buff > marginHigh;
}
