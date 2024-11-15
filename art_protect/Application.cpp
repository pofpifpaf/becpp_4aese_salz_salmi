/*********************************************************************
 * @file  Apllication.cpp
 * @author LahnM, Adam S.
 * @brief Fichier source de l'application
 *********************************************************************/
#include "Application.h"

Application::Application()
  : prox(D5, 14, 120)
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
  Serial.print("Distance : ");
  Serial.println(prox.getValue());
  delay(1000);
  Serial.print(" Depasse : ");
  Serial.println(prox.isOutOfMargin());
  delay(1000);
  Serial.print("Last value : ");
  Serial.println(prox[0]);
  
}
