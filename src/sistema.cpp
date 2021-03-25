/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Implementacion de clase 
 * Autores (por nombre):
 * 	Alexis Baladon 
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include <iostream>
#include <stdexcept>
#include <string>

#include "../include/sistema.h"
#include "../include/constraints.h"

Sistema::Sistema(){
    jugadores = nullptr;
    videojuegos = nullptr;
    partidas = nullptr;
    cantidadJugadores = 0;
    cantidadVideojuegos = 0;
    cantidadPartidas = 0;
}
Sistema::~Sistema(){
    if(jugadores != nullptr){
	jugadores->masacre();
	delete jugadores;
    }
    if(partidas != nullptr){
	partidas->masacre();
	delete partidas;
    }
    if(videojuegos != nullptr){
	videojuegos->masacre();
	delete videojuegos;
    }
}

void Sistema::agregarVideojuego(std::string nombre, TipoJuego genero){
    Videojuego * lol;
    ListaVideojuego *vt = videojuegos;
    DtVideojuego * d = new DtVideojuego();
    while(vt != nullptr){
	lol = vt->getVideojuego();
	*d = lol->getDt();
	if(nombre == d->getNombre())
	    throw std::invalid_argument("El videojuego ya existe en el sistema");
	vt = vt->next();
    }
    if(cantidadVideojuegos < MAX_VIDEOJUEGOS){
	lol = new Videojuego(nombre,genero); 
	if(videojuegos == nullptr)
	    videojuegos = new ListaVideojuego(lol);
	else
	    videojuegos->add(lol);    
	cantidadVideojuegos++;
    }
}

void Sistema::agregarJugador(std::string nickname, int edad, std::string contrasenia) {
    if(findJugador(nickname) != nullptr)
	throw std::invalid_argument("Ya hay un jugador con ese nombre.");
    if(cantidadJugadores < MAX_JUGADORES){ 
        Jugador * nuevoJugador = new Jugador(nickname,edad,contrasenia);
        if(jugadores == nullptr) 
	    jugadores = new ListaJugador(nuevoJugador);
        else
	    jugadores->add(nuevoJugador);
	cantidadJugadores++;
    } 
}

DtJugador** Sistema::obtenerJugadores(int & cantJugadores){
    ListaJugador * lista = jugadores;
    cantJugadores = cantidadJugadores;
    DtJugador **jugs = new DtJugador * [cantJugadores]; 
    for(int i = 0; i < cantJugadores; i++){
        jugs[i] = new DtJugador;
	*(jugs[i]) = lista->getJugador()->getDt();
        lista = lista->next();
    }
    return jugs;
}

DtVideojuego** Sistema::obtenerVideojuegos(int& cantVideojuegos) {
    cantVideojuegos = cantidadVideojuegos;
    DtVideojuego** arr_dt = new DtVideojuego*[cantVideojuegos];
    ListaVideojuego * list_aux = videojuegos;
    for (int i = 0; i < cantVideojuegos; i++){
	arr_dt[i] = new DtVideojuego;
        *(arr_dt[i]) = list_aux->getVideojuego()->getDt();
	list_aux = list_aux->next();
    }
    return arr_dt;
}

DtPartida** Sistema::obtenerPartidas(std::string videojuego, int& cantPartidas) {
    if (findVideojuego(videojuego) == nullptr) {
        cantPartidas = cantidadPartidas;
        DtPartida **arregloPartidas = new DtPartida* [cantPartidas];
        ListaPartida * list = partidas;
        for (int i = 0; i < cantPartidas; i++) {
            arregloPartidas[i] = list->getPartida()->getDt(); 
            list = list->next();
        }
        return arregloPartidas;
    } else {
        throw std::invalid_argument("El videojuego ingresado no existe");
    }
}

void Sistema::iniciarPartida(std::string nickname, std::string videojuego, DtPartida* datos) {
    Videojuego * v;
    if (findJugador(nickname) == nullptr)
        throw std::invalid_argument("Jugador no registrado en el Sistema");
    if ((v = findVideojuego(videojuego)) == nullptr)
        throw std::invalid_argument("Videojuego no ingresado en el Sistema");
    if(cantidadPartidas < MAX_PARTIDAS){
	//Partida * p = Partida::fabricarPartida(*datos,findJugador(nickname),jugadores);
	Partida * p = datos->fabricarPartida(findJugador(nickname),jugadores);
	if(partidas == nullptr)
	    partidas = new ListaPartida(p);
	else
	    partidas->add(p);
	cantidadPartidas++;
	v->agregarPartida(p);
    }
}

/* Operaciones Auxiliares */

Jugador * Sistema::findJugador(std::string nombre) {
    ListaJugador * list_player = jugadores;
    while (list_player != nullptr) {
        if (nombre == ( (list_player->getJugador()->getDt()).getNickname()))
            return list_player->getJugador(); 
	list_player = list_player->next();
    }
    return nullptr; 
}

Videojuego * Sistema::findVideojuego(std::string nombre) {
    ListaVideojuego * list_games = videojuegos;
    while (list_games != nullptr) {
        if (nombre == ( (list_games->getVideojuego()->getDt()).getNombre()))
            return list_games->getVideojuego(); 
        list_games = list_games->next();
    }
    return nullptr; 
}
