#include "../include/dtPartidaMultijugador.h"
#include "../include/dtPartida.h"
#include "../include/dtFechaHora"

DtPartidaMultijugador::DtPartidaMultijugador(int id,DtFechaHora fecha,float duracion,bool activa, bool transmitidaEnVivo): DtPartida(id,fecha,duracion,activa) {
    this->transmitidaEnVivo = transmitidaEnVivo;
}

bool DtPartidaMultijugador::getTransmitidaEnVivo() {
    return transmitidaEnVivo;
}

friend & operator << (std::ostream,DtPartida) {
    
}
