#ifndef JUGADOR
#define JUGADOR

#include "dtVideojuego.h"
#include "dtPartida.h"
#include "dtPartidaindividual.h"
#include "partidaindividual.h"
#include "partida.h"
#include "suscripcion"

#include <string>

class Jugador: public Usuario {
    private:
        std::string empresa;
    public:
        //Set(String) obtenerVidejuegosActivos();
        //Set(DtVidejuego) obtenerDatosVj();
        //Set(String) getVjSinPartidasActivas();
        //Set(DtPartida) obtenerPartidasActivas();
        //Set(DtPartidaindividual) obtenerHistorialPartidas();
        Partidaindividual seleccionarContinuacionPartida(int);
        void agregarPartida(Partida);
        void agregarSuscripcion(Suscripcion);
        void abandonarPartidaMulti(PartidaMultijugador);
        void finPartida(int);
};

#endif