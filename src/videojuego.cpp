/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Baladon 
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
    // Miguel: antes de dar el Dt se calcula la duracion total de partidas del videojuego. Ya que no se puede acceder a este
    //  atributo desde DtVideojuego.
    float duracion = 0.0;
    ListaPartida* iterador = partidas;
    while (iterador != nullptr) {
        duracion += iterador->getPartida()->darTotalHorasParticipantes();
        iterador = iterador->next();
    }
    DtVideojuego dt_v(nombre, genero, duracion);
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