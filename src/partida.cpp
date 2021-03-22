/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Implementacion de clase 
 * Autores (por nombre):
 * 	Alexis Ramilo
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "../include/partida.h"
#include "../include/jugador.h"
#include "<iostream>"
#include "<string.h>"

Partida::Partida(DtFechaHora d, float f, Jugador * p){
    fecha = d;
    duracion = f;
    host = p;
}

float Partida::getDuracion(){
    return duracion;
}

DtFechaHora Partida::getFecha(){
    return fecha;
}

Partida * Partida::fabricarPartida(DtPartidaIndividual d,Jugador * host, ListaJugador * invitees){
    Partida * p = new PartidaIndividual(d.getContinuarPartidaAnterior(),d.getFecha(),d.getDuracion(),host);
    return p;
}
//Limitacion: El nickname de un usuario no puede contener comas.
Partida * Partida::fabricarPartida(DtPartidaMultijugador d,Jugador * host, ListaJugador * jugadoresSystema){
    ListaJugador * invitees = nullptr;
    std::string invstr = d.getNicknameJugadoresUnidos();
    int i=0,j=0;
    while(j < invstr.length()){
	if(invstr[j] == ','){
	    Jugador * p = findJugador(invstr(i,j-1));
	    if(p == nullptr)
	        throw std::invalid_argument("Uno de los jugadores invitados a la partida no se encuentra registrado.");
	    if(invitees == nullptr)
	        invitees = new ListaJugador(p);
	    else
	        invitees.add(p);
	    i=j+2;
	    j++;
	}
	j++;
    }
    Partida * p = new PartidaMultijugador(d.transmitidaEnVivo(),d.getFecha(),d.getDuracion(),host,invitees);
    return p;

static Jugador * findJugador(std::string nombre) {
    ListaJugador * list_player = jugadores;
    while (list_player != nullptr) {
        if (nombre == ( (list_player.getJugador()->getDt()).getNickname()))
            return list_player->getJugador(); 
	list_player = list_player->next();
    }
    return nullptr; 
}

PartidaIndividual::PartidaIndividual(bool b,DtFechaHora d, float f, Jugador * p):
    Partida(d,f,p){
    continuarPartidaAnterior = b;
}

float PartidaIndividual::darTotalHorasParticipantes(){
    return duracion;
}:

DtPartidaIndividual PartidaIndividual::getDt(){
    DtPartidaIndividual pkg(continuarPartidaAnterior,fecha,duracion);
    return pkg;
}

PartidaMultijugador::PartidaMultijugador(bool b,DtFechaHora d, float f, Jugador * p, ListaJugador * l):
    Partida(d,f,p){
    transmitidaEnVivo = b;
    invitados = l;
}

float PartidaMultijugador::darTotalHorasParticipantes(){
    int cantidad=0;
    ListaJugador * inv = invitados;
    while(inv != nullptr){
	cantidad++;
	inv = inv.next();
    }
    return this->getDuracion()*(cantidad+1); //+1 para incluir al host. 
}

DtPartidaMultijugador PartidaMultijugador::getDt(){
    DtPartidaMultijugador pkg(transmitidaEnVivo,invitados,this->getFecha(),this->getDuracion());
    return pkg;
}

DtPartida::DtPratida(DtFechaHora d,float f){
    fecha =d;
    duracion=f;
}
DtFechaHora DtPartida::getFecha(){
    return fecha;
}
float DtPartida::getDuracion(){
    return duracion;
}

DtPartidaIndividual::DtPartidaIndividual(bool b,DtFechaHora d, float f):
    DtPartida(d,f){
    continuaPartidaAnterior = b;
}

bool DtPartidaIndividual::getContinuaPartidaAnterior(){
    return continuaPartidaAnterior;
}

DtPartidaMultijugador::DtPartidaMultijugador(bool b, ListaJugador * pp, DtFechaHora d, float f): DtPartida(d,f){
    transmitidaEnVivo = b;
    nicknameJugadoresUnidos = "";
    cantidadJugadoresUnidos = 0;
    Jugador * jug = nullptr;
    DtJugador dtJug();
    while(pp != nullptr){
	cantidadJugadoresUnidos++;
	jug = pp->getJugador();
	dtJug = jug->getDt();
	nicknameJugadoresUnidos = nicknameJugadoresUnidos + ", " + dtJug.getNickname();
	pp = pp->next();
    }
} 

std::string DtPartidaMultijugador::getNicknameJugadoresUnidos(){
    return nicknameJugadoresUnidos;
}

int DtPartidaMultijugador::getCantidadJugadoresUnidos(){
    return cantidadJugadoresUnidos;
}

bool DtPartidaMultijugador::getTransmitidaEnVivo(){
    return transmitidaEnVivo;
}


ListaPartida::ListaPartida(Partida * pp){
    match = pp; 
    sig = nullptr;
}

ListaJugador::~ListaJugador(){
    delete sig;
}

void ListaPartida::add(Partida * pp){
    ListaPartida * tmp = sig;
    sig = new ListaPartida(pp);
    sig->sig = tmp;
}
ListaPartida * ListaPartida::next(){
    return sig;
};
Partida * ListaPartida::getPartida(){
    return match;
};

void ListaPartida::masacre(){
    if(sig == nullptr){
	delete match;
	return;
    }
    sig->masacre();
    delete match;
}



