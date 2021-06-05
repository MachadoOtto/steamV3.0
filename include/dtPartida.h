#ifndef DTPARTIDA
#define DTPARTIDA

#include "dtFechaHora.h"

#include <iostream>

class DtPartida {
    private:
        int id;
        DtFechaHora fecha;
        float duracion;
        bool activa;
    public:
        DtPartida(int,DtFechaHora,float,bool);
        int getId();
        DtFechaHora getFecha();
        float getDuracion();
        bool getActiva();
        bool esActiva();
        friend & operator << (std::ostream,DtPartida); //falta
};

#endif
