/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include <string>

#include "Videojuego.h"
#include "Partida.h"
#include "PartidaIndividual.h"
#include "PartidaMultijugador.h"

Videojuego::Videojuego(DtVideojuego datos, Set(Categoria) categorias) {
    this->nombre = datos.getNombre();
    this->descripcion = datos.getDescripcion();
    this->costoSuscripciones = datos.getCostos();
    this->totalHorasJugadas = 0;
    this->puntaje = 0;
    this->totalJugadoresSuscriptos = 0;

    ptrCat = begin(categorias);
    while (ptrCat != NULL) {
        this->categorias = add(categorias->getDt());
        ptrCat = next(categorias);
    }
}

DtVideojuego Videojuego::obtenerDatosVideojuego() {
    DtVideojuego dtVid = new DtVideojuego();
    dtVid->nombre = this->getNombre();
    dtVid->descripcion = this->getDescripcion();
    dtVid->costos = this->getCostoSuscripciones();
    return dtVid;
}

Set(string) Videojuego::obtenerJugadoresSuscriptos() {

}

bool Videojuego::estaActivo() {
    if (this->partidas->empty()) {
        return false;
    } else {
        return true;
    }
}

void Videojuego::confirmarPartida(Jugador host,PartidaIndividual pCont,bool enVivo,Set(Jugador) jUnidos) {
    if (pCont != NULL) {
        PartidaIndividual pInd = new PartidaIndividual();
        pInd->id = obtenerDatosPartida()->getId();
        pInd->fecha = obtenerDatosPartida()->getFecha();
        pInd->duracion = obtenerDatosPartida()->getDuracion();
        pInd->activa = obtenerDatosPartida()->getActiva();
        host->partidas = add(pInd); 
    } else {

    }
}
