/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Baladon 
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef LISTA_VIDEOJUEGO
#define LISTA_VIDEOJUEGO

#include <string>
#include "videojuego.h"
#include "tipoJuego.h"

class ListaVideojuego{
private:
    Videojuego * video;
    ListaVideojuego * sig;
public:
    ListaVideojuego(Videojuego *);
    ~ListaVideojuego();

    void add(Videojuego *);
    ListaVideojuego * next();
    void masacre(); //luego delete l;
    Videojuego * getVideojuego();
};

#endif