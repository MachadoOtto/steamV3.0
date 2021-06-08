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

class laFabrica{
private:
   laFabrica instancia;
   laFabrica();

public:
   IVideojuego getIVideojuego();
   IIFPartidas getIIFPartidas();
   IAltaUsuario getIAltaUsuario(); 
};

#endif
