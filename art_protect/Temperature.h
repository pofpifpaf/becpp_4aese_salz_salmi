#ifndef TEMPERATURE_HUMIDITY_H
#define TEMPERATURE_HUMIDITY_H

#include "Sensor.h"
#include "SHT31.h"
#include "Wire.h"


class Temperature : public Sensor
{
private :
	SHT31 sht31;

public :
	Temperature(float mL, float mH);
	Temperature();

	float getValue();
};

#endif
