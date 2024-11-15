/*********************************************************************
 * @file  Apllication.h
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier header de l'application
 *********************************************************************/
#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "Proximity.h"
#include "Temperature.h"
#include "Humidity.h"
#include "Screen.h"
#include "SHT31.h"
#include "Wire.h"
#include <Ticker.h>


/**
  * @class Application
  * @brief Classe Application 
*/    
class Application
{
  private: 
    static Proximity prox;
    static Temperature temp;
    static Humidity hum;
    static Screen screen;

  public :


    /**
     * @fn Application();
     * @brief Constructeur par defaut
    */    
    Application();
    /**
     * @fn Application();
     * @brief Destructeur
    */    
    ~Application();    
    /**
     * @fn void init(void)
     * @brief Fonction d'initialisation de l'application
    */
    void init(void);
    /**
     * @fn void run(void)
     * @brief Fonction de lancement de l'application
    */
    void run(void);

    static void updateScreen();

    static void sensorsMonitoring();
};
#endif