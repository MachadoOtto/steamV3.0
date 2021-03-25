/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Baladon 
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "../include/partidaIndividual.h"
#include "../include/dtPartidaIndividual.h"

PartidaIndividual::PartidaIndividual(bool b,DtFechaHora d, float f, Jugador * p):
    Partida(d,f,p){
    continuarPartidaAnterior = b;
}

float PartidaIndividual::darTotalHorasParticipantes(){
    return this->getDuracion();
}

DtPartida * PartidaIndividual::getDt(){
    DtPartidaIndividual *pkg = new DtPartidaIndividual(continuarPartidaAnterior,this->getFecha(),this->getDuracion());
    return pkg;
}