#ifndef LISTAVIDEOJUEGO
#define LISTAVIDEOJUEGO

#include "Videojuego.h"

class ListaVideojuego {
    private:
        Videojuego videojuego;
    public:
        ListaVideojuego * siguiente;
        ListaVideojuego * anterior;
        ListaVideojuego(Videojuego);
        void setVideojuego(Videojuego);
        Videojuego getVideojuego();
};

#endif
