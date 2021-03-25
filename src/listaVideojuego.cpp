/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Baladon 
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "../include/listaVideojuego.h"

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