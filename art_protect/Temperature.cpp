#include "Temperature.h"

Temperature::Temperature()
	: Sensor()
{
	Wire.begin();
	Wire.setClock(100000);
	
	sht31.begin();
}

Temperature::Temperature(float mL, float mH)
	: Sensor(mL, mH)
{
	Wire.begin();
	Wire.setClock(100000);
	
	sht31.begin();
}

float Temperature::getValue()
{
	sht31.read();
	float buff = sht31.getTemperature();
	history.push_back(buff);
	return buff;
}