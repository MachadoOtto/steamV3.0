#ifndef CABEZALLISTAJUGADORES
#define CABEZALLISTAJUGADORES

#include "ListaVideojuego.h"

class CabezalListaVideojuego {
    private:
        static int largoMax = MAX_VIDEOJUEGOS;
        int largoActual;
        ListaVideojuego * videojuegos;
    public:
        CabezalListaVideojuego();
        ~CabezalListaVideojuego();
        int getLargoActual();
        void setLargoActual(int);
        ListaVideojuego getVideojuegos();
        void insertar(Videojuego);
        bool estaVideojuego(Videojuego);
        bool esVaciaLista();
};

#endif
