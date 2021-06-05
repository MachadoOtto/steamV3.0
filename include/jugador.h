#ifndef JUGADOR
#define JUGADOR

#include "dtVideojuego.h"
#include "dtPartida.h"
#include "dtPartidaindividual.h"
#include "partidaindividual.h"
#include "partida.h"
#include "suscripcion"
#include "dtVideojuego.h"
#include "dtPartida.h"
#include "../include/JugadorMulti.h"

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
        Jugador(DtVideojuego);
        std::set<std::string> * obtenerVidejuegosActivos();
        std::set<DtVideojuego> * obtenerDatosVj();
        std::set<DtPartida> * obtenerPartidasActivas();
        std::set<DtPartidaindividual> * obtenerHistorialPartidas(Videojuego *);
        Partidaindividual * seleccionarContinuacionPartida(int);
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
