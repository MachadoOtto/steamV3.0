/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Baladón
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef PARTIDA_INDIVIDUAL
#define PARTIDA_INDIVIDUAL

#include "partida.h"
#include "dtPartida.h"
#include <string>
#include "jugador.h"
#include "dtFechaHora.h"

class PartidaIndividual: public Partida{
private:
    bool continuarPartidaAnterior;
public:
    PartidaIndividual(bool,DtFechaHora,float,Jugador*);

    virtual float darTotalHorasParticipantes();
    virtual DtPartida * getDt();
};

#endif