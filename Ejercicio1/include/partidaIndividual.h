/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Baladon 
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef PARTIDA_INDIVIDUAL
#define PARTIDA_INDIVIDUAL

#include <string>
#include "dtFechaHora.h"
#include "partida.h"

class Partida;
class Jugador;
class DtPartida;

class PartidaIndividual: public Partida{
private:
    bool continuarPartidaAnterior;
public:
    PartidaIndividual(bool,DtFechaHora,float,Jugador*);

    virtual float darTotalHorasParticipantes();
    virtual DtPartida * getDt();
};

#endif
