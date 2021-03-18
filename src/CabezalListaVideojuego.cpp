#include "../src/CabezalListaVideojuego.h"

CabezalListaVideojuego::CabezalListaVideojuego() {
    largoActual = 0;
    videojuegos = NULL;
}

CabezalListaJugador::~CabezalListaJugador() {
    if(jugadores != NULL) {
        delete * videojuegos; //se supone que 'delete' está redefinido
    }
}

void CabezalListaJugador::insertar(Jugador nuevoVideojuego) {
    ListaVideojuego nuevaLista(nuevoVideojuego);
    nuevaLista->siguiente = videojuegos;
    videojuegos = nuevaLista;
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