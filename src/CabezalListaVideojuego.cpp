#include "../include/CabezalListaVideojuego.h"

CabezalListaVideojuego::CabezalListaVideojuego() {
    largoActual = 0;
    videojuegos = NULL;
}

CabezalListaVideojuego()::~CabezalListaVideojuego() {
    Videojuego * aux1 = videojuegos;
    while(aux1) {
        Videojuego * aux2 = videojuegos->siguiente;
        delete aux1
        aux1 = aux2;
    }
    videojuegos = NULL;
}

void CabezalListaVideojuego::insertar(Jugador nuevoVideojuego) {
    ListaVideojuego * nuevaLista(nuevoVideojuego);
    nuevaLista->siguiente = videojuegos;
    videojuegos = nuevaLista;
    if (nuevaLista->siguiente)
        nuevaLista->siguiente->anterior = videojuegos;
}

int CabezalListaVideojuego::getLargoActual() {
    return largoActual;
}

void CabezalListaVideojuego::setLargoActual(int largoNuevo) {
    largoActual = largoNuevo;
}

bool CabezalListaVideojuego::estaVideojuego(Videojuego videojuegoBuscado) {
    bool res = 0;
    ListaVideojuego * iterador = videojuegos;
    while(iterador) { // NULL = true
        if(iterador->videojuego == videojuegoBuscado) {
            res = 1;
        }
    }
    return res;
}

bool CabezalListaVideojuego::esVaciaLista() {
    return videojuegos;
}