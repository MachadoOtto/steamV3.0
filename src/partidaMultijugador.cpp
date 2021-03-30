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
    int i=0;
    ListaJugador * inv = invitados;
    while(inv != nullptr){
	inv = inv->next();
	i++;
    }
    inv = invitados;
    i++;
    std::string * ark = new std::string[i];
    for(int k=1;k<i;k++){
	ark[k] = inv->getJugador()->getDt().getNickname();
	inv = inv->next();
    }
    ark[0] = this->getHost()->getDt().getNickname();
    DtPartidaMultijugador * pkg = new DtPartidaMultijugador(transmitidaEnVivo,ark,i,this->getFecha(),this->getDuracion());
    return pkg;
}

