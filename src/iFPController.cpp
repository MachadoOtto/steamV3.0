/* Laboratorio Programacion IV - INCO/FING/UDELAR 
 * Integrantes:
 *      Alexis Baladon (5.574.612-4) - alexis.baladon@fing.edu.uy
 *      Guillermo Toyos (5.139.879-9) - guillermo.toyos@fing.edu.uy
 *      Jorge Machado (4.876.616-9) - jorge.machado.ottonelli@fing.edu.uy
 *      Juan Jose Mangado (5.535.227-0) - juan.mangado@fing.edu.uy
 *      Mathias Ramilo (5.665.788-5) - mathias.ramilo@fing.edu.uy
 */

#include "../include/iFPController.h"

IFPController::IFPController() {
    esIndividual = false;
    contadorId = 0;
    host = NULL;
    vj = NULL;
    partidaAnterior = NULL;
    jugadoresAUnir = new std::map<std::string,Jugador *>;
}

IFPController * IFPController::getInstance() {
    static IFPController instancia;
    return &instancia;
}

void IFPController::iniciarSesion() {
    HandlerUsuario* hu = HandlerUsuario::getInstance();
    this->setHost(static_cast<Jugador*>(hu->getLoggedUser()));
}

int IFPController::getIdSisActual() {
    return contadorId;
}

void IFPController::setTipo(bool tipo) {
    esIndividual = tipo;
}

bool IFPController::getTipo() {
    return esIndividual;
}

void IFPController::setHost(Jugador * player) {
    this->host = player;
}

Jugador * IFPController::getHost() {
    return host;
}

void IFPController::seleccionarVideojuego(std::string nombreVideojuego) {
    HandlerCatalogo *hc = HandlerCatalogo::getInstance();
    this->setVj(hc->findVideojuego(nombreVideojuego));
}

void IFPController::setVj(Videojuego * vj) {
    this->vj = vj;
}

Videojuego * IFPController::getVj() {
    return vj;
}

void IFPController::seleccionarContinuacionPartida(int identificador) {
    this->setPartidaAnterior(host->seleccionarContinuacionPartida(identificador));
}

void IFPController::setPartidaAnterior(PartidaIndividual * partidaAnt) {
    this->partidaAnterior = partidaAnt;
}

Partida * IFPController::getPartidaAnterior() {
    return partidaAnterior;
}

void IFPController::setEnVivo(bool enVivo) {
    this->enVivo = enVivo;
}

bool IFPController::getEnVivo() {
    return enVivo;
}

void IFPController::add(Jugador * jugador) {
    jugadoresAUnir->insert(std::pair<std::string,Jugador *>(jugador->getNickname(),jugador));
}

void IFPController::remove(Jugador * jugador) {
    jugadoresAUnir->erase(jugador->getNickname());
}

Jugador * IFPController::findJugador(std::string nombreJugador) {
    return jugadoresAUnir->find(nombreJugador)->second;
}

std::set<std::string>* IFPController::obtenerVideojuegosActivos() {
    std::set<std::string>* res = new std::set<std::string>;
    std::set<Suscripcion*>* suscripciones = host->getSuscripciones();
    for(std::set<Suscripcion *>::iterator it = suscripciones->begin(); it != suscripciones->end(); it++) {
        if((*it)->esActiva()) {
            res->insert((*it)->obtenerVideojuego()->getNombre());
        }
    }  
    return res;
}

std::map<int, std::string>* IFPController::obtenerPartidasActivas() {
    std::map<int, std::string>* res = new std::map<int, std::string>;
    std::map<int, Partida*>* pActiva = host->obtenerPartidas();
    std::string aInsertar = "";
    for (std::map<int, Partida*>::iterator it = pActiva->begin(); it != pActiva->end(); ++it) {
        if (it->second->esActiva()) {
            aInsertar = aInsertar + "ID: " + std::to_string(it->second->getId()) + "\n" + "Fecha de creacion: " + it->second->getDtFechaHora().getString() + "\n"
            + "Videojuego: " + it->second->getVideojuego()->getNombre() + ".\n";
            if (dynamic_cast<PartidaIndividual*>(it->second)) {
                PartidaIndividual* pInd = dynamic_cast<PartidaIndividual*>(it->second);
                if (pInd->getPartidaAnterior() == NULL) 
                    aInsertar = aInsertar + "No es continuacion de otra partida \n";
                else 
                    aInsertar = aInsertar + "ID partida anterior: " + std::to_string(pInd->getPartidaAnterior()->getId()) + "\n";
            } else {
                PartidaMultijugador* pMulti = dynamic_cast<PartidaMultijugador*>(it->second);
                if (pMulti->getTransmitidaEnVivo()) 
                    aInsertar = aInsertar + "Se esta transmitiendo en vivo\n";
                else 
                    aInsertar = aInsertar + "No se ha transmitido en vivo\n";
                std::map<string, Jugador*>* jUnidos = pMulti->getJugadoresUnidos();
                aInsertar = aInsertar + "Jugadores unidos:\n";
                for (std::map<string, Jugador*>::iterator it = jUnidos->begin(); it != jUnidos->end(); ++it) {
                    aInsertar = aInsertar + "\t" + it->first + "\n";
                }
            }
            res->insert(map<int, std::string>::value_type(it->second->getId(), aInsertar));
        }
        aInsertar = "";
    }
    return res;
}

std::set<int>* IFPController::obtenerHistorialIDPartidas() {
    std::set<int>* res = new std::set<int>;
    std::vector<PartidaIndividual*>* partidas = host->obtenerHistorialPartidas();
    int aInsertar;
    for (std::vector<PartidaIndividual*>::iterator it = partidas->begin(); it != partidas->end(); ++it) {
        if ((*it)->getVideojuego()->getNombre() == vj->getNombre()) {
            aInsertar = (*it)->getId();
            res->insert(aInsertar);
        }
    }
    delete partidas;
    return res;
}

std::vector<std::string>* IFPController::obtenerHistorialPartidas() {
    std::vector<std::string>* res = new std::vector<std::string>;
    std::vector<PartidaIndividual*>* partidas = host->obtenerHistorialPartidas();
    std::string aInsertar = "";
    for (std::vector<PartidaIndividual*>::iterator it = partidas->begin(); it != partidas->end(); ++it) {
        if ((*it)->getVideojuego()->getNombre() == vj->getNombre()) {
            aInsertar = aInsertar + "ID: " + std::to_string((*it)->getId()) + "\n" + "Fecha de creacion: " + (*it)->getDtFechaHora().getString() + "\n"
            + "Duracion: " + std::to_string((*it)->getDuracion()) + ".\n";
            res->insert(res->end(), aInsertar);
        }
        aInsertar = "";
    }
    delete partidas;
    return res;
}

std::set<std::string> * IFPController::obtenerJugadoresSubscriptos() {
    std::set<std::string>* res = new std::set<std::string>; 
    std::set<Jugador*>* jSus = vj->obtenerJugadoresSuscriptos();
    for (std::set<Jugador*>::iterator it = jSus->begin(); it != jSus->end(); ++it) {
        if ((this->getHost()->getNickname()) != (*it)->getNickname())
            res->insert((*it)->getNickname());
    }
    delete jSus;
    return res;
}

void IFPController::aniadirJugadorPartida(std::string nicknameJugador) {
    HandlerUsuario * hu = HandlerUsuario::getInstance();
    Jugador * jAUnir = static_cast<Jugador*>(hu->findJugador(nicknameJugador));
    jugadoresAUnir->insert(std::pair<std::string,Jugador *>(nicknameJugador,jAUnir));
}

void IFPController::confirmarPartida() {
    if (esIndividual)
        vj->confirmarPartida(host, ++contadorId, partidaAnterior);
    else {
        vj->confirmarPartida(host, ++contadorId, enVivo, jugadoresAUnir);
        jugadoresAUnir = new std::map<std::string,Jugador *>;
    }
}


void IFPController::confirmarFinalizarPartida(int identificador) {
    Partida* p = host->findPartida(identificador);
    PartidaMultijugador* pMulti = nullptr;
    if ((pMulti = dynamic_cast<PartidaMultijugador*>(p))) {
        std::map<std::string, Jugador*>* jUnidos = pMulti->getJugadoresUnidos();
        for (std::map<std::string, Jugador*>::iterator it = jUnidos->begin(); it != jUnidos->end(); ++it) {
            if ((!(it->second->obtenerPartidasUnido()->empty())) && (it->second->findPartidaMulti(identificador) == pMulti)) {
                it->second->abandonarPartidaMulti(pMulti);
            }
        }
    }
    p->finalizarPartida();   
}

void IFPController::clearCache() {
    host = NULL;
    partidaAnterior = NULL;
    vj = NULL;
    jugadoresAUnir->clear();
}

std::map<int, std::string>* IFPController::obtenerPartidasMultiActivas() {
    std::map<int, std::string>* res = new std::map<int, std::string>;
    std::map<int, PartidaMultijugador*>* pUnido = host->obtenerPartidasUnido();
    std::string aInsertar = "";
    for (std::map<int, PartidaMultijugador*>::iterator it = pUnido->begin(); it != pUnido->end(); ++it) {
        DtPartidaMultijugador* dtMulti = dynamic_cast<DtPartidaMultijugador*>(it->second->obtenerDatosPartida());
        aInsertar = aInsertar + dtMulti->getString();
        delete dtMulti;
        aInsertar = aInsertar + "Host: " + it->second->getHost()->getNickname() + ".\n";
        aInsertar = aInsertar + "Videojuego: " + it->second->getVideojuego()->getNombre() + ".\n";
        std::map<string, Jugador*>* jUnidos = it->second->getJugadoresUnidos();
        aInsertar = aInsertar + "Jugadores unidos:\n";
        for (std::map<string, Jugador*>::iterator it = jUnidos->begin(); it != jUnidos->end(); ++it) {
            aInsertar = aInsertar + "\t" + it->first + "\n";
        }
        res->insert(map<int, std::string>::value_type(it->second->getId(), aInsertar));
        aInsertar = "";
    }
    return res;
}

void IFPController::confirmarAbandonarPartida(int i) {
    host->abandonarPartidaMulti(host->findPartidaMulti(i));
}

IFPController::~IFPController() {
    delete jugadoresAUnir;
}
