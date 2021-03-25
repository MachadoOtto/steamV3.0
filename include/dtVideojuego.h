/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Baladón
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef DT_VIDEOJUEGO
#define DT_VIDEOJUEGO

#include <string>
#include "tipoJuego.h"

class DtVideojuego {
private:
    std::string nombre;
    TipoJuego genero;
    float totalHorasDeJuego;
public:
    DtVideojuego(std::string = "", TipoJuego = TipoJuego::Otro,float = 0.0);
    std::string getNombre();
    TipoJuego getGenero();
    float getTotalHorasDeJuego();
};

#endif