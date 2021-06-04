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

using std::string
using std::map
using std::set

Videojuego::Videojuego(DtVideojuego datos, map<string,Categoria> *categorias) {
    this->nombre = datos.getNombre();
    this->descripcion = datos.getDescripcion();
    this->costoSuscripciones = datos.getCostos();
    this->totalHorasJugadas = 0;
    this->puntaje = 0;
    this->totalJugadoresSuscriptos = 0;
    this->categorias = categorias;
}

DtVideojuego Videojuego::obtenerDatosVideojuego() {
    DtVideojuego dtVid();
    dtVid.nombre = this->getNombre();
    dtVid.descripcion = this->getDescripcion();
    dtVid.costos = this->getCostoSuscripciones();
    return dtVid;
}

set<Jugador*>* Videojuego::obtenerJugadoresSuscriptos() {
    set<Jugador*>* setJugadores = new set<Jugador*>;
    for (set<Suscripcion*>::iterator it = suscripciones->begin(); it != suscripciones->end(); ++it) {
        setJugadores->insert(it->getComprador());
    }
    return setJugadores;
}

bool Videojuego::estaActivo() {
    if (this->partidas->empty()) {
        return false;
    } else {
        return true;
    }
}

void Videojuego::confirmarPartida(Jugador host,PartidaIndividual pCont,bool enVivo,set<Jugador> jUnidos) {
    if (pCont != NULL) {
        PartidaIndividual pInd = new PartidaIndividual();
        pInd->setId(pCont->obtenerDatosPartida()->getId());
        pInd->setFecha(pCont->obtenerDatosPartida()->getFecha());
        pInd->setDuracion(pCont->obtenerDatosPartida()->getDuracion());
        pInd->setActiva(pCont->obtenerDatosPartida()->getActiva());
        host->partidas->add(pInd); 
    } else {

    }
}
