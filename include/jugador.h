/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Baladon 
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef JUGADOR
#define JUGADOR

#include <string>
#include "dtJugador.h"

class Jugador{
private:
    std::string nickname;
    int edad;
    std::string contrasena;
public:
    Jugador(std::string,int,std::string);
    DtJugador getDt();
};

#endif