/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4
 * Autores (por nombre):
 * 	Alexis Baladon 
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "../include/laFabrica.h"

LaFabrica *LaFabrica::getInstance(){
    static LaFabrica instancia;
    return &instancia;
}

IIFPController * LaFabrica::getIIFPController(){
  IFPController * IFP = IFPController::getInstance();
  return IFP; 
}

IVideojuegoController * LaFabrica::getIVideojuegoController(){
   IVideojuegoController * vj = VideojuegoController::getInstance();
   return vj;
}

IAltaUsuarioController * LaFabrica::getIAltaUsuarioController(){
   IAltaUsuarioController * au = AltaUsuarioController::getInstance();
   return au;  
}
