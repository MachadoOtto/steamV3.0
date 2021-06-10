/* Laboratorio Programacion IV - INCO/FING/UDELAR 
 * Integrantes:
 *      Alexis Baladon (5.574.612-4) - alexis.baladon@fing.edu.uy
 *      Guillermo Toyos (5.139.879-9) - guillermo.toyos@fing.edu.uy
 *      Jorge Machado (4.876.616-9) - jorge.machado.ottonelli@fing.edu.uy
 *      Juan Jose Mangado (5.535.227-0) - juan.mangado@fing.edu.uy
 *      Mathias Ramilo (5.665.788-5) - mathias.ramilo@fing.edu.uy
 */

#ifndef JUGADOR
#define JUGADOR

#include "usuario.h"
#include "dtVideojuego.h"
#include "dtPartida.h"
#include "dtPartidaIndividual.h"
#include "partidaIndividual.h"
#include "partidaMultijugador.h"
#include "partida.h"
#include "suscripcion.h"
#include "dtVideojuego.h"
#include "dtPartida.h"
#include "dtJugador.h"
#include "jugadorMulti.h"

#include <string>
#include <set>
#include <map>

class Jugador: public Usuario {
    private:
        std::set<Suscripcion *> * suscripciones;
        std::map<int,Partida *> * partidas;
        std::set<JugadorMulti *> * jMultis;
        std::string nickname;
        std::string descripcion;
    public:
        Jugador(DtJugador);
        void setNickname(std::string);
        std::string getNickname();
        void setDescripcion(std::string);
        std::string getDescripcion();
        void add(Suscripcion *);
        void remove(Suscripcion *);
        void add(Partida *);
        Partida * find(int);
        void add(JugadorMulti *);
        void remove(JugadorMulti *);

        std::set<std::string> * obtenerVideojuegosActivos();
        std::set<DtVideojuego> * obtenerDatosVj();
        std::set<DtPartida> * obtenerPartidasActivas();
        std::set<DtPartidaIndividual> * obtenerHistorialPartidas(Videojuego *);
        PartidaIndividual * seleccionarContinuacionPartida(int);
        void agregarPartida(Partida *);
        void agregarSuscripcion(Suscripcion *);
        void abandonarPartidaMulti(PartidaMultijugador *);
        void finPartida(int);
        void associate(Partida *);
        void removeSus(Suscripcion *);
        void remove(Partida *);
        ~Jugador();
};

#endif
