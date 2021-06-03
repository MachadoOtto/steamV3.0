#ifndef IIFPCONTROLLER
#define IIFPCONTROLLER

#include "dtPartida.h"
#include "dtPartidaIndividual.h"

#include <string>
#include <set>

class IIFPController {
    private:
        IIFPController();
    public:
        static IIFPController * getInstance();
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
