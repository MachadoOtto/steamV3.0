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

LaFabrica LaFabrica::getInstance(){
    static LaFabrica instancia();
    return &instancia;
}

IIFPartidas * LaFabrica::getIIFPartidas(){
  IFPartidasController * IFP = IFPartidas::getInstance();
  return IFP; 
}

IVideojuego * LaFabrica::getIVideojuego(){
   videojuegoController * vj = videojuegoController::getInstance();
   return vj;
}

IAltaUsuario * LaFabrica::getIAltaUSuario(){
   altaUsuarioController * au = altaUSuarioController::getInstance();
   return au;  
}
