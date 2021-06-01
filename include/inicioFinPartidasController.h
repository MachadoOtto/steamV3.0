#ifndef INICIOFINPARTIDASCONTROLLER
#define INICIOFINPARTIDASCONTROLLER

#include HandlerUsuario
#include HandlerCatalogo

#include "iFPartidasInterface.h"
#include <string>

class InicioFinPartidasController: public IFPartidasInterface {
    private:
        InicioFinPartidasController();
        static InicioFinPartidasController * instancia;
        bool pCont;
        bool enVivo;
    public:
        static virtual InicioFinPartidasController * getInstance();
        //virtual Set(string) obtenerVideojuegosActivos();
        //virtual Set(DtPartida) obtenerPartidasActivas();
        //virtual Set(DtPartidaIndividual) obtenerHistorialPartidas();
        //virtual Set(string) obtenerJugadoresSubscriptos();
        //virtual void seleccionarVideojuego(string);
        virtual void seleccionarContinuacionPartida(int);
        virtual void partidaEnVivo(bool);
        virtual void aniadirJugadorPartida(std::string);
        virtual void confirmarPartida();
        virtual void confirmarFinalizarPartida(int);
        virtual void clearCache();
};

#endif