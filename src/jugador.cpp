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
    jMultis = new std::set<JugadorMulti *>;
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

Partida * Jugador::find(int identificador) {
    return partidas->find(identificador)->second;
}

void Jugador::add(JugadorMulti * jMulti) {
    jMultis->insert(jMulti);
}

void Jugador::remove(JugadorMulti * jMulti) {
    jMultis->erase(jMulti);
}

std::set<std::string> * Jugador::obtenerVideojuegosActivos() {
    std::set<std::string> * res = new std::set<std::string>;
    /* Esto no funciona bien. Revisar que es exactamente lo que se quiere mandar...
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
    /* No se utilizan correctamente las funciones de suscripcion. Suscripcion devuelve el objeto videojuego no un dt... 
    for(std::set<Suscripcion *>::const_iterator it = suscripciones->cbegin(); it != suscripciones->cend(); it++) {
        Suscripcion * s = *it;
        bool esAct = s->esActiva();
        if(esAct) {
            DtVideojuego dtvjAct = s->obtenerVideojuego();
            res->insert(dtvjAct);
        }
    }
    */
    return res;
}

std::set<DtPartida> * Jugador::obtenerPartidasActivas() {
    std::set<DtPartida> * res = new std::set<DtPartida>;
    for(std::map<int,Partida *>::const_iterator it = partidas->cbegin(); it != partidas->cend(); it++) {
        Partida * p = it->second;
        bool ok = p->esActiva();
        if(ok) {
            DtPartida dvj = p->obtenerDatosPartida();
            res->insert(dvj);
        }
    }
    return res;
}

std::set<DtPartidaIndividual> * Jugador::obtenerHistorialPartidas(Videojuego * vj) {
    std::set<DtPartidaIndividual> * res = new std::set<DtPartidaIndividual>;
    /* Hay problemas de polimorfismo en la iteracion del map, revisar todo 
    for(std::map<int,PartidaIndividual *>::const_iterator it = partidas->cbegin(); it != partidas->cend(); it++) {
        PartidaIndividual * pi = it->second;
        bool activa = pi->esActiva();
        //bool esVj = pi->esIgualVideojuego(vj); Esta funcion no es valida. No utilizar.
	bool esVj = false; //provisorio
        if(!activa && esVj) {
            //DtPartidaIndividual datosPartida = pi->getDtPartidaIndividual(); esta funcion noexiste...
            //res->insert(dtvjAct); dtvj was not declared in this scope
        }
    }
    */
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
    partidas->erase(p->getId());
    JugadorMulti * jm = new JugadorMulti(p->getDtFechaHora());
    delete p;
    jMultis->insert(jm);
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
    for(std::set<JugadorMulti *>::iterator it = jMultis->begin(); it != jMultis->end(); it++) {
        delete *it;
    }
    delete jMultis;
}
