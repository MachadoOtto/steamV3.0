/* Laboratorio Programacion IV - INCO/FING/UDELAR
    Laboratorio 0 - Modulo de clase
    Autores (por nombre):
  	    Alexis Ramilo
  	    Guillermo Toyos
  	    Jorge Machado
        Juan Jose Mangado
        Mathias Ramilo
*/

#include "../include/videojuego.h"

/* Operaciones de Clase Videojuego */

Videojuego::Videojuego(std::string name, TipoJuego gen) {
    nombre = name;
    genero = gen;
    partidas = nullptr;
}

Videojuego::~Videojuego(){
    delete partidas;
};

DtVideojuego Videojuego::getDt() {
    DtVideojuego dt_v(nombre, genero);
    return dt_v;
}

ListaPartida * Videojuego::getPartidas(){
    return partidas;
}

void Videojuego::agregarPartida(Partida * p){
    if(partidas==nullptr)
	partidas = new ListaPartida(p);
    else
	partidas->add(p);
}
/* Operaciones de Clase DtVideojuego */

DtVideojuego::DtVideojuego(std::string name, TipoJuego gen, float f) {
    nombre = name;
    genero = gen;
    totalHorasDeJuego = f;
//    totalHorasDeJuego = 0.0;
}
// #Guille: El totalHorasDeJuego se setea al construir el objeto.
// Incrementa 'totalHorasDeJuego' en la cantidad pasada por el float 'thour'.
//void DtVideojuego::setTotalHoras(float thour) {
//    totalHorasDeJuego += thour;
//}
        
std::string DtVideojuego::getNombre() {
    return nombre;
}

TipoJuego DtVideojuego::getGenero() {
    return genero;
}

float DtVideojuego::getTotalHorasDeJuego() {
    return totalHorasDeJuego;
}

/* Operaciones de Clase ListaVideojuegos */

ListaVideojuego::ListaVideojuego(Videojuego *game) {
    video = game;
    sig = nullptr;
}
/*
ListaVideojuego::~ListaVideojuego() {
    if (!(sig->esVacia()))
        sig->~ListaVideojuego();
    delete video;
}
*/ //Con esta funcion estas deleteando todos los videojuegos, pero la lista permanece intacta ver:
ListaVideojuego::~ListaVideojuego(){
    delete sig;
}

// Añade un Videojuego a la ListaVideojuego existente.
void ListaVideojuego::add(Videojuego *game) {
    ListaVideojuego *aux = new ListaVideojuego(game);
    aux->sig = this->sig;
    this->sig = aux;
}

ListaVideojuego * ListaVideojuego::next() {
    return sig;
}

void ListaVideojuego::masacre(){
    if(sig == nullptr){
	delete video;
	return;
    }
    sig->masacre();
    delete video;
}

Videojuego* ListaVideojuego::getVideojuego() {
    return video;
}

