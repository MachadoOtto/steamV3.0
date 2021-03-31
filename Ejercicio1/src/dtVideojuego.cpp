/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Baladon 
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "../include/dtVideojuego.h"

// Miguel: la duracion total del DtVideojuego 'j' se la pasa al construir el objeto desde videojuego.getDt();
DtVideojuego::DtVideojuego(std::string name, TipoJuego gen, float f) {
    nombre = name;
    genero = gen;
    totalHorasDeJuego = f;
}
        
std::string DtVideojuego::getNombre() {
    return nombre;
}

TipoJuego DtVideojuego::getGenero() {
    return genero;
}

float DtVideojuego::getTotalHorasDeJuego() {
    return totalHorasDeJuego;
}