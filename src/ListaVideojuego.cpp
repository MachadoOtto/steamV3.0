#include "../include/ListaVideojuego.h"

ListaVideojuego::ListaVideojuego(Videojuego nuevoVideojuego) {
    videojuego = nuevoVideojuego;
    videojuego->siguiente = NULL;
    videojuego->anterior = NULL;
}

void ListaVideojuego::setVideojuego(Videojuego nuevoVideojuego) {
    videojuego = nuevoVideojuego;
}
Videojuego ListaVideojuego::getVideojuego() {
    return videojuego;
}
