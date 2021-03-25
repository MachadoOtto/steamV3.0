/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Baladon 
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
#include "dtVideojuego.h"

class Videojuego {
private:
    std::string nombre;
    TipoJuego genero;
    ListaPartida  * partidas;
public:
    Videojuego(std::string, TipoJuego);
    ~Videojuego();
    DtVideojuego getDt();    
    ListaPartida * getPartidas();
    void agregarPartida(Partida *);
};

#endif
