#include "../include/jugador.h"
#include "../include/dtJugador.h"
#include "../include/dtVideojuego.h"
#include "../include/dtPartida.h"
#include "../include/dtPartidaindividual.h"
#include "../include/partidaindividual.h"
#include "../include/partida.h"
#include "../include/suscripcion.h"
#include "../include/JugadorMulti.h"

#include <string>
#include <set>
#include <map>
#include <iterator>

Jugador::Jugador(DtJugador dtj) {
    suscripciones = new std::set<Suscripcion *>;
    partidas = new std::map<int,Partidaindividual *>;
    jMultis = new std::set<JugadorMulti *>;
    descripcion = dtj.getDescripcion();
    nickname = dtj.getNickname();
    email = dtj.getEmail();
    contrasenia = dtj.getContrasenia();
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
    partidas->insert(std::pair<int,Partida *>(partida->getIdentificador(),partida));
}

void Jugador::remove(Partida * partida) {
    partidas->erase(partida->getIdentificador());
}

Partida * Jugador::find(int identificador) {
    return partidas[identificador];
}

void Jugador::add(JugadorMulti * jMulti) {
    jMultis->insert(jMulti);
}

void Jugador::remove(JugadorMulti * jMulti) {
    jMultis->erase(jMulti);
}

std::set<std::string> * Jugador::obtenerVidejuegosActivos() {
    std::set<std::string> * res = new std::set<std::string>;
    for(std::set<Suscripcion *>::const_iterator it = suscripciones->cbegin(); it != suscripciones->cend(); it++) {
        Suscripcion * sus = *it;
        bool ok = sus->esActiva();
        if(ok) {
            std::string nombreVj = sus->getNombreVideojuego();
            res->insert(dtvjAct);
        }
    }
    return res;
}

std::set<DtVideojuego> * Jugador::obtenerDatosVj() {
    std::set<DtVideojuego> * res = new std::set<DtVideojuego>;
    for(std::set<Suscripcion *>::const_iterator it = suscripciones->cbegin(); it != suscripciones->cend(); it++) {
        Suscripcion * s = *it;
        bool esAct = s->esActiva();
        if(esAct) {
            DtVideojuego dtvjAct = s->obtenerVideojuego();
            res->insert(dtvjAct);
        }
    }
    return res;
}

std::set<DtPartida> * Jugador::obtenerPartidasActivas() {
    std::set<DtPartida> * res = new std::set<DtPartida>;
    for(std::map<int,Partida *>::const_iterator it = partidas->cbegin(); it != partidas->cend(); it++) {
        Partida * p = *it;
        bool ok = p->esActiva();
        if(ok) {
            DtVideojuego dvj = p->obtenerDatosPartida();
            res->insert(dvj);
        }
    }
    return res;
}

std::set<DtPartidaindividual> * Jugador::obtenerHistorialPartidas(Videojuego * vj) {
    std::set<DtPartidaindividual> * res = new std::set<DtPartidaindividual>;
    for(std::map<int,Partidaindividual *>::const_iterator it = partidas->cbegin(); it != partidas->cend(); it++) {
        PartidaIndividual * pi = *it;
        bool activa = pi->esActiva();
        bool esVj = pi->esIgualVideojuego(vj);
        if(!activa && esVj) {
            DtPartidaindividual datosPartida = pi->getDtPartidaIndividual();
            res->insert(dtvjAct);
        }
    }
    retun res;
}

Partidaindividual * Jugador::seleccionarContinuacionPartida(int identificador) {
    return *(partidas->find(identificador));
}

void Jugador::agregarPartida(Partida * partida) {
    partidas->insert(std::pair<int,Partida *>(partida->id,partida));
}

void Jugador::agregarSuscripcion(Suscripcion * sNueva) {
    suscripciones->insert(sNueva);
}

void Jugador::abandonarPartidaMulti(PartidaMultijugador * p) {
    partidas->erase(p->id);
    JugadorMulti * jm = new JugadorMulti(p->fecha);
    delete p;
    jMultis->insert(jm);
}

void Jugador::finPartida(int identificador) {
    Partidas * p = *(partidas->find(identificador));
    p->finalizarPartida();
}

void Jugador::associate(Partida * pNueva) {
    agregarPartida(pNueva);
}

void Jugador::removeSus(Suscripcion * s) {
    suscrpiciones->erase(s);
    delete s;
}

void Jugador::remove(Partida * p) {
    partidas->erase(p->getIdentificador());
}

Jugador::~Jugador() {
    delete suscripciones;
    delete partidas;
    for(std::set<JugadorMulti *>::iterator it = jMultis->begin(); it != jMultis->end(); it++) {
        delete *it;
    }
    delete jMultis;
}
