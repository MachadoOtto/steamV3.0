#ifndef IIFPCONTROLLER
#define IIFPCONTROLLER

#include "dtPartida.h"
#include "dtPartidaIndividual.h"

#include <string>
#include <set>

class IIFPController {
    public:
        virtual void setHost(Jugador *) = 0;
        virtual Jugador * getHost() = 0;
        virtual void setVj(Videojuego *) = 0;
        virtual Videojuego * getVj() = 0;
        virtual void setPartida(Partida *) = 0;
        virtual Partida * getPartida() = 0;
        virtual void setPCont(bool) = 0;
        virtual bool getPCont() = 0;
        virtual void setEnVivo(bool) = 0;
        virtual bool getEnVivo() = 0;
        virtual void add(Jugador *) = 0;
        virtual void remove(Jugador *) = 0;
        virtual Jugador * find(std::string) = 0;

        virtual std::set<std::string> * obtenerVideojuegosActivos() = 0;
        virtual std::set<DtPartida> * obtenerPartidasActivas() = 0;
        virtual std::set<DtPartidaIndividual> * obtenerHistorialPartidas() = 0;
        virtual std::set<std::string> * obtenerJugadoresSubscriptos() = 0;
        virtual void seleccionarVideojuego(std::string) = 0;
        virtual void seleccionarContinuacionPartida(int) = 0;
        virtual void partidaEnVivo(bool) = 0;
        virtual void aniadirJugadorPartida(std::string) = 0;
        virtual void confirmarPartida() = 0;
        virtual void confirmarFinalizarPartida(int) = 0;
        virtual void clearCache() = 0;
};

#endif
