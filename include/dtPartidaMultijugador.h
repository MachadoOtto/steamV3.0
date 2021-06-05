#ifndef DTPARTIDAMULTIJUGADOR
#define DTPARTIDAMULTIJUGADOR

#include "dtPartida.h"
#include "dtFechaHora"

class DtPartidaMultijugador: public DtPartida {
    private:
        bool transmitidaEnVivo;
    public:
        DtPartidaMultijugador(int,DtFechaHora,float,bool,bool transmitidaEnVivo);
        bool getTransmitidaEnVivo();
        friend & operator << (std::ostream,DtPartida); //falta
};

#endif
