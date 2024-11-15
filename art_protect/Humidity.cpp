#include "Humidity.h"

Humidity::Humidity()
	: Sensor()
{
	Wire.begin();
	Wire.setClock(100000);
	
	sht31.begin();
}

Humidity::Humidity(float mL, float mH)
	: Sensor(mL, mH)
{
	Wire.begin();
	Wire.setClock(100000);
	
	sht31.begin();
}

float Humidity::getValue()
{
	sht31.read();
	float buff = sht31.getHumidity();
	history.push_back(buff);
	return buff;
}