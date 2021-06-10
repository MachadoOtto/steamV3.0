/* Laboratorio Programacion IV - INCO/FING/UDELAR 
 * Integrantes:
 *      Alexis Baladon (5.574.612-4) - alexis.baladon@fing.edu.uy
 *      Guillermo Toyos (5.139.879-9) - guillermo.toyos@fing.edu.uy
 *      Jorge Machado (4.876.616-9) - jorge.machado.ottonelli@fing.edu.uy
 *      Juan Jose Mangado (5.535.227-0) - juan.mangado@fing.edu.uy
 *      Mathias Ramilo (5.665.788-5) - mathias.ramilo@fing.edu.uy
 */

#ifndef IFPCONTROLLER
#define IFPCONTROLLER

#include "iIFPController.h"
#include "dtPartida.h"
#include "dtPartidaIndividual.h"
#include "jugador.h"
#include "partidaIndividual.h"
#include "handlerCatalogo.h"
#include "handlerUsuario.h"

#include <string>
#include <set>

class IFPController: public IIFPController {
    private:
        IFPController();
        Jugador * host;
        Videojuego * vj;
        PartidaIndividual * partida;
        std::map<std::string,Jugador *> * jugadoresAUnir;
        bool pCont;
        bool enVivo;
    public:
        static IFPController * getInstance();
        void setHost(Jugador *);
        Jugador * getHost();
        void setVj(Videojuego *);
        Videojuego * getVj();
        void setPartida(Partida *);
        Partida * getPartida();
        void setPCont(bool);
        bool getPCont();
        void setEnVivo(bool);
        bool getEnVivo();
        void add(Jugador *);
        void remove(Jugador *);
        Jugador * find(std::string);

        std::set<std::string> * obtenerVideojuegosActivos();
        std::set<DtPartida> * obtenerPartidasActivas();
        std::set<DtPartidaIndividual> * obtenerHistorialPartidas();
        std::set<std::string> * obtenerJugadoresSubscriptos();
        void seleccionarVideojuego(std::string);
        void seleccionarContinuacionPartida(int);
        void partidaEnVivo(bool);
        void aniadirJugadorPartida(std::string);
        void confirmarPartida();
        void confirmarFinalizarPartida(int);
        void clearCache();

	std::set<DtPartidaMultijugador>* obtenerPartidasMultiActivas();
	void confirmarAbandonarPartida(int);

        ~IFPController();
};

#endif
