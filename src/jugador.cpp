/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Implementacion de clase 
 * Autores (por nombre):
 * 	Alexis Ramilo
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */
#include "../include/jugador.h"
#include <string>

Jugador::Jugador(std::string nick, int age, std::string passwd){
    nickname = nick;
    edad = age;
    contrasena = passwd;
}

DtJugador Jugador::getDt(){
    DtJugador pkg(nickname,edad);
    return pkg;
}

DtJugador::DtJugador(std::string n, int e){
   nickname = n;
   edad = e;
}

std::string DtJugador::getNickname(){
    return nickname;
}

int DtJugador::getEdad(){
    return edad;
}

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





