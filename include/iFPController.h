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
        virtual void setHost(Jugador *);
        virtual Jugador * getHost();
        virtual void setVj(Videojuego *);
        virtual Videojuego * getVj();
        virtual void setPartida(Partida *);
        virtual Partida * getPartida();
        virtual void setPCont(bool);
        virtual bool getPCont();
        virtual void setEnVivo(bool);
        virtual bool getEnVivo();
        virtual void add(Jugador *);
        virtual void remove(Jugador *);
        virtual Jugador * find(std::string);

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
