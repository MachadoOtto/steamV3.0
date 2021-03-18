#ifndef CABEZALLISTAJUGADORES
#define CABEZALLISTAJUGADORES

#include "ListaJugador.h"

class CabezalListaJugador {
    private:
        static int largoMax = MAX_JUGADORES;
        int largoActual;
        ListaJugador * jugadores;
    public:
        CabezalListaJugador();
        ~CabezalListaJugador();
        int getLargoActual();
        void setLargoActual(int);
        ListaJugador getJugadores();
        void insertar(Jugador);
        bool estaJugador(Jugador);
        bool esVaciaLista();
};

#endif