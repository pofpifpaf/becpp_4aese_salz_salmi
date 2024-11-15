/*********************************************************************
 * @file  Apllication.cpp
 * @author LahnM, Adam S.
 * @brief Fichier source de l'application
 *********************************************************************/
#include "Application.h"

Ticker TimerUpdateScreen;
Ticker TimerMeasurmentsTaking;

Proximity Application::prox(D5, 14, 300);
Temperature Application::temp(0, 100);
Humidity Application::hum(0, 100);
Screen Application::screen;

Application::Application()
{
}
  
Application::~Application()
{
  // Code
  ;
}  

void Application::init(void)
{
  Serial.begin(9600);
  TimerUpdateScreen.attach(0.5, Application::updateScreen);
  TimerMeasurmentsTaking.attach(0.1, Application::sensorsMonitoring);
}


void Application::run(void)
{
  
}


void Application::updateScreen()
{
  if (!prox.getAcknowledgement()) {
        screen.displayAlert(prox);
    } else if (!temp.getAcknowledgement()) {
        screen.displayAlert(temp);
    } else if (!hum.getAcknowledgement()) {
        screen.displayAlert(hum);
    } else {
        screen.refreshScreen(prox, temp, hum);
    }
    Serial.println("J'ai update le screen");
}

void Application::sensorsMonitoring()
{
  if (prox.isOutOfMargin() && prox.getAcknowledgement() == true) {
    Serial.println("Prox out of margin");
    prox.setAcknowledgement(false);
  } else if (temp.isOutOfMargin() && temp.getAcknowledgement() == true) {
    temp.setAcknowledgement(false);
  } else if (hum.isOutOfMargin() && hum.getAcknowledgement() == true) {
    hum.setAcknowledgement(false);
  }
}