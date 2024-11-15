/*********************************************************************
 * @file  Apllication.cpp
 * @author LahnM, Adam S.
 * @brief Fichier source de l'application
 *********************************************************************/
#include "Application.h"

Ticker TimerUpdateScreen;
Ticker TimerMeasurmentsTaking;

Proximity Application::prox(D5, 5, 300);
Temperature Application::temp(15, 21);
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
  if (prox.getAlert() && !prox.getAcknowledgement()) {
        screen.displayAlert(prox);
    } else if (temp.getAlert() && !temp.getAcknowledgement()) {
        screen.displayAlert(temp);
    } else if (hum.getAlert() && !hum.getAcknowledgement()) {
        screen.displayAlert(hum);
    } else {
        screen.refreshScreen(prox, temp, hum);
    }
    Serial.println("J'ai update le screen");
}

void Application::sensorsMonitoring()
{
  bool buff_prox = prox.isOutOfMargin();
  if (buff_prox && prox.getAcknowledgement() == false) {
    Serial.println("Prox out of margin");
    prox.setAlert(true);
  } else if (buff_prox && prox.getAcknowledgement() == true) {
    prox.setAlert(false);
  } else
  {
    prox.setAcknowledgement(false);
  }
  
  bool buff_temp = temp.isOutOfMargin();
  if (buff_temp && temp.getAcknowledgement() == false) {
    Serial.println("Temp out of margin");
    temp.setAlert(true);
  } else if (buff_temp && temp.getAcknowledgement() == true) {
    temp.setAlert(false);
  } else
  {
    temp.setAcknowledgement(false);
  }

  bool buff_hum = hum.isOutOfMargin();
  if (buff_hum && hum.getAcknowledgement() == false) {
    Serial.println("Hum out of margin");
    hum.setAlert(true);
  } else if (buff_hum && hum.getAcknowledgement() == true) {
    hum.setAlert(false);
  } else
  {
    hum.setAcknowledgement(false);
  }
}