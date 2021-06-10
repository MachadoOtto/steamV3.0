/* Laboratorio Programacion IV - INCO/FING/UDELAR 
 * Integrantes:
 *      Alexis Baladon (5.574.612-4) - alexis.baladon@fing.edu.uy
 *      Guillermo Toyos (5.139.879-9) - guillermo.toyos@fing.edu.uy
 *      Jorge Machado (4.876.616-9) - jorge.machado.ottonelli@fing.edu.uy
 *      Juan Jose Mangado (5.535.227-0) - juan.mangado@fing.edu.uy
 *      Mathias Ramilo (5.665.788-5) - mathias.ramilo@fing.edu.uy
 */

#include "../include/iFPController.h"

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

IFPController * IFPController::getInstance() {
    static IFPController instancia;
    return &instancia;
}

void IFPController::setHost(Jugador * host) {
    this->host = host;
}

Jugador * IFPController::getHost() {
    return host;
}

void IFPController::setVj(Videojuego * vj) {
    this->vj = vj;
}

Videojuego * IFPController::getVj() {
    return vj;
}

void IFPController::setPartida(Partida * partida) {
    //this->partida = partida; this->partida es PartidaIndividual. Falto casteo o error de dise(enie)o?
}

Partida * IFPController::getPartida() {
    return partida;
}

void IFPController::setPCont(bool pCont) {
    this->pCont = pCont;
}

bool IFPController::getPCont() {
    return pCont;
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
    //jugadoresAUnir->erase(jugador); uso incorrecto del erase del map
}

Jugador * IFPController::find(std::string nombreJugador) {
    //return jugadoresAUnir[nombreJugador]; no match for operator[]. ver types.
    return nullptr; //temporal
}

std::set<std::string> * IFPController::obtenerVideojuegosActivos() {
    HandlerUsuario * hu = HandlerUsuario::getInstance();
    host = static_cast<Jugador*>(hu->getLoggedUser());
    return host->obtenerVideojuegosActivos();
}

std::set<DtPartida> * IFPController::obtenerPartidasActivas() {
    HandlerUsuario * hu = HandlerUsuario::getInstance();
    Jugador * jSesion = static_cast<Jugador*>(hu->getLoggedUser());

    host = jSesion;
    return host->obtenerPartidasActivas();
}

std::set<DtPartidaIndividual> * IFPController::obtenerHistorialPartidas() {
    //Se quiere las partidas de todos los videojuegos me parece... en el UML no se pide el parametro videojuego para esta operacion. corregir. 
    Videojuego * vj = nullptr; //tmp
    return host->obtenerHistorialPartidas(vj);
}

std::set<std::string> * IFPController::obtenerJugadoresSubscriptos() {
    //return vj->obtenerJugadoresSuscriptos(); esto retorna el set de jugadores*... hay que hacer trabajooo
    return nullptr;
}

void IFPController::seleccionarVideojuego(std::string nombreVideojuego) {
    HandlerCatalogo *hc = HandlerCatalogo::getInstance();
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
    Jugador * jAUnir = static_cast<Jugador*>(hu->findUsuario(nicknameJugador));
    jugadoresAUnir->insert(std::pair<std::string,Jugador *>(nicknameJugador,jAUnir));
}

void IFPController::confirmarPartida() {
    //vj->confirmarPartida(host,partida,enVivo,jugadoresAUnir); se esperaba que jugadores a unir fuera un set, no un map. Que problema! 
    clearCache();
}

void IFPController::confirmarFinalizarPartida(int identificador) {
    host->finPartida(identificador);
    clearCache();
}

void IFPController::clearCache() {
   /* 
    delete host;
    delete partida;
    delete vj;
    delete jugadoresAUnir;

    * Esto creo que no esta bien. Limpiar el cache vendira a ser borrar los datos temporales que fuiste guardando en le controlador, no eliminar los objetos que guardas referencia, lo que tenes que hacer es limpiar las referencias (nullptr) */ 
}

std::set<DtPartidaMultijugador>* IFPController::obtenerPartidasMultiActivas(){
    return nullptr;
}

void IFPController::confirmarAbandonarPartida(int i){

}

IFPController::~IFPController() {
    clearCache();
}
