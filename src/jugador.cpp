/* Laboratorio Programacion IV - INCO/FING/UDELAR 
 * Integrantes:
 *      Alexis Baladon (5.574.612-4) - alexis.baladon@fing.edu.uy
 *      Guillermo Toyos (5.139.879-9) - guillermo.toyos@fing.edu.uy
 *      Jorge Machado (4.876.616-9) - jorge.machado.ottonelli@fing.edu.uy
 *      Juan Jose Mangado (5.535.227-0) - juan.mangado@fing.edu.uy
 *      Mathias Ramilo (5.665.788-5) - mathias.ramilo@fing.edu.uy
 */

#include "../include/jugador.h"

#include <string>
#include <set>
#include <map>
#include <iterator>

Jugador::Jugador(DtJugador dtj):Usuario(dtj.getEmail(),dtj.getContrasenia()) {
    suscripciones = new std::set<Suscripcion *>;
    partidas = new std::map<int,Partida *>;
    partidasUnido = new std::map<int,PartidaMultijugador *>;
    descripcion = dtj.getDescripcion();
    nickname = dtj.getNickname();
}

void Jugador::setNickname(std::string nickname) {
    this->nickname = nickname;
}

std::string Jugador::getNickname() {
    return nickname;
}

void Jugador::setDescripcion(std::string descripcion) {
    this->descripcion = descripcion;
}

std::string Jugador::getDescripcion() {
    return descripcion;
}

void Jugador::add(Suscripcion * suscripcion) {
    suscripciones->insert(suscripcion);
}

void Jugador::remove(Suscripcion * suscripcion) {
    suscripciones->erase(suscripcion);
}

void Jugador::add(Partida * partida) {
    partidas->insert(std::pair<int,Partida *>(partida->getId(),partida));
}

void Jugador::quitar(Partida * partida) {
    partidas->erase(partida->getId());
}

Partida * Jugador::findPartida(int identificador) {
    return partidas->find(identificador)->second;
}

void Jugador::add(PartidaMultijugador * pMulti) {
    partidasUnido->insert(map<int, PartidaMultijugador*>::value_type(pMulti->getId(), pMulti));
}

void Jugador::remove(PartidaMultijugador * pMulti) {
    partidasUnido->erase(pMulti->getId());
}

PartidaMultijugador * Jugador::findPartidaMulti(int id) {
    return partidasUnido->find(id)->second;
}

std::set<Videojuego *> * Jugador::obtenerDatosVj() {
    std::set<Videojuego*> * res = new std::set<Videojuego*>;
    // Migue - Alexis: Esto esta bien, obtenerVideojuego() es una operacion de Suscripcion que tiene que devolver un DtVideojuego.
    //  @GUILLE Ver diagrama de comunicacion! P.D: El que hizo suscripcion no puede devolver un puntero a DtVideojuego!!!!
    //  Guille: El diagrama esta mal. Se generan dependencias circulares. Me veo forzado a redise(niar) todo
    /*for(std::set<Suscripcion *>::const_iterator it = suscripciones->cbegin(); it != suscripciones->cend(); it++) {
        Suscripcion * s = *it;
	bool esAct = s->esActiva();
        if(esAct) {
            DtVideojuego dtvjAct = s->obtenerVideojuego();
            res->insert(dtvjAct);
        }
    } */
    Videojuego * v = nullptr;
    for (std::set<Suscripcion *>::iterator it = suscripciones->begin(); it != suscripciones->end(); it++){
	v=(*it)->obtenerVideojuego();
	res->insert(v);
    }	 
    return res;
}

std::map<int, Partida*>* Jugador::obtenerPartidas() {
    return partidas;
}

// Lista en orden cronologico todas las partidas individuales finalizadas del jugador. (No distingue entre videojuegos).
std::vector<PartidaIndividual*>* Jugador::obtenerHistorialPartidas() {
    std::vector<PartidaIndividual*>* res = new std::vector<PartidaIndividual*>;
    for (std::map<int, Partida*>::iterator it = partidas->begin(); it != partidas->end(); ++it) {
        PartidaIndividual* aInsertar = NULL;
        if ((!(it->second->esActiva())) && ((aInsertar = dynamic_cast<PartidaIndividual*>(it->second)))) {
            std::vector<PartidaIndividual*>::iterator itVector = res->begin();
            for ( ; itVector != res->end(); ++itVector) {
                if ((*itVector)->getDtFechaHora() < aInsertar->getDtFechaHora()) {
                    break;
                }
            }
            res->insert(itVector, aInsertar);
        }
    }
    return res;
}

std::map<int,PartidaMultijugador *>* Jugador::obtenerPartidasUnido() {
    return partidasUnido;
}

PartidaIndividual * Jugador::seleccionarContinuacionPartida(int identificador) {
    return static_cast<PartidaIndividual*>(partidas->find(identificador)->second);
}

void Jugador::agregarPartida(Partida * partida) {
    partidas->insert(std::pair<int,Partida *>(partida->getId(),partida));
}

void Jugador::agregarSuscripcion(Suscripcion * sNueva) {
    suscripciones->insert(sNueva);
}

void Jugador::abandonarPartidaMulti(PartidaMultijugador * p) {
    partidasUnido->erase(p->getId());
    JugadorMulti* jMulti = new JugadorMulti(fechaSistema::fecha);
    p->abandonar(jMulti);
}

void Jugador::finPartida(int identificador) {
    Partida * p = partidas->find(identificador)->second;
    p->finalizarPartida();
}

void Jugador::associate(Partida * pNueva) {
    agregarPartida(pNueva);
}

void Jugador::removeSus(Suscripcion * s) {
    suscripciones->erase(s);
    delete s;
}

set<Suscripcion *>* Jugador::getSuscripciones(){
    return suscripciones;
}

Jugador::~Jugador() {
    delete suscripciones;
    delete partidas;
    delete partidasUnido;
}
