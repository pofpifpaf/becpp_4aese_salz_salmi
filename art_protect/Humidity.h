#ifndef HUMIDITY_H
#define HUMIDITY_H

#include "Sensor.h"
#include "SHT31.h"
#include "Wire.h"


class Humidity : public Sensor
{
private :
	SHT31 sht31;

public :
	Humidity(float mL, float mH);
	Humidity();

	float getValue();
};

#endif
