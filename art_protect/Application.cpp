/*********************************************************************
 * @file  Apllication.cpp
 * @author LahnM, Adam S.
 * @brief Fichier source de l'application
 *********************************************************************/
#include "Application.h"
#include "SHT31.h"
#include "Wire.h"


Application::Application()
  : prox(D5, 14, 300)
  , temp(0, 100)
  , hum(0, 100)
  , screen()
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
}


void Application::run(void)
{
  // Serial.print("Distance : ");
  // Serial.println(prox.getValue());
  // delay(1000);
  // Serial.print(" Depasse : ");
  // Serial.println(prox.isOutOfMargin());
  // delay(1000);
  // Serial.print("Last value : ");
  // Serial.println(prox[0]);

  // Serial.print("Temp = "); 
  // Serial.print(temp.getValue());
  // Serial.println(" C"); //The unit for  Celsius because original arduino don't support speical symbols
  // Serial.print("Hum = "); 
  // Serial.print(hum.getValue());
  // Serial.println("%"); 
  // Serial.println();
  // delay(1000);

  screen.refreshScreen(prox, temp, hum);
  delay(5000);
  screen.displayAlert(prox);
  delay(5000);

  
}
