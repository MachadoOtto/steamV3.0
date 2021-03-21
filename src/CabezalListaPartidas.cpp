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
        delete aux1;
        aux1 = aux2;
    }
    partidas = NULL;
}

void CabezalListaPartidas::insertar(Partida nuevaPartida) {
    ListaPartidas * nuevaLista(nuevaPartida);
    nuevaLista->siguiente = partidas;
    partidas = nuevaLista;
}

int CabezalListaPartidas::getLargoActual() {
    return largoActual;
}

void CabezalListaPartidas::setLargoActual(int largoNuevo) {
    largoActual = largoNuevo;
}

bool CabezalListaPartidas::estaPartida(Partida partidaBuscada) {
    bool res = 0;
    ListaPartidas * iterador = partidas;
    while(iterador) { // NULL = true
        if(iterador->partida == partidaBuscada) {
            res = 1;
        }
    }
    return res;
}

bool CabezalListaPartidas::esVaciaLista() {
    return partidas;
}
