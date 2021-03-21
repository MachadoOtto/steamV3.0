#include "include/ListaPartidas.h"

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
