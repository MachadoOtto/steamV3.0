/* Laboratorio Programacion IV - INCO/FING/UDELAR 
 * Integrantes:
 *      Alexis Baladon (5.574.612-4) - alexis.baladon@fing.edu.uy
 *      Guillermo Toyos (5.139.879-9) - guillermo.toyos@fing.edu.uy
 *      Jorge Machado (4.876.616-9) - jorge.machado.ottonelli@fing.edu.uy
 *      Juan Jose Mangado (5.535.227-0) - juan.mangado@fing.edu.uy
 *      Mathias Ramilo (5.665.788-5) - mathias.ramilo@fing.edu.uy
 */

#ifndef IIFPCONTROLLER
#define IIFPCONTROLLER

#include <string>
#include <set>
#include <map>
#include <vector>

class Jugador;
class Videojuego;
class Partida;
class PartidaIndividual;
class DtPartida;
class DtPartidaIndividual;
class DtPartidaMultijugador;
class DtFechaHora;

class IIFPController {
    public:
        virtual void iniciarSesion() = 0;
        virtual void setHost(Jugador*) = 0;
        virtual Jugador* getHost() = 0;
        virtual void seleccionarVideojuego(std::string) = 0;
        virtual void setVj(Videojuego*) = 0;
        virtual Videojuego* getVj() = 0;
        virtual void seleccionarContinuacionPartida(int) = 0;
        virtual void setPartidaAnterior(PartidaIndividual*) = 0;
        virtual Partida* getPartidaAnterior() = 0;
        virtual void setEnVivo(bool) = 0;
        virtual bool getEnVivo() = 0;
        virtual void add(Jugador *) = 0;
        virtual void remove(Jugador *) = 0;
        virtual void aniadirJugadorPartida(std::string) = 0;
        virtual Jugador* findJugador(std::string) = 0;
		
        virtual std::set<std::string> * obtenerVideojuegosActivos() = 0;
        virtual std::vector<DtPartida*>* obtenerPartidasActivas() = 0;
        virtual std::vector<DtPartidaIndividual*>* obtenerHistorialPartidas() = 0;
        virtual std::vector<DtPartidaMultijugador*>* obtenerPartidasMultiActivas() = 0;
        virtual std::set<std::string> * obtenerJugadoresSubscriptos() = 0;
        
        virtual void confirmarPartida() = 0;
        virtual void confirmarFinalizarPartida(int) = 0;
	    virtual void confirmarAbandonarPartida(int)=0;
        virtual void clearCache() = 0;

	    virtual ~IIFPController(){}
};

#endif
