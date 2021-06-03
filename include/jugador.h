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

#include <string>

class Jugador: public Usuario {
    private:
        std::string empresa;
    public:
        Jugador();
        std::set<std::string> * obtenerVidejuegosActivos();
        std::set<DtVideojuego> * obtenerDatosVj();
        std::set<std::string> * getVjSinPartidasActivas();
        std::set<DtPartida> * obtenerPartidasActivas();
        std::set<DtPartidaindividual> * obtenerHistorialPartidas(Videojuego *);
        Partidaindividual * seleccionarContinuacionPartida(int);
        void agregarPartida(Partida *);
        void agregarSuscripcion(Suscripcion *);
        void abandonarPartidaMulti(PartidaMultijugador *);
        void finPartida(int);
};

#endif
