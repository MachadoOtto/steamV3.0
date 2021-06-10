/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - 
 * Autores (por nombre):
 * 	Alexis Baladon 
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */
#ifndef LAFABRICA
#define LAFABRICA

#include <string>
#include "iAltaUsuarioController.h"
#include "altaUsuarioController.h"
#include "iIFPController.h"
#include "iFPController.h"
#include "iVideojuegoController.h"
#include "videojuegoController.h"

class LaFabrica{
private:
   LaFabrica(){};
public:
   static LaFabrica * getInstance();
   IVideojuegoController *getIVideojuegoController();
   IIFPController *getIIFPController();
   IAltaUsuarioController *getIAltaUsuarioController(); 
};

#endif
