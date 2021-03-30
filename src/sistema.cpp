/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
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
    if ((lol=findVideojuego(nombre)) != nullptr) 
        throw std::invalid_argument("Ya existe un videojuego con el nombre \"" + lol->getDt().getNombre() + "\" en el sistema.");
    if(cantidadVideojuegos < MAX_VIDEOJUEGOS) {
	    lol = new Videojuego(nombre,genero); 
	    if(videojuegos == nullptr)
	        videojuegos = new ListaVideojuego(lol);
	    else
	        videojuegos->add(lol);    
	    cantidadVideojuegos++;
    }
}

void Sistema::agregarJugador(std::string nickname, int edad, std::string contrasenia) {
    Jugador * p;
    if((p=findJugador(nickname)) != nullptr)
	    throw std::invalid_argument("Ya existe un jugador con el nombre \"" + p->getDt().getNickname() + "\" en el sistema.");
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
    Videojuego* juego = findVideojuego(videojuego);
    if (juego != nullptr) { // Correccion de condicion del if (antes: == , ahora: !=).
	ListaPartida* list = juego->getPartidas();
	int card=0;
	while(list != nullptr){
	    card++;
	    list = list->next();
	}
	cantPartidas = card;
        DtPartida** arregloPartidas = new DtPartida*[card];
        list = juego->getPartidas();
        for (int i = 0; i < card; i++) {
            arregloPartidas[i] = list->getPartida()->getDt(); 
            list = list->next();
        }
        return arregloPartidas;
    }
    else 
	throw std::invalid_argument("El videojuego \"" + videojuego + "\" no existe en el sistema.");
}

void Sistema::iniciarPartida(std::string nickname, std::string videojuego, DtPartida* datos) {
    Videojuego * v;
    if (findJugador(nickname) == nullptr)
        throw std::invalid_argument("El jugador \"" + nickname + "\" no se encuentra registrado en el sistema.");
    if ((v = findVideojuego(videojuego)) == nullptr)
        throw std::invalid_argument("El videojuego \"" + videojuego + "\" no se encuentra registrado en el sistema.");
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
