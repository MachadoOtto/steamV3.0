/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Baladon 
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "../include/partidaMultijugador.h"
#include "../include/dtPartidaMultijugador.h"

PartidaMultijugador::PartidaMultijugador(bool b,DtFechaHora d, float f, Jugador * p, ListaJugador * l):
    Partida(d,f,p){
    transmitidaEnVivo = b;
    invitados = l;
}

PartidaMultijugador::~PartidaMultijugador(){
    delete invitados;
}

float PartidaMultijugador::darTotalHorasParticipantes(){
    int cantidad=0;
    ListaJugador * inv = invitados;
    while(inv != nullptr){
	cantidad++;
	inv = inv->next();
    }
    return this->getDuracion()*(cantidad+1); //+1 para incluir al host. 
}

DtPartida * PartidaMultijugador::getDt(){
    DtPartidaMultijugador * pkg = new DtPartidaMultijugador(transmitidaEnVivo,invitados,this->getFecha(),this->getDuracion());
    return pkg;
}