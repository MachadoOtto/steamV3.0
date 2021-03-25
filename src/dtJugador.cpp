/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Baladon 
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "../include/dtJugador.h"
#include <string>

DtJugador::DtJugador(std::string n, int e){
   nickname = n;
   edad = e;
}

std::string DtJugador::getNickname(){
    return nickname;
}

int DtJugador::getEdad(){
    return edad;
}