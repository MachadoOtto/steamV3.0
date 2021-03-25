/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Baladón
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "../include/dtPartidaIndividual.h"
#include "../include/dtPartida.h"
#include "../include/PartidaIndividual.h"
#include <iostream>
#include <string.h>

DtPartidaIndividual::DtPartidaIndividual(bool b,DtFechaHora d, float f):
    DtPartida(d,f){
    continuaPartidaAnterior = b;
}

bool DtPartidaIndividual::getContinuaPartidaAnterior(){
    return continuaPartidaAnterior;
}

static Jugador * findJugador(std::string nombre,ListaJugador * jugadores) {
    ListaJugador * list_player = jugadores;
    while (list_player != nullptr) {
        if (nombre == ( (list_player->getJugador()->getDt()).getNickname()))
            return list_player->getJugador(); 
	list_player = list_player->next();
    }
    return nullptr; 
}

Partida * DtPartidaIndividual::fabricarPartida(Jugador * host, ListaJugador * invitees){
    Partida * p = new PartidaIndividual(this->getContinuaPartidaAnterior(),this->getFecha(),this->getDuracion(),host);
    return p;
}

std::ostream &operator <<(std::ostream &o, DtPartidaIndividual &pInd) {

    std::string siNo = "Si";
    if(pInd.getContinuaPartidaAnterior()) siNo = "No";
    DtFechaHora auxFecha = pInd.getFecha();

    o << "Tipo Partida: Individual" << std::endl;
     o << "Fecha partida:" << auxFecha.getDia() << "/" << auxFecha.getMes() << "/" << auxFecha.getAnio() << std::endl;
    o << "Duración partida:" << auxFecha.getHora() << "/" << auxFecha.getMinuto() << std::endl;
    o << "Continuación de una partida anterior: " << siNo << std::endl;

    return o;
}