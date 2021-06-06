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

laFabrica::laFabrica(){
   instancia = new laFabrica();
}

laFabrica laFabrica::getInstance(){
   if (instancia == NULL) 
      instancia = new laFabrica;
   return instancia;
}

IIFPartidas * laFabrica::getIIFPartidas(){
  IFPartidasController * IFP = IFPartidas::getInstance();
  return IFP; 
}

IVideojuego * laFabrica::getIVideojuego(){
   videojuegoController * vj = videojuegoController::getInstance();
   return vj;
}

IAltaUsuario * laFabrica::getIAltaUSuario(){
   altaUsuarioController * au = altaUSuarioController::getInstance();
   return au;  
}
