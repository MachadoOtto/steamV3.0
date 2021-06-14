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

#include "../include/videojuego.h"

using std::string;
using std::map;
using std::set;

Videojuego::Videojuego(DtVideojuego datos, map<string,Categoria*> *categorias): costoSuscripciones(datos.getDtPrecios()){
    this->nombre = datos.getNombre();
    this->descripcion = datos.getDescripcion();
    this->totalHorasJugadas = 0;
    this->puntaje = 0;
    this->totalJugadoresSuscriptos = 0;
    this->categorias = categorias;
    this->partidas = new map<int,Partida*>;
    this->suscripciones = new set<Suscripcion*>;
    opiniones = new vector<int>;
}

Videojuego::~Videojuego() {
    eliminarInfoAsociada();
    delete this->categorias;
    delete this->partidas;
    delete this->suscripciones;
    delete opiniones;
}

DtVideojuego Videojuego::obtenerDatosVideojuego() {
    DtPrecios dtPrecios = this->getCostoSuscripciones();
    DtVideojuego dtVid(this->nombre,this->descripcion,dtPrecios.getMensual(),dtPrecios.getTrimestral(),dtPrecios.getAnual(),dtPrecios.getVitalicia());
    return dtVid;
}

set<Jugador*>* Videojuego::obtenerJugadoresSuscriptos() {
    set<Jugador*>* setJugadores = new set<Jugador*>;
    for (set<Suscripcion*>::iterator it = suscripciones->begin(); it != suscripciones->end(); ++it) {
        setJugadores->insert((*it)->getComprador()); 
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

//--- ConfirmarPartida Individual ---
void Videojuego::confirmarPartida(Jugador* host,int id,PartidaIndividual* pCont) {
    if (pCont != NULL) {
        DtPartidaIndividual dtPInd(id,fechaSistema::fecha,0,true,pCont->getId());
    } else {
        DtPartidaIndividual dtPInd(id,fechaSistema::fecha,0,true,-1);
    }
    PartidaIndividual* pInd = new PartidaIndividual(dtPInd); 
    pInd->setHost(host);
    pInd->setPartidaAnterior(pCont);
    pInd->setVideojuego(this);
    host->agregarPartida(pInd); 
    this->partidas->insert(pInd);
}

//--- confirmarPartida Multijugador ---
void Videojuego::confirmarPartida(Jugador* host,int id,bool enVivo,map<string,Jugador*>* jUnidos) {
    DtPartidaMultijugador dtPMulti(id,fechaSistema::fecha,0,true,enVivo);
    PartidaMultijugador* pMulti = new PartidaMultijugador(dtPMulti); 
    pMulti->setHost(host);
    pMulti->setPartidaAnterior(pCont);
    pMulti->setVideojuego(this);
    host->agregarPartida(pMulti); 
    this->partidas->insert(pMulti);
}

void Videojuego::cancelarSuscripcion(Jugador* host) {
    for (set<Suscripcion*>::iterator it = suscripciones->begin(); it != suscripciones->end(); ++it) {
        if ((*it)->esDeJugador(host)) {
            static_cast<SuscripcionTemporal*>((*it))->cancelarSuscripcion();
        }
    }
}

void Videojuego::confirmarSuscripcion(Jugador* host,TipoValido tipoVal,TipoPago tipoPago) {
    DtFechaHora fechaHoraActual(); 
    if (tipoVal != TipoValido::Vitalicia) {
        SuscripcionTemporal* nuevaSus = new SuscripcionTemporal(tipoVal,TipoEstado::Activa,fechaSistema::fecha,tipoPago,host,this);
	host->agregarSuscripcion(nuevaSus);
	this->suscripciones->insert(nuevaSus);
    } else {
        SuscripcionVitalicia* nuevaSus = new SuscripcionVitalicia(fechaSistema::fecha,tipoPago,host,this);
	host->agregarSuscripcion(nuevaSus);
        this->suscripciones->insert(nuevaSus);
    }
}

void Videojuego::eliminarInfoAsociada() {
    for (map<int,Partida*>::iterator it = partidas->begin(); it != partidas->end(); ++it) {
        it->second->eliminarAssoc();
        delete it->second;
    }
    for (set<Suscripcion*>::iterator it = suscripciones->begin(); it != suscripciones->end(); ++it) {
        (*it)->eliminarAssoc();
        delete *it;
    }
}

//--- Getters ---
string Videojuego::getNombre() {
    return this->nombre;
}

string Videojuego::getDescripcion() {
    return this->descripcion;
}

DtPrecios Videojuego::getCostoSuscripciones() {
    return this->costoSuscripciones;
}

float Videojuego::getTotalHorasJugadas() {
    return this->totalHorasJugadas;
}

float Videojuego::getPuntaje() {
    return this->puntaje;
}

int Videojuego::getTotalJugadoresSuscriptos() {
    return this->totalJugadoresSuscriptos;
}

set<Suscripcion*>* Videojuego::getSuscripciones() {
    return this->suscripciones;
}

map<int,Partida*>* Videojuego::getPartidas() {
    return this->partidas;
}

map<string,Categoria*>* Videojuego::getCategorias() {
    return this->categorias;
}

void Videojuego::addOpinion(int i){
    opiniones->push_back(i);
}

//--- Setters ---
void Videojuego::setNombre(string nombre) {
    this->nombre = nombre;
}

void Videojuego::setDescripcion(string descripcion) {
    this->descripcion = descripcion;
}

void Videojuego::setCostoSuscripciones(DtPrecios costoSuscripciones) {
    this->costoSuscripciones = costoSuscripciones;
}

void Videojuego::setTotalHorasJugadas(float totalHorasJugadas) {
    this->totalHorasJugadas = totalHorasJugadas;
}

void Videojuego::setPuntaje(float puntaje) {
    this->puntaje = puntaje;
}

void Videojuego::setTotalJugadoresSuscriptos(int totalJugadoresSuscriptos) {
    this->totalJugadoresSuscriptos = totalJugadoresSuscriptos;
}
