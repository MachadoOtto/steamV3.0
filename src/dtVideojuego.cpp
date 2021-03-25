/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Baladón
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "../include/dtVideojuego.h"

DtVideojuego::DtVideojuego(std::string name, TipoJuego gen, float f) {
    nombre = name;
    genero = gen;
    totalHorasDeJuego = f;
//    totalHorasDeJuego = 0.0;
}
// #Guille: El totalHorasDeJuego se setea al construir el objeto.
// Incrementa 'totalHorasDeJuego' en la cantidad pasada por el float 'thour'.
//void DtVideojuego::setTotalHoras(float thour) {
//    totalHorasDeJuego += thour;
//}
        
std::string DtVideojuego::getNombre() {
    return nombre;
}

TipoJuego DtVideojuego::getGenero() {
    return genero;
}

float DtVideojuego::getTotalHorasDeJuego() {
    return totalHorasDeJuego;
}