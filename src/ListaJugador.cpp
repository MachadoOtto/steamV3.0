#include "ListaJugador.h"

ListaJugador::ListaJugador(Jugador nuevoJugador) {
    jugador = nuevoJugador;
}

void ListaJugador::setJugador(Jugador nuevoJugador) {
    jugador = nuevoJugador;
}
Jugador ListaJugador::getJugador() {
    return jugador;
}