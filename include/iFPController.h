#ifndef IFPCONTROLLER
#define IFPCONTROLLER

#include "iIFPController.h"
#include "dtPartida.h"
#include "dtPartidaIndividual.h"
#include "jugador.h"
#include "partidaindividual.h"

#include <string>
#include <set>

class IFPController: public IIFPController {
    private:
        IFPController();
        Jugador * host;
        Videojuego * vj;
        PartidaIndividual * partida;
        std::map<std::string,Jugador *> * jugadoresAUnir;
        static IFPController * instancia;
        bool pCont;
        bool enVivo;
    public:
        static virtual IFPController * getInstance();
        virtual std::set<std::string> * obtenerVideojuegosActivos();
        virtual std::set<DtPartida> * obtenerPartidasActivas();
        virtual std::set<DtPartidaIndividual> * obtenerHistorialPartidas(Videojuego *);
        virtual std::set<std::string> * obtenerJugadoresSubscriptos();
        virtual void seleccionarVideojuego(std::string);
        virtual void seleccionarContinuacionPartida(int);
        virtual void partidaEnVivo(bool);
        virtual void aniadirJugadorPartida(std::string);
        virtual void confirmarPartida();
        virtual void confirmarFinalizarPartida(int);
        virtual void clearCache();
        ~IFPController();
};

#endif
