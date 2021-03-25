/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Baladón
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef PARTIDA_MULTIJUGADOR
#define PARTIDA_MULTIJUGADOR

#include "partida.h"
#include "dtPartida.h"
#include <string>
#include "jugador.h"
#include "dtFechaHora.h"
#include "listaJugador.h"

class PartidaMultijugador: public Partida{
private:
    bool transmitidaEnVivo;
    ListaJugador * invitados;   
public:
    PartidaMultijugador(bool,DtFechaHora,float,Jugador*,ListaJugador *);
    ~PartidaMultijugador();
    //ListaPartidas getInvitados();
    virtual float darTotalHorasParticipantes();
    virtual DtPartida *getDt(); 
};

#endif