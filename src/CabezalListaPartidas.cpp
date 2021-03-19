#include "include/CabezalListaPartidas.h"
#include "include/ListaPartidas.h"

CabezalListaPartidas::CabezalListaPartidas() {
    largoActual = 0;
    partidas = NULL;
}

CabezalListaPartidas::~CabezalListaPartidas() {
    Partida * aux1 = partidas;
    while(aux1 != NULL) {
        Partida * aux2 = partidas->siguiente;
        aux1 = aux2;
    }
    delete aux1;
    delete aux2;
    partidas = NULL;
}
