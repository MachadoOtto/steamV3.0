/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Baladón
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef PARTIDA
#define PARTIDA

#include <string>
#include "jugador.h"
#include "dtFechaHora.h"
#include "dtPartida.h"

class Partida{
private:
    DtFechaHora fecha;
    float duracion;
    Jugador * host;
public:
    virtual float darTotalHorasParticipantes()=0;
    float getDuracion();
    DtFechaHora getFecha();
    //Partida * fabricarPartida(DtPartidaIndividual, Jugador *,ListaJugador *);
    //Partida * fabricarPartida(DtPartidaMultijugador, Jugador *,ListaJugador *);
    virtual DtPartida *getDt()=0;
    //Jugador * gethost()
protected:
    Partida(DtFechaHora, float, Jugador *);
};

#endif