/*********************************************************************
 * @file  Apllication.cpp
 * @author LahnM, Adam S.
 * @brief Fichier source de l'application
 *********************************************************************/
#include "Application.h"

Ticker TimerUpdateScreen;
Ticker TimerMeasurmentsTaking;

Proximity Application::prox(D5, 15, 300);
Temperature Application::temp(15, 20);
Humidity Application::hum(0, 100);
Screen Application::screen();

Application::Application()
{
}
  
Application::~Application()
{
}  

void Application::init(void)
{
  Serial.begin(9600);
  TimerUpdateScreen.attach(0.5, Application::updateScreen);
  TimerMeasurmentsTaking.attach(0.1, Application::sensorsMonitoring);
}


void Application::run(void)
{
  if (Serial.available())
  {
    String command = Serial.readString();
    command.trim();
    Serial.print("Command received : ");
    Serial.println(command);
    
    //tout cela est temporaire non ?
    if (command == "-ack_prox") {
      prox.setAcknowledgement(true);
      Serial.println("Prox acknowledged");
    } else if (command == "-ack_temp") {
      temp.setAcknowledgement(true);
      Serial.println("Temp acknowledged");
    } else if (command == "-ack_hum") {
      hum.setAcknowledgement(true);
      Serial.println("Hum acknowledged");
    } else {
      Serial.println("Command unknown");
    }
  }
}


void Application::updateScreen()
{
  if (prox.getAlert()) {
    screen.displayAlert(prox);
  } else if (temp.getAlert()) {
    screen.displayAlert(temp);
  } else if (hum.getAlert()) {
    screen.displayAlert(hum);
  } else {
    screen.refreshScreen(prox, temp, hum);
  }
}

void Application::sensorMonitor(Sensor& sens)
{
  sens.setAlert(sens.isOutOfMargin() || (!sens.getAcknowledgement() && sens.getAlert()));
  sens.setAcknowledgement(false);
}

void Application::sensorsMonitoring()
{
  sensorMonitor(prox);
  sensorMonitor(hum);
  sensorMonitor(temp);
}