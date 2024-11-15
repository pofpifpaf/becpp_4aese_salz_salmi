#ifndef SCREEN_H
#define SCREEN_H

#include <Wire.h>
#include "rgb_lcd.h"
#include "Temperature.h"
#include "Humidity.h"
#include "Proximity.h"


class Screen 
{
protected :
    rgb_lcd lcd;

    bool alert;

public :
	Screen();

    bool checkAlert(Sensor& sens);

    void refreshSensor(Sensor& sens, int x, int y);

    void refreshScreen(Proximity& prox, Temperature& temp, Humidity& hum);

};

#endif
