#ifndef IIFPCONTROLLER
#define IIFPCONTROLLER

#include <string>

class IIFPController {
    private:
        IIFPController();
        static IIFPController * instancia;
    public:
        static IIFPController * getInstance() = 0;
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