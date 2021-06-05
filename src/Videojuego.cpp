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
#include <map>
#include <set>

#include "Videojuego.h"
#include "Partida.h"
#include "Suscripcion.h"
#include "Categoria.h"
#include "Jugador.h"
#include "PartidaIndividual.h"
#include "PartidaMultijugador.h"
#include "dtVideojuego.h"
#include "tipoSuscripcion.h"
#include "tipoPago.h"

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
        DtPartidaIndividual dtPInd();
        dtPInd.setId(pCont->obtenerDatosPartida()->getId());
        dtPInd.setFecha(pCont->obtenerDatosPartida()->getFecha());
        dtPInd.setDuracion(pCont->obtenerDatosPartida()->getDuracion());
        dtPInd.setActiva(pCont->obtenerDatosPartida()->getActiva());
        PartidaIndividual pInd = new PartidaIndividual(dtPInd); 
        host->partidasInd->insert(pInd); 
    } else {
        DtPartidaMultijugador dtPMulti();
        dtPMulti.setId(pCont->obtenerDatosPartida()->getId());
        dtPMulti.setFecha(pCont->obtenerDatosPartida()->getFecha());
        dtPMulti.setDuracion(pCont->obtenerDatosPartida()->getDuracion());
        dtPMulti.setActiva(pCont->obtenerDatosPartida()->getActiva());
    }
}

void Videojuego::cancelarSuscripcion(Jugador host) {
    for (set<Suscripcion*>::iterator it = suscripciones->begin(); it != suscripciones->end(); ++it) {
        if (it->esDeJugador(host)) {
            it->cancelarSuscripcion();
        }
    }
}

void Videojuego::confirmarSuscripcion(Jugador host,TipoSuscripcion tipoSus,TipoPago tipoPago) {
    
}

void Videojuego::eliminarInfoAsociada(Videojuego videojuego) {

}
