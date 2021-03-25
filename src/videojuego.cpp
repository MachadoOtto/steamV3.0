/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Baladón
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "../include/videojuego.h"

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