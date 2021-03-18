#ifndef LISTAJUGADOR
#define LISTAJUGADOR

#include "Jugador.h"

class ListaJugador {
    private:
        Jugador jugador;
        
    public:
        ListaJugador * siguiente;
        ListaJugador * anterior;
        ListaJugador(Jugador);
        void setJugador(Jugador);
        Jugador getJugador();
};

#endif