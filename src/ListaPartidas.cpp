#include "include/ListaPartidas.h"

ListaPartidas::ListaPartidas() {
    partida = NULL;
    siguiente = NULL;
}

ListaPartidas::ListaPartidas(Partida nuevaPartida) {
    partida = nuevaPartida;
    siguiente = NULL;
}

ListaPartidas::setPartida(Partida nuevaPartida) {
    partida = nuevaPartida;
}

ListaPartidas::getPartida() {
    return partida;
}
