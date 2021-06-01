#ifndef IFPARTIDASINTERFACE
#define IFPARTIDASINTERFACE

#include <string>

class IFPartidasinterface {
    private:
        IFPartidasinterface();
        static IFPartidasinterface * instancia;
    public:
        static IFPartidasinterface * getInstance() = 0;
        //Set(string) obtenerVideojuegosActivos() = 0;
        //Set(DtPartida) obtenerPartidasActivas() = 0;
        //Set(DtPartidaIndividual) obtenerHistorialPartidas() = 0;
        //Set(string) obtenerJugadoresSubscriptos() = 0;
        //void seleccionarVideojuego(string) = 0;
        void seleccionarContinuacionPartida(int) = 0;
        void partidaEnVivo(bool) = 0;
        void aniadirJugadorPartida(std::string) = 0;
        void confirmarPartida() = 0;
        void confirmarFinalizarPartida(int) = 0;
        void clearCache() = 0;
};

#endif