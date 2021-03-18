#include "../src/CabezalListaJugador.h"

CabezalListaJugador::CabezalListaJugador() {
    largoActual = 0;
    jugadores = NULL;
}

CabezalListaJugador::~CabezalListaJugador() {
    if(jugadores != NULL) {
        delete * jugadores; //se supone que 'delete' está redefinido
    }
}

void CabezalListaJugador::insertar(Jugador nuevoJugador) {
    ListaJugador nuevaLista(nuevoJugador);
    nuevaLista->siguiente = jugadores;
    jugadores = nuevaLista;
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