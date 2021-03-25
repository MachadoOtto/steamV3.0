/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Baladón
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "../include/listaPartida.h"

ListaPartida::ListaPartida(Partida * pp){
    match = pp; 
    sig = nullptr;
}

ListaPartida::~ListaPartida(){
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