#include "../include/inicioFinPartidasController.h"

InicioFinPartidasController::IFPartidasinterface() {

}

static InicioFinPartidasController::InicioFinPartidasController * getInstance() {
    if(instancia == NULL) {
        instancia = new InicioFinPartidasController;
    }
    return instancia;
}

//Set(string) InicioFinPartidasController::obtenerVideojuegosActivos() {

}

//Set(DtPartida) InicioFinPartidasController::obtenerPartidasActivas() {

}

//Set(DtPartidaIndividual) InicioFinPartidasController::obtenerHistorialPartidas() {

}

//Set(string) InicioFinPartidasController::obtenerJugadoresSubscriptos() {

}

//void InicioFinPartidasController::seleccionarVideojuego(string) {

}

void InicioFinPartidasController::seleccionarContinuacionPartida(int) {

}

void InicioFinPartidasController::partidaEnVivo(bool) {

}

void InicioFinPartidasController::aniadirJugadorPartida(std::string) {

}

void InicioFinPartidasController::confirmarPartida() {

}

void InicioFinPartidasController::confirmarFinalizarPartida(int) {

}

void InicioFinPartidasController::clearCache() {

}