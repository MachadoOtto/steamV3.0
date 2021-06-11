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
    return host->obtenerVideojuegosActivos();
}

std::map<DtFechaHora, DtPartida*>* IFPController::obtenerPartidasActivas() {
    return host->obtenerPartidasActivas();
}

std::map<DtFechaHora, DtPartidaIndividual*>* IFPController::obtenerHistorialPartidas() {
    return host->obtenerHistorialPartidas();
}

std::set<std::string> * IFPController::obtenerJugadoresSubscriptos() {
    std::set<std::string>* res = new std::set<std::string>; 
    std::set<Jugador*>* jSus = vj->obtenerJugadoresSuscriptos();
    for (std::set<Jugador*>::iterator it = jSus->begin(); it != jSus->end(); ++it) {
        res->insert((*it)->getNickname());
    }
    return res;
}

void IFPController::aniadirJugadorPartida(std::string nicknameJugador) {
    HandlerUsuario * hu = HandlerUsuario::getInstance();
    Jugador * jAUnir = static_cast<Jugador*>(hu->findUsuario(nicknameJugador));
    jugadoresAUnir->insert(std::pair<std::string,Jugador *>(nicknameJugador,jAUnir));
}

void IFPController::confirmarPartida() {
    vj->confirmarPartida(host, contadorId++, partidaAnterior, enVivo, jugadoresAUnir);
}

void IFPController::confirmarFinalizarPartida(int identificador) {
    Partida* p = host->findPartida(identificador);
    PartidaMultijugador* pMulti = nullptr;
    if ((pMulti = dynamic_cast<PartidaMultijugador*>(p))) {
        std::map<std::string, Jugador*>* jUnidos = pMulti->getJugadoresUnidos();
        for (std::map<std::string, Jugador*>::iterator it = jUnidos->begin(); it != jUnidos->end(); ++it) {
            if (it->second->findPartidaMulti(identificador) == pMulti) {
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

std::map<DtFechaHora, DtPartidaMultijugador*>* IFPController::obtenerPartidasMultiActivas() {
    return host->obtenerPartidasUnido();
}

void IFPController::confirmarAbandonarPartida(int i) {
    PartidaMultijugador* p = dynamic_cast<PartidaMultijugador*>(host->findPartida(i));
    host->abandonarPartidaMulti(p);
}

IFPController::~IFPController() {
    delete jugadoresAUnir;
}