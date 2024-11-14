/*********************************************************************
 * @file  Apllication.cpp
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier source de l'application
 *********************************************************************/
#include "Application.h"

Application::Application()
  : prox(D5, 120, 14)
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
  Serial.print("Distance : " + prox.getValue());
  Serial.print(" Depasse : " + prox.isOutOfMargin());
  Serial.println("Last value : " + prox[0]);
}
