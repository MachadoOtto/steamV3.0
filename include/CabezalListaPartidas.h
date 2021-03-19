#ifndef CABEZALLISTAPARTIDAS
#define CABEZALLISTAPARTIDAS

#include "ListaPartidas.h"

class CabezalListaPartidas {
    private:
        static int largoMax = MAX_PARTIDAS;
        int largoActual;
        ListaPartidas *partidas;
    public:
        CabezalListaPartidas();
        ~CabezalListaPartidas();
        int getLargoActual();
        void setLargoActual(int);
        ListaPartidas getPartidas();
        void insertar(Partida);
        bool estaPartida(Partida);
        bool esVaciaLista();
};

#endif
