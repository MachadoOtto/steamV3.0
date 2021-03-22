/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Implementacion de clase 
 * Autores (por nombre):
 * 	Alexis Ramilo
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include <iostream>
#include <stdexcept>

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

void Sistema::agregarVideojuego(string nombre, TipoJuego genero){
    Videojuego * lol;
    ListaVideojuego *vt = videojuegos;
    DtVideojuego d();
    while(vt != nullptr){
	lol = vt->getVideojuego();
	d = lol->getDt();
	if(nombre == d.getNombre())
	    throw std::invalid_argument("El videojuego ya existe en el sistema");
	vt = vt->next();
    }
    if(cantidadVideojuegos == MAX_VIDEOJUEGOS){
	lol = new Videojuego(nombre,genero); 
	if(videojuegos == nullptr)
	    videojuegos = new ListaVideojuego(lol);
	else
	    videojuegos->add(lol);    
	cantidadVideojuegos++;
    }
}

void Sistema::agregarJugador(std::string nickname, int edad, std::string contrasenia) {
    if(estaJugadorSistema(nickname)) { //supongo que funciona cuando jugadores es NULL
            throw std::invalid_argument("Ya hay un jugador con ese nombre.");
    }
    if(cantidadJugadores == MAX_JUGADORES){ 
        Jugador * nuevoJugador = new Jugador(nickname,edad,contrasenia);
        if(jugadores == nullptr) 
	    jugadores = new ListaJugadores(nuevoJugador);
        else
	    jugadores.add(nuevoJugador);
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
        lista = lista.next();
    }
    return jugs;
}

DtVideojuego** Sistema::obtenerVideojuegos(int& cantVideojuegos) {
    cantVideojuegos = cantidadVideojuegos;
    DtVideojuego** arr_dt = new DtVideojuego*[cantVideojuegos];
    ListaVideojuego * list_aux = Videojuegos;
    for (int i = 0; i < cantVideojuegos; i++){
	arr_dt[i] = new DtVideojuego;
        *(arr_dt[i]) = list_aux->getVideojuego()->getDt();
	list_aux = list_aux();
    }
    return arr_dt;
}

DtPartida** Sistema::obtenerPartidas(std::string videojuego, int& cantPartidas) {
    if (estaVideojuegoSistema(videojuego)) {
        cantPartidas = cantidadPartidas;
        DtPartida **arregloPartidas = new DtPartida* [cantPartidas];
        ListaPartidas list = partidas;
        for (int i = 0; i < cantPartidas; i++) {
	    arregloPartidas = new DtPartida;
            arregloPartidas[i] = list->getPartida()->getDt(); 
            list = list->next();
        }
        return arregloPartidas;
    } else {
        throw std::invalid_argument("El videojuego ingresado no existe");
    }
}

void Sistema::iniciarPartida(std::string nickname, std::string videojuego, DtPartida* datos) {
    if (!estaJugadorSistema(nickname))
        throw std::invalid_argument("Jugador no registrado en el Sistema");
    if (!estaVideojuegoSistema(videojuego))
        throw std::invalid_argument("Videojuego no ingresado en el Sistema");
    if(cantidadPartidas == MAX_PARTIDAS){
	Partida * p = new Partida(datos,nickname);
	if(partidas == nullptr)
	    partidas = new ListaPartida(p);
	else
	    partidas.add(p);
	cantidadPartidas++;
    }
}

/* Operaciones Auxiliares */

// Devuelve true si 'nombre' ya es un nickname presente en el sistema.
bool Sistema::estaJugadorSistema(std::string nombre) {
    ListaJugador * list_player = jugadores;
    while (list_player != nullptr) {
        if (nombre == ( (list_player.getJugador()->getDt()).getNickname()))
            return true;
	list_player = list_player->next();
    }
    return false;
}

// Devuelve true si 'nombre' ya es un videojuego presente en el sistema.
bool Sistema::estaVideojuegoSistema(std::string nombre) {
    ListaVideojuego * list_games = videojuegos;
    while (list_games != nullptr) {
        if (nombre == ( (list_games.getVideojuego()->getDt()).getNombre()))
            return true;
        list_games = list_games->next();
    }
    return false;
}
