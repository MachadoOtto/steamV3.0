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

float Partida::getDuracion(){
    return duracion;
}

DtFechaHora Partida::getFecha(){
    return fecha;
}

PartidaIndividual::PartidaIndividual(bool b,DtFechaHora d, float f, Jugador * p):
    Partida(d,f,p){
    continuarPartidaAnterior = b;
}

float PartidaIndividual::darTotalHorasParticipantes(){
    return duracion;
}

DtPartidaIndividual PartidaIndividual::getDt(){
    DtPartidaIndividual pkg(continuarPartidaAnterior,fecha,duracion);
    return pkg;
}

PartidaMultijugador::PartidaMultijugador(bool b,DtFechaHora d, float f, Jugador * p, ListaJugador * l):
    Partida(d,f,p){
    transmitidaEnVivo = b;
    invitados = l;
}

float PartidaMultijugador::darTotalHorasParticipantes(){
    int cantidad=0;
    ListaJugador * inv = invitados;
    while(inv != nullptr){
	cantidad++;
	inv = inv.next();
    }
    return this->getDuracion()*(cantidad+1); //+1 para incluir al host. 
}

DtPartidaMultijugador PartidaMultijugador::getDt(){
    DtPartidaMultijugador pkg(transmitidaEnVivo,invitados,this->getFecha(),this->getDuracion());
    return pkg;
}

DtPartida::DtPratida(DtFechaHora d,float f){
    fecha =d;
    duracion=f;
}
DtFechaHora DtPartida::getFecha(){
    return fecha;
}
float DtPartida::getDuracion(){
    return duracion;
}

DtPartidaIndividual::DtPartidaIndividual(bool b,DtFechaHora d, float f):
    DtPartida(d,f){
    continuaPartidaAnterior = b;
}

bool DtPartidaIndividual::getContinuaPartidaAnterior(){
    return continuaPartidaAnterior;
}

DtPartidaMultijugador::DtPartidaMultijugador(bool b, ListaJugador * pp, DtFechaHora d, float f): DtPartida(d,f){
    transmitidaEnVivo = b;
    
