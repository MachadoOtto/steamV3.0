/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Implementacion de clase 
 * Autores (por nombre):
 * 	Alexis Ramilo
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "../include/partida.h"
#include "../include/jugador.h"

Partida::Partida(DtFechaHora d, float f, Jugador * p){
    fecha = d;
    duracion = f;
    host = p;
}

PartidaIndividual::PartidaIndividual(bool b,DtFechaHora d, float f, Jugador * p):
    Partida(d,f,p){
    continuarPartidaAnterior = b;
}

float PartidaIndividual::darTotalHorasParticipantes(){
    return duracion;
}

DtPartidaIndividual PartidaIndividual::getDt(){
    DtPartidaIndividual pkg(fecha,duracion,continuarPartidaAnterior);
    return pkg;


