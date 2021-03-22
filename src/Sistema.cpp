#include "include/Videojuego.h"
#include "include/Partida.h"
#include "include/Jugador.h"
#include "include/PartidaIndividual.h"
#include "include/PartidaMultijugador.h"
#include "include/DtVideouego.h"
#include "include/DtPartida.h"
#include "include/DtJugador.h"
#include "include/DtFechaHora.h"
#include "include/DtPartidaIndividual.h"
#include "include/DtPartidaMultijugador.h"
#include "include/Sistema.h"

#define MAX_JUGADORES
#define MAX_VIDEOJUEGOS
#define MAX_PARTIDAS

DtPartida** obtenerPartidas(string videojuego, int& cantPartidas) {
    if (existeVideojuego(videojuego)) {
        cantPartidas = cantidadPartidas;
        DtPartida **arregloPartidas = new DtPartida* [cantPartidas];
        ListaPartidas list = partidas;
        for (int i = 0; i < cantPartidas; i++) {
            arregloPartidas[i] = list.getPartida()->getDt(); 
            list.next;
        }
        return arregloPartidas;
    } else {
        throw std::invalid_argument("El videojuego ingresado no existe");
    }
}

