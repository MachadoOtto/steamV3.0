#include "../include/ListaJugador.h"

ListaJugador::ListaJugador(Jugador nuevoJugador) {
    jugador = nuevoJugador;
    jugador->siguiente = NULL;
    jugador->anterior = NULL;
}

void ListaJugador::setJugador(Jugador nuevoJugador) {
    jugador = nuevoJugador;
}
Jugador ListaJugador::getJugador() {
    return jugador;
}