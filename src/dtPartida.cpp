#include "../include/dtPartida.h"
#include "../include/dtFechaHora.h"

DtPartida::DtPartida(int id,DtFechaHora fecha,float duracion, bool activa) {
    this->id = id;
    this->fecha = fecha;
    this->duracion = duracion;
    this->activa = activa;
}

//poner gets chaval
//overloading como miguelillo (flujo) <<
