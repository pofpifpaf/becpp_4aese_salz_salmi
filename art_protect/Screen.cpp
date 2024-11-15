#include "Screen.h"


Screen::Screen()
    : lcd()
{
    lcd.begin(16, 2);
    lcd.setRGB(0, 255, 0);
}

void Screen::refreshSensor(Sensor& sens, int x, int y)
{
    lcd.setRGB(0, 255, 0);
    lcd.setCursor(x, y);
    lcd.print(sens.getAbbreviation() + ":" + sens.getValue() + sens.getUnit() + ".");
}

void Screen::refreshScreen(Proximity& prox, Temperature& temp, Humidity& hum)
{
    lcd.clear();
    refreshSensor(prox, 0, 0);
    refreshSensor(temp, 0, 1);
    refreshSensor(hum, 8, 1);
}

void Screen::displayAlert(Sensor& sens)
{
    lcd.clear();
    lcd.setRGB(255, 0, 0);
    lcd.setCursor(0, 0);
    lcd.print("ALERT " + sens.getName());
    lcd.setCursor(0, 1);
    lcd.print(sens.getAbbreviation() + ":" + sens.getValue() + sens.getUnit() + ".");
}