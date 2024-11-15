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

    void refreshSensor(Sensor& sens, int x, int y);

public :
	Screen();

    void refreshScreen(Proximity& prox, Temperature& temp, Humidity& hum);

    void displayAlert(Sensor& sens);

};

#endif
