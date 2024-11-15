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
  if (Serial.available()) {
    String commande = Serial.readString();
    commande.trim();
    Serial.print("Command received : ");
    Serial.println(commande);
    
    if (commande == "-ack_prox") {
      prox.setAcknowledgement(true);
      Serial.println("Prox acknowledged");
    } else if (commande == "-ack_temp") {
      temp.setAcknowledgement(true);
      Serial.println("Temp acknowledged");
    } else if (commande == "-ack_hum") {
      hum.setAcknowledgement(true);
      Serial.println("Hum acknowledged");
    } else {
      Serial.println("Command unknown");
    }
  }
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
}

void Application::sensorsMonitoring()
{
  bool buff_prox = prox.isOutOfMargin();
  if (buff_prox) { 
      // If outside margins, activate alert
      Serial.println("Prox out of margin");
      prox.setAlert(true); 
  } else if (!buff_prox && prox.getAcknowledgement() == false && prox.getAlert() == true) {
      // If in margins but ack is still false, keep alert enabled
      prox.setAlert(true);
  } else if (!buff_prox && prox.getAcknowledgement() == true) {
      // If in margins and ack is true, disable alert and reset acknowledgment
      prox.setAlert(false);
      prox.setAcknowledgement(false);
  }
  
  bool buff_temp = temp.isOutOfMargin();
  if (buff_temp) { 
      // If outside margins, activate alert
      Serial.println("Temp out of margin");
      temp.setAlert(true); 
  } else if (!buff_temp && temp.getAcknowledgement() == false && temp.getAlert() == true) {
      // If in margins but ack is still false, keep alert enabled
      temp.setAlert(true);
  } else if (!buff_temp && temp.getAcknowledgement() == true) {
      // If in margins and ack is true, disable alert and reset acknowledgment
      temp.setAlert(false);
      temp.setAcknowledgement(false);
  }

  bool buff_hum = hum.isOutOfMargin();
  if (buff_hum) { 
      // If outside margins, activate alert
      Serial.println("Hum out of margin");
      hum.setAlert(true); 
  } else if (!buff_hum && hum.getAcknowledgement() == false && hum.getAlert() == true) {
      // If in margins but ack is still false, keep alert enabled
      hum.setAlert(true);
  } else if (!buff_hum && hum.getAcknowledgement() == true) {
      // If in margins and ack is true, disable alert and reset acknowledgment
      hum.setAlert(false);
      hum.setAcknowledgement(false);
  }
}