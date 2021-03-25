/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Baladon 
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "../include/dtPartida.h"

DtPartida::DtPartida(DtFechaHora d,float f):
    fecha(d){
    duracion=f;
}

DtFechaHora DtPartida::getFecha(){
    return fecha;
}

float DtPartida::getDuracion(){
    return duracion;
}