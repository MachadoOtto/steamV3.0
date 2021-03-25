/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Baladón
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "../include/dtPartidaMultijugador.h"
#include "../include/dtPartida.h"
#include "../include/PartidaMultijugador.h"
#include <iostream>
#include <string.h>

DtPartidaMultijugador::DtPartidaMultijugador(bool b, ListaJugador * pp, DtFechaHora d, float f): DtPartida(d,f){
    transmitidaEnVivo = b;
    nicknameJugadoresUnidos = "";
    cantidadJugadoresUnidos = 0;
    Jugador * jug = nullptr;
    DtJugador * dtJug = new DtJugador();
    while(pp != nullptr){
	cantidadJugadoresUnidos++;
	jug = pp->getJugador();
	*dtJug = jug->getDt();
	nicknameJugadoresUnidos = nicknameJugadoresUnidos + ", " + dtJug->getNickname();
	pp = pp->next();
    }
    delete dtJug;
} 

std::string DtPartidaMultijugador::getNicknameJugadoresUnidos(){
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
    std::string invstr = this->getNicknameJugadoresUnidos();
    int i=0,j=0;
    while(j < invstr.length()){
	if(invstr[j] == ','){
	    Jugador * p = findJugador(invstr.substr(i,j-1),jugadoresSystema);
	    if(p == nullptr)
	        throw std::invalid_argument("Uno de los jugadores invitados a la partida no se encuentra registrado.");
	    if(invitees == nullptr)
	        invitees = new ListaJugador(p);
	    else
	        invitees->add(p);
	    i=j+2;
	    j++;
	}
	j++;
    }
    Partida * p = new PartidaMultijugador(this->transmitidaEnVivo,this->getFecha(),this->getDuracion(),host,invitees);
    return p;
}

std::ostream &operator <<(std::ostream &o, DtPartidaMultijugador &pMult) {

    std::string siNo = "Si";
    if(pMult.getTransmitidaEnVivo()) siNo = "No";
    DtFechaHora auxFecha = pMult.getFecha();

    o << "Tipo Partida: Multijugador" << std::endl; 
    o << "Fecha partida:" << auxFecha.getDia() << "/" << auxFecha.getMes() << "/" << auxFecha.getAnio() << std::endl;
    o << "Duración partida:" << auxFecha.getHora() << "/" << auxFecha.getMinuto() << std::endl;
    o << "Transmitida en vivo: " << siNo << std::endl;
    o << "Cantidad jugadores unidos a la partida: " << pMult.getCantidadJugadoresUnidos() << std::endl;
    o << "Jugadores unidos a la partida: " << pMult.getNicknameJugadoresUnidos() << std::endl;

    return o;
}