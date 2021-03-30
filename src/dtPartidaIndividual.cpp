/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Baladon 
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "../include/dtPartidaIndividual.h"
#include "../include/dtPartida.h"
#include "../include/partidaIndividual.h"
#include "../include/listaJugador.h"
#include <iostream>
#include <string.h>

DtPartidaIndividual::DtPartidaIndividual(bool b,DtFechaHora d, float f):
    DtPartida(d,f){
    continuaPartidaAnterior = b;
}

bool DtPartidaIndividual::getContinuaPartidaAnterior(){
    return continuaPartidaAnterior;
}

Partida * DtPartidaIndividual::fabricarPartida(Jugador * host, ListaJugador * invitees){
    Partida * p = new PartidaIndividual(this->getContinuaPartidaAnterior(),this->getFecha(),this->getDuracion(),host);
    return p;
}

std::ostream &operator<<(std::ostream &o, DtPartidaIndividual & pInd) {
    std::string siNo = "No";
    if(pInd.continuaPartidaAnterior) 
        siNo = "Si";
    DtFechaHora auxFecha = pInd.fecha;
    o << "Tipo Partida: Individual" << std::endl;
    o << "Fecha partida: " << auxFecha.getDia() << "/" << auxFecha.getMes() << "/" << auxFecha.getAnio() << "  " << auxFecha.getHora() << ":" << auxFecha.getMinuto() << std::endl;
    o << "Duración partida: " << pInd.getDuracion() << " hs" << std::endl;
    o << "Continuación de una partida anterior: " << siNo << std::endl;
    return o;
}
