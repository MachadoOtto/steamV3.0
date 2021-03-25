/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Baladón
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "../include/partida.h"

//#include "../include/jugador.h"
#include <iostream>
#include <string.h>

Partida::Partida(DtFechaHora d, float f, Jugador * p):
fecha(d){
    duracion = f;
    host = p;
}

float Partida::getDuracion(){
    return duracion;
}

DtFechaHora Partida::getFecha(){
    return fecha;
}