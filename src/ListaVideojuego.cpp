#include "ListaVideojuego.h"

ListaVideojuego::ListaVideojuego(Videojuego nuevoVideojuego) {
    videojuego = nuevoVideojuego;
}

void ListaJugador::setVideojuego(Videojuego nuevoVideojuego) {
    videojuego = nuevoVideojuego;
}
Videojuego ListaVideojuego::getVideojuego() {
    return videojuego;
}