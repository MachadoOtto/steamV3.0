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

Videojuego::Videojuego(DtVideojuego datos, map<string,Categoria*> *categorias) {
    this->nombre = datos.getNombre();
    this->descripcion = datos.getDescripcion();
    this->costoSuscripciones = datos.getCostos();
    this->totalHorasJugadas = 0;
    this->puntaje = 0;
    this->totalJugadoresSuscriptos = 0;
    this->categorias = categorias;
}

Videojuego::~Videojuego() {
    eliminarInfoAsociada();
    delete this->categorias;
    delete this->partidas;
    delete this->suscripciones;
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

void Videojuego::confirmarPartida(Jugador* host,int id,DtFechaHora fechaHoraActual,PartidaIndividual* pCont,bool enVivo,map<string,Jugador*>* jUnidos) {
    if (pCont != NULL) {
        DtPartidaIndividual dtPInd(id,fechaHoraActual,0,true);
        PartidaIndividual* pInd = new PartidaIndividual(dtPInd); 
        pInd->setHost(host);
        pInd->setPartidaAnterior(pCont);
        pInd->setVideojuego(this);
        host->agregarPartida(pInd); 
        this->partidas->insert(pInd);
    } else {
        DtPartidaMultijugador dtPMulti(id,fechaHoraActual,0,true,enVivo);
        PartidaMultijugador* pMulti = new PartidaMultijugador(dtPMulti);
        pMulti->setHost(host);
        pMulti->setJugadoresUnidos(jUnidos);
        host->agregarPartida(pMulti);
        for (map<string,Jugador*>::iterator it = jUnidos->begin(); it != jUnidos->end(); ++it) {
            it->second->associate(pMulti);
        }
        this->partidas->insert(pMulti);
    }
}

void Videojuego::cancelarSuscripcion(Jugador* host) {
    for (set<Suscripcion*>::iterator it = suscripciones->begin(); it != suscripciones->end(); ++it) {
        if (it->esDeJugador(host)) {
            it->cancelarSuscripcion();
        }
    }
}

void Videojuego::confirmarSuscripcion(Jugador* host,TipoValido tipoVal,TipoPago tipoPago) {
    Suscripcion* nuevaSus;
    DtFechaHora fechaHoraActual(); 
    if (tipoVal != TipoValido::Vitalicio) {
        SuscripcionTemporal* nuevaSus = new SuscripcionTemporal(tipoVal,TipoEstado::Activa,fechaHoraActual,host,this,tipoPago);
    } else {
        SuscripcionVitalicia* nuevaSus = new SuscripcionVitalicia(fechaHoraActual,host,this,tipoPago);
    }
    host->agregarSuscripcion(nuevaSus);
    this->suscripciones->insert(nuevaSus);
}

void Videojuego::eliminarInfoAsociada() {
    for (map<int,Partida*>::iterator it = partidas->begin(); it != partidas->end(); ++it) {
        it->second->eliminarAssoc();
        delete it->second;
    }
    for (set<Suscripcion*>::iterator it = suscripciones->begin(); it != suscripciones->end(); ++it) {
        it->eliminarAssoc();
        delete it;
    }
}

//--- Getters ---
string Videojuego::getNombre() {
    return this->nombre;
}

string getDescripcion() {
    return this->descripcion;
}

DtPrecios getCostoSuscripciones() {
    return this->costoSuscripciones;
}

float getTotalHorasJugadas() {
    return this->totalHorasJugadas;
}

float getPuntaje() {
    return this->puntaje;
}

int getTotalJugadoresSuscriptos() {
    return this->totalJugadoresSuscriptos;
}

Suscripcion* getSuscripciones() {
    return this->suscripciones;
}

map<int,Partida> getPartidas() {
    return this->partidas;
}

Categoria* getCategorias() {
    return this->categorias;
}

//--- Setters ---
void setNombre(string nombre) {
    this->nombre = nombre;
}

void setDescripcion(string descripcion) {
    this->descripcion = descripcion;
}

void setCostoSuscripciones(DtPrecios costoSuscripciones) {
    this->costoSuscripciones = costoSuscripciones;
}

void setTotalHorasJugadas(float totalHorasJugadas) {
    this->totalHorasJugadas = totalHorasJugadas;
}

void setPuntaje(float puntaje) {
    this->puntaje = puntaje;
}

void setTotalJugadoresSuscriptos(int totalJugadoresSuscriptos) {
    this->totalJugadoresSuscriptos = totalJugadoresSuscriptos;
}
