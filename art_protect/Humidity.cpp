#include "Humidity.h"

Humidity::Humidity()
	: Sensor("Humidity", "H", "%")
{
	Wire.begin();
	Wire.setClock(100000);
	
	sht31.begin();
}

Humidity::Humidity(float mL, float mH)
	: Sensor("Humidity", "H", "%", mL, mH)
{
	Wire.begin();
	Wire.setClock(100000);
	
	sht31.begin();
}

float Humidity::getValue()  
{
	sht31.read();
	float buff = sht31.getHumidity();
	//history.push_back(buff);
	return buff;
}