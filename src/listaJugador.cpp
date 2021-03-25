/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Baladon 
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "../include/listaJugador.h"
#include "../include/jugador.h"
#include <string>

ListaJugador::ListaJugador(Jugador * pp){
    player = pp; 
    sig = nullptr;
}

ListaJugador::~ListaJugador(){
    delete sig;
}

void ListaJugador::add(Jugador * pp){
    ListaJugador * tmp = sig;
    sig = new ListaJugador(pp);
    sig->sig = tmp;
}
ListaJugador * ListaJugador::next(){
    return sig;
};
Jugador * ListaJugador::getJugador(){
    return player;
};

void ListaJugador::masacre(){
    if(sig == NULL){
	delete player;
	return;
    }
    sig->masacre();
    delete player;
}
