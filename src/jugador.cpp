#include "../include/jugador.h"
#include "../include/dtVideojuego.h"
#include "../include/dtPartida.h"
#include "../include/dtPartidaindividual.h"
#include "../include/partidaindividual.h"
#include "../include/partida.h"
#include "../include/suscripcion.h"

#include <set>
#include <iterator>

std::set<std::string> * obtenerVidejuegosActivos() {

}

std::set<DtVideojuego> * obtenerDatosVj() {
    std::set<DtVideojuego> * res = new std::set<DtVideojuego>;
    for(std::set<Suscripcion *>::const_iterator it = suscripciones->cbegin(); it != suscripciones->cend(); it++) {
        Suscripcion * s = *it;
        bool esAct = s->esActiva();
        if(esAct) {
            DtVideojuego dtvjAct = s->obtenerVideojuego();
            res->push_back(dtvjAct);
        }
    }
    return res;
}

std::set<std::string> * getVjSinPartidasActivas() {

}

std::set<DtPartida> * obtenerPartidasActivas() {

}

std::set<DtPartidaindividual> * obtenerHistorialPartidas(Videojuego *) {

}

Partidaindividual * seleccionarContinuacionPartida(int) {

}

void agregarPartida(Partida) {

}

void agregarSuscripcion(Suscripcion * sNueva) {
    suscripciones->insert(sNueva);
}

void abandonarPartidaMulti(PartidaMultijugador) {

}

void finPartida(int) {

}
