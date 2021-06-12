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

void Jugador::remove(Partida * partida) {
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

std::set<std::string> * Jugador::obtenerVideojuegosActivos() {
    std::set<std::string> * res = new std::set<std::string>;
    // Migue y Alexis: No funciona bien, porque estan devolviendo un puntero a DT!!!!
    /*
    for(std::set<Suscripcion *>::const_iterator it = suscripciones->cbegin(); it != suscripciones->cend(); it++) {
        Suscripcion * sus = *it;
        bool ok = sus->esActiva();
        if(ok) {
            std::string nombreVj = sus->obtenerVideojuego()->getNombre();
            res->insert(dtvjAct);
        }
    }
    */
    return res;
}

std::set<DtVideojuego> * Jugador::obtenerDatosVj() {
    std::set<DtVideojuego> * res = new std::set<DtVideojuego>;
    // Migue - Alexis: Esto esta bien, obtenerVideojuego() es una operacion de Suscripcion que tiene que devolver un DtVideojuego.
    //  @GUILLE Ver diagrama de comunicacion! P.D: El que hizo suscripcion no puede devolver un puntero a DtVideojuego!!!!
/*  for(std::set<Suscripcion *>::const_iterator it = suscripciones->cbegin(); it != suscripciones->cend(); it++) {
        Suscripcion * s = *it;
        bool esAct = s->esActiva();
        if(esAct) {
            DtVideojuego dtvjAct = s->obtenerVideojuego();
            res->insert(dtvjAct);
        }
    } */
    return res;
}

std::vector<DtPartida*>* Jugador::obtenerPartidasActivas() {
    std::vector<DtPartida*>* res = new std::vector<DtPartida*>;
    for(std::map<int,Partida*>::iterator it = partidas->begin(); it != partidas->end(); it++) {
        Partida* p = it->second;
        bool ok = p->esActiva();
        if(ok) {
            DtPartida* aInsertar = p->obtenerDatosPartida();
            std::vector<DtPartida*>::iterator itVector = res->begin();
            for ( ; itVector != res->end(); ++itVector) {
                if ((*itVector)->getFecha() < aInsertar->getFecha()) {
                    break;
                }
            }
            res->insert(itVector, aInsertar);
        }
    }
    return res;
}

// Lista en orden cronologico todas las partidas individuales finalizadas del jugador. (No distingue entre videojuegos).
// Se utiliza un puntero al DtPartida para poder castearlo a DtPartidaIndividual.
std::vector<DtPartidaIndividual*>* Jugador::obtenerHistorialPartidas() {
    std::vector<DtPartidaIndividual*>* res = new std::vector<DtPartidaIndividual*>;
    for (std::map<int, Partida*>::iterator it = partidas->begin(); it != partidas->end(); ++it) {
        if (dynamic_cast<PartidaIndividual*>(it->second)) {
            if (!(it->second->esActiva())) {
                DtPartidaIndividual* aInsertar = dynamic_cast<DtPartidaIndividual*>(it->second->obtenerDatosPartida());
                std::vector<DtPartidaIndividual*>::iterator itVector = res->begin();
                for ( ; itVector != res->end(); ++itVector) {
                    if ((*itVector)->getFecha() < aInsertar->getFecha()) {
                        break;
                    }
                }
                res->insert(itVector, aInsertar);
            }
        }
    }
    return res;
}

std::vector<DtPartidaMultijugador*>* Jugador::obtenerPartidasUnido() {
    std::vector<DtPartidaMultijugador*>* res = new std::vector<DtPartidaMultijugador*>;
    for (std::map<int, PartidaMultijugador*>::iterator it = partidasUnido->begin(); it != partidasUnido->end(); ++it) {
        DtPartidaMultijugador* aInsertar = dynamic_cast<DtPartidaMultijugador*>(it->second->obtenerDatosPartida());
        std::vector<DtPartidaMultijugador*>::iterator itVector = res->begin();
        for ( ; itVector != res->end(); ++itVector) {
            if ((*itVector)->getFecha() < aInsertar->getFecha()) {
                break;
            }
        }
        res->insert(itVector, aInsertar);
    }
    return res;
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

Jugador::~Jugador() {
    delete suscripciones;
    delete partidas;
    delete partidasUnido;
}