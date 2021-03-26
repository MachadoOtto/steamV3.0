/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Baladon 
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef PARTIDA_MULTIJUGADOR
#define PARTIDA_MULTIJUGADOR

#include <string>
//#include "partida.h"
#include "listaJugador.h"

class Partida;

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
