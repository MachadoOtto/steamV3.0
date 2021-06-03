#ifndef DTPARTIDA
#define DTPARTIDA

#include "dtFechaHora.h"

class DtPartida {
    private:
        int id;
        DtFechaHora fecha;
        float duracion;
        bool activa;
    public:
        DtPartida(int,DtFechaHora,float,bool);
};

#endif
