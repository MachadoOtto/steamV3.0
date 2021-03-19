#include "../include/CabezalListaJugador.h"

CabezalListaJugador::CabezalListaJugador() {
    largoActual = 0;
    jugadores = NULL;
}

CabezalListaJugador::~CabezalListaJugador() {
    Jugador * aux1 = jugadores;
    while(aux1) {
        Jugador * aux2 = jugadores->siguiente;
        delete aux1
        aux1 = aux2;
    }
    jugadores = NULL;
}

void CabezalListaJugador::insertar(Jugador nuevoJugador) {
    ListaJugador * nuevaLista(nuevoJugador);
    nuevaLista->siguiente = jugadores;
    videoJugador = nuevaLista;
    if (nuevaLista->siguiente)
        nuevaLista->siguiente->anterior = jugadores;
}

int CabezalListaJugador::getLargoActual() {
    return largoActual;
}

void CabezalListaJugador::setLargoActual(int largoNuevo) {
    largoActual = largoNuevo;
}

bool CabezalListaJugador::estaJugador(Jugador jugadorBuscado) {
    bool res = 0;
    ListaJugador * iterador = jugadores;
    while(iterador) { // NULL = true
        if(iterador->jugador == jugadorBuscado) {
            res = 1;
        }
    }
    return res;
}

bool CabezalListaJugador::esVaciaLista() {
    return jugadores;
}