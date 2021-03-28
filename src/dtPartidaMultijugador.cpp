/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Baladon 
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "../include/dtPartidaMultijugador.h"
#include "../include/dtPartida.h"
#include "../include/listaJugador.h"
#include "../include/partidaMultijugador.h"
#include <iostream>
#include <string>

DtPartidaMultijugador::DtPartidaMultijugador(bool b, std::string * pp,int card, DtFechaHora d, float f): DtPartida(d,f){
    transmitidaEnVivo = b;
    cantidadJugadoresUnidos = card;
    nicknameJugadoresUnidos = pp;
} 

std::string * DtPartidaMultijugador::getNicknameJugadoresUnidos(){
    return nicknameJugadoresUnidos;
}

int DtPartidaMultijugador::getCantidadJugadoresUnidos(){
    return cantidadJugadoresUnidos;
}

bool DtPartidaMultijugador::getTransmitidaEnVivo(){
    return transmitidaEnVivo;
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

//Limitacion: El nickname de un usuario no puede contener comas.
Partida * DtPartidaMultijugador::fabricarPartida(Jugador * host, ListaJugador * jugadoresSystema){
    ListaJugador * invitees = nullptr;
    int tot = this->getCantidadJugadoresUnidos();
    for(int i=0;i<tot;i++){
	Jugador * p = findJugador(this->getNicknameJugadoresUnidos()[i],jugadoresSystema);
	if(p == nullptr)
	    throw std::invalid_argument("Uno de los jugadores invitados a la partida no se encuentra registrado.");
	if(invitees == nullptr)
	    invitees = new ListaJugador(p);
	else
	    invitees->add(p);
    }
    Partida * p = new PartidaMultijugador(this->transmitidaEnVivo,this->getFecha(),this->getDuracion(),host,invitees);
    return p;
}

std::ostream &operator<<(std::ostream& o, DtPartidaMultijugador const& pMult){
    std::string siNo = "Si";
    if(pMult.transmitidaEnVivo) 
        siNo = "No";
    DtFechaHora auxFecha = pMult.fecha;
    int cantJug = pMult.cantidadJugadoresUnidos;
    o << "Tipo Partida: Multijugador" << std::endl; 
    o << "Fecha partida:" << auxFecha.getDia() << "/" << auxFecha.getMes() << "/" << auxFecha.getAnio() << std::endl;
    o << "Duración partida:" << auxFecha.getHora() << "/" << auxFecha.getMinuto() << std::endl;
    o << "Transmitida en vivo: " << siNo << std::endl;
    o << "Cantidad jugadores unidos a la partida: " << pMult.cantidadJugadoresUnidos << std::endl;
    o << "Jugadores unidos a la partida: ";
    std::string * invitados = pMult.nicknameJugadoresUnidos;
    for(int i = 0; i < cantJug; i++) {
	    o << invitados[i];
        if (i + 1 == cantJug)
            o << ".";
        else
            o << ", ";
    }
    return o;
}
