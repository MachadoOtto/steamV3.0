#include "../include/iFPController.h"
#include "../include/IIFPController.h"
#include "../include/dtPartida.h"
#include "../include/dtPartidaIndividual.h"
#include "../include/usuario.h"
#include "../include/handlerCatalogo"

#include <string>
#include <set>
#include <map>
#include <iterator>

IFPController::IFPController() {
    host = NULL;
    vj = NULL;
    partida = NULL;
    jugadoresAUnir = new std::map<std::string,Jugador *>;
}

static IFPController * IFPController::getInstance() {
    if(instancia == NULL) {
        instancia = new IFPController;
    }
    return instancia;
}

std::set<std::string> * obtenerVideojuegosActivos() {
    HandlerUsuario * hu = HandlerUsuario::getInstance();
    host = hu->getLoggedUser();
    return host->obtenerVideojuegosActivos();
}

std::set<DtPartida> * obtenerPartidasActivas() {
    HandlerUsuario * hu = HandlerUsuario::getInstance();
    Jugador * jSesion = hu->getLoggedUser();
    host = jSesion;
    return host->obtenerPartidasActivas();
}

std::set<DtPartidaIndividual> * obtenerHistorialPartidas(Videojuego * vj) {
    return host->obtenerHistorialPartidas(vj);
}

std::set<std::string> * obtenerJugadoresSubscriptos() {
    return vj->obtenerJugadoresSubscriptos();
}

void seleccionarVideojuego(std::string nombreVideojuego) {
    HandlerCatalogo hc = HandlerCatalogo::getInstance();
    vj = hc->findVideojuego(nombreVideojuego);
}

void IFPController::seleccionarContinuacionPartida(int identificador) {
    partida = host->seleccionarContinuacionPartida(identificador);
}

void IFPController::partidaEnVivo(bool esTransmitidaEnVivo) {
    enVivo = esTransmitidaEnVivo;
}

void IFPController::aniadirJugadorPartida(std::string nicknameJugador) {
    HandlerUsuario * hu = HandlerUsuario::getInstance();
    Jugador * jAUnir = hu->findJugador(nicknameJugador);
    jugadoresAUnir->insert(std::pair<std::string,Jugador *>(nicknameJugador,jAUnir));
}

void IFPController::confirmarPartida() {
    vj->confirmarPartida(host,partida,enVivo,jugadoresAUnir);
    clearCache();
}

void IFPController::confirmarFinalizarPartida(int identificador) {
    host->finPartida(identificador);
    clearCache();
}

void IFPController::clearCache() {
    delete host;
    delete partida;
    delete vj;
    for(std::map<std::string,Jugador *>::iterator it = jugadoresAUnir->begin(); it != jugadoresAUnir->end(); it++) {
        delete it->second;
    }
    delete jugadoresAUnir;
}
