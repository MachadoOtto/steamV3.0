#ifndef SISTEMA
#define SISTEMA

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
#include "include/DtPartidaMultijugador"

class Sistema {
    private:
        DtJugadores *conjuntoJugadores;
        DtVideojuegos *conjuntoVideojuegos;
    public:
        void agregarJugador(string,int,string);
        void agregarVideojuego(string,TipoJuego);
        DtJugador** obtenerJugadores(int&);
        DtVideojuego** obtenerVidejuegos(int&);
        DtPartida** obtenerPartidas(string,int&);
        void iniciarPartida(string,string,DtPartida*);
};

#endif
