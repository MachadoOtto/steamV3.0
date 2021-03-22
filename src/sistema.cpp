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

Sistema::Sistema(){
    jugadores = nullptr;
    videojuegos = nullptr;
    partidas = nullptr;
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
    lol = new Videojuego(nombre,genero); 
    if(videojuegos == nullptr)
	videojuegos = new ListaVideojuego(lol);
    else
	videojuegos->add(lol);    
}
