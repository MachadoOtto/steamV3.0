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

Videojuego::Videojuego(DtVideojuego datos, map<string,Categoria*> *cat): costoSuscripciones(datos.getDtPrecios()){
    nombre = datos.getNombre();
    descripcion = datos.getDescripcion();
    totalHorasJugadas = 0;
    puntaje = 0;
    totalJugadoresSuscriptos = 0; 
    categorias = cat;
    partidas = new map<int,Partida*>;
    suscripciones = new set<Suscripcion*>;
    opiniones = new map<string,int>;
}

Videojuego::~Videojuego() {
    delete categorias;
    for (map<int,Partida*>::iterator it = partidas->begin(); it != partidas->end(); ++it) {
        delete it->second;
    }
    delete partidas;
    for (set<Suscripcion*>::iterator it = suscripciones->begin(); it != suscripciones->end(); ++it) {
        delete (*it);
    }
    delete suscripciones;
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
    bool esActivo = false;
    for (map<int,Partida*>::iterator it = partidas->begin(); ((it != partidas->end()) && (!esActivo)); ++it) {
        esActivo = it->second->esActiva();
    }
    return esActivo;
}

//--- ConfirmarPartida Individual ---
void Videojuego::confirmarPartida(Jugador* host,int id,PartidaIndividual* pCont) {
    DtPartidaIndividual dtPInd(id,fechaSistema::fecha,0,true,-1);
    if (pCont != NULL) {
        dtPInd = DtPartidaIndividual(id,fechaSistema::fecha,0,true,pCont->getId());
    }
    PartidaIndividual* pInd = new PartidaIndividual(dtPInd); 
    pInd->setHost(host);
    pInd->setPartidaAnterior(pCont);
    pInd->setVideojuego(this);
    host->agregarPartida(pInd); 
    this->partidas->insert(map<int,Partida*>::value_type(pInd->getId(),pInd));
}

//--- confirmarPartida Multijugador ---
void Videojuego::confirmarPartida(Jugador* host,int id,bool enVivo,map<string,Jugador*>* jUnidos) {
    DtPartidaMultijugador dtPMulti(id,fechaSistema::fecha,0,true,enVivo);
    PartidaMultijugador* pMulti = new PartidaMultijugador(dtPMulti); 
    pMulti->setHost(host);
    pMulti->setVideojuego(this);
    pMulti->setJugadoresUnidos(jUnidos);
    host->agregarPartida(pMulti); 
    for (map<string, Jugador*>::iterator it = jUnidos->begin(); it != jUnidos->end(); ++it) {
        it->second->add(pMulti);
    }
    this->partidas->insert(map<int,Partida*>::value_type(pMulti->getId(),pMulti));
}

void Videojuego::cancelarSuscripcion(Jugador* host) {
    for (set<Suscripcion*>::iterator it = suscripciones->begin(); it != suscripciones->end(); ++it) {
        if ((*it)->esDeJugador(host) && (*it)->esActiva()) {
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
    float s = 0;
    for(map<int,Partida*>::iterator it= partidas->begin(); it!=partidas->end();++it){
	    s += it->second->getDuracion();
    }
    totalHorasJugadas = s;
    return totalHorasJugadas;
}

float Videojuego::getPuntaje() {
    int s = 0;
    for(map<string,int>::iterator it = opiniones->begin(); it != opiniones->end(); ++it) 
	s += it->second;
    if(!opiniones->size())
	puntaje=0;
    else
	puntaje = ((float)s)/((float)(opiniones->size()));
    return puntaje;
}

int Videojuego::getTotalJugadoresSuscriptos() {
    int i=0;
    set<Jugador*>* j = new set<Jugador*>;
    for(set<Suscripcion*>::iterator it=suscripciones->begin();it!=suscripciones->end();++it){
	if(j->find((*it)->getComprador()) == j->end()){
	    i++;
	    j->insert((*it)->getComprador());
	}
    }
    delete j;
    totalJugadoresSuscriptos = i; 
    return totalJugadoresSuscriptos;
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

int Videojuego::addOpinion(string email, int i) {
    int ex=0;
    if(opiniones->find(email) != opiniones->end())
	ex=1;
    (*opiniones)[email]=i;
    return ex;
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
