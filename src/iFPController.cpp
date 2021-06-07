/* Laboratorio Programacion IV - INCO/FING/UDELAR 
 * Integrantes:
 *      Alexis Baladon (5.574.612-4) - alexis.baladon@fing.edu.uy
 *      Guillermo Toyos (5.139.879-9) - guillermo.toyos@fing.edu.uy
 *      Jorge Machado (4.876.616-9) - jorge.machado.ottonelli@fing.edu.uy
 *      Juan Jose Mangado (5.535.227-0) - juan.mangado@fing.edu.uy
 *      Mathias Ramilo (5.665.788-5) - mathias.ramilo@fing.edu.uy
 */

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
#include <pair>

//IFPController * IFPController::instancia = NULL;

IFPController::IFPController() {
    host = NULL;
    vj = NULL;
    partida = NULL;
    jugadoresAUnir = new std::map<std::string,Jugador *>;
}

IFPController * IFPController::getInstance() {
    static IFPController instancia();
    return &instancia;
}

void setHost(Jugador * host) {
    this->host = host;
}

Jugador * getHost() {
    return host;
}

void setVj(Videojuego * vj) {
this->vj = vj;
}

Videojuego * getVj() {
    return vj;
}

void setPartida(Partida * partida) {
 this->partida = partida;
}

Partida * getPartida() {
    return partida;
}

void setPCont(bool pCont) {
    this->pCont = pCont;
}

bool getPCont() {
    return pCont;
}

void setEnVivo(bool enVivo) {
    this->enVivo = enVivo;
}

bool getEnVivo() {
    return enVivo;
}

void add(Jugador * jugador) {
    jugadoresAUnir->insert(std::pair<std::string,Jugador *>(jugador->getNombre(),jugador));
}

void remove(Jugador * jugador) {
    jugadoresAUnir->erase(jugador);
}

Jugador * find(std::string nombreJugador) {
    return jugadoresAUnir[nombreJugador];
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
    delete jugadoresAUnir;
}

~IFPController() {
    clearCache();
}
