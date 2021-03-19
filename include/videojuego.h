/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Ramilo
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef VIDEOJUEGO
#define VIDEOJUEGO

#include <string>
#include "tipoJuego.h"
#include "listaPartida.h"
class Videojuego {
private:
    std::string nombre;
    TipoJuego genero;
    ListaPartida partidas;
public:
    Videojuego(std::string, TipoJuego);
    DtVideojuego getDt();    
    //ListaPartidas getListaPartidas();
};

class DtVideojuego {
private:
    std::string nombre;
    TipoJuego genero;
    float totalHorasDeJuego;
public:
    DtVideojuego(std::string, TipoJuego,float);
    std::string getNombre();
    TipoJuego getGenero();
    float getTotalHorasDeJuego();
};
#endif

