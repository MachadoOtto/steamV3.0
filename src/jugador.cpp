/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Baladon 
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "../include/jugador.h"
#include <string>

Jugador::Jugador(std::string nick, int age, std::string passwd){
    nickname = nick;
    edad = age;
    contrasena = passwd;
}

DtJugador Jugador::getDt(){
    DtJugador pkg(nickname,edad);
    return pkg;
}