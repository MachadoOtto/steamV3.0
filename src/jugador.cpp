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

Jugador::Jugador(DtJugador dtj) { //ABSTRACCION???
    suscripciones = new std::set<Suscripcion *>;
    partidasIndstd = new std::map<int,Partidaindividual *>;
    jMultis = new std::set<JugadorMulti *>;
    descripcion = dtj->descripcion;
    nickname = dtj->descripcion;
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

std::set<std::string> * Jugador::getVjSinPartidasActivas() {
    //DONDE ESTA ESTA OPERACION???
}

std::set<DtPartida> * Jugador::obtenerPartidasActivas() {
    std::set<DtPartida> * res = new std::set<DtPartida>;
    for(std::map<int,Partida *>::const_iterator it = partidasInd->cbegin(); it != partidasInd->cend(); it++) {
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
    for(std::map<int,Partidaindividual *>::const_iterator it = partidasInd->cbegin(); it != partidasInd->cend(); it++) {
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
    return *(partidasInd->find(identificador));
}

void Jugador::agregarPartida(Partida * partida) {
    partidasInd->insert(std::pair<int,Partida *>(partida->id,partida));
}

void Jugador::agregarSuscripcion(Suscripcion * sNueva) {
    suscripciones->insert(sNueva);
}

void Jugador::abandonarPartidaMulti(PartidaMultijugador * p) {
    partidasInd->erase(p->id);
    JugadorMulti * jm = new JugadorMulti(p->fecha);
    delete p;
    jMultis->insert(jm);
}

void Jugador::finPartida(int identificador) {
    Partidas * p = *(partidasInd->find(identificador));
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
    //QUE HAGOOOOOOOOOOOOOO
    int ayuda = 1/0;
}

Jugador::~Jugador() {
    for(std::set<Suscripcion *>::iterator it = suscripciones->begin(); it != suscripciones->end(); it++) {
        delete *it;
    }
    delete suscripciones;
    for(std::map<int,Partidaindividual *> it = partidasInd->begin(); it != partidasInd->end(); it++) {
        delete it->second;
    }
    delete partidasInd;
    for(std::set<Suscripcion *>::iterator it = jMultis->begin(); it != jMultis->end(); it++) {
        delete *it;
    }
    delete jMultis;
}
