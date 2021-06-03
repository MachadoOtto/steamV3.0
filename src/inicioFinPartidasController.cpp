#include "../include/iFPController.h"

IFPController::IFPController() {

}

static IFPController * IFPController::getInstance() {
    if(instancia == NULL) {
        instancia = new IFPController;
    }
    return instancia;
}

//Set(string) IFPController::obtenerVideojuegosActivos() {

}

//Set(DtPartida) IFPController::obtenerPartidasActivas() {

}

//Set(DtPartidaIndividual) IFPController::obtenerHistorialPartidas() {

}

//Set(string) IFPController::obtenerJugadoresSubscriptos() {

}

//void IFPController::seleccionarVideojuego(string) {

}

void IFPController::seleccionarContinuacionPartida(int) {

}

void IFPController::partidaEnVivo(bool) {

}

void IFPController::aniadirJugadorPartida(std::string) {

}

void IFPController::confirmarPartida() {

}

void IFPController::confirmarFinalizarPartida(int) {

}

void IFPController::clearCache() {

}