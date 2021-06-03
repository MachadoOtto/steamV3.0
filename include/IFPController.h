#ifndef IFPCONTROLLER
#define IFPCONTROLLER

#include "HandlerUsuario.h"
#include "HandlerCatalogo.h"
#include "IIFPController.h"

#include <string>

class IFPController: public IIFPController {
    private:
        IFPController();
        static IFPController * instancia;
        bool pCont;
        bool enVivo;
    public:
        static virtual IFPController * getInstance();
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