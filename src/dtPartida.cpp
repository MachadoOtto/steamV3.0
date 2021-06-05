#include "../include/dtPartida.h"
#include "../include/dtFechaHora.h"

DtPartida::DtPartida(int id,DtFechaHora fecha,float duracion, bool activa) {
    this->id = id;
    this->fecha = fecha;
    this->duracion = duracion;
    this->activa = activa;
}

int DtPartida::getId() {
    return id;
}

DtFechaHora DtPartida::getFecha() {
    return fecha;
}

float DtPartida::getDuracion() {
    return duracion;
}

bool DtPartida::getActiva() {
    return activa;
}

bool DtPartida::esActiva() { //alias
    return getActiva();
}

friend & DtPartida::operator << (std::ostream o,DtPartida dtp) {

}
