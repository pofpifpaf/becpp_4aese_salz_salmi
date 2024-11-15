#include "Screen.h"


Screen::Screen()
    : lcd()
    , alert(false)
{
    lcd.begin(20, 2);
    lcd.setRGB(0, 255, 0);
}

bool Screen::checkAlert(Sensor& sens)
{
    if(alert = sens.isOutOfMargin())
    {
        lcd.clear();
        lcd.setRGB(255, 0, 0);
        lcd.setCursor(0, 0);
        lcd.print("ALERT ");
        lcd.setCursor(6, 0);
        lcd.print(sens.getName());
    }

    return alert;
}

void Screen::refreshSensor(Sensor& sens, int x, int y)
{
    if (!alert)
    {
        if (!checkAlert(sens)) {
            lcd.setCursor(x, y);
            lcd.print(sens.getAbbreviation() + ":" + sens.getValue() + sens.getUnit() + ".");
        }
    }
}

void Screen::refreshScreen(Proximity& prox, Temperature& temp, Humidity& hum)
{
    //lcd.clear();
    refreshSensor(prox, 0, 0);
    refreshSensor(temp, 0, 1);
    refreshSensor(hum, 8, 1);
}
