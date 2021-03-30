/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Baladon 
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef PARTIDA
#define PARTIDA

#include <string>
//#include "jugador.h"
#include "dtFechaHora.h"
#include "dtPartida.h"

class Jugador;

class Partida{
private:
    DtFechaHora fecha;
    float duracion;
    Jugador * host;
public:
    virtual float darTotalHorasParticipantes()=0;
    virtual ~Partida();
    float getDuracion();
    DtFechaHora getFecha();
    virtual DtPartida *getDt()=0;
    Jugador * getHost();
protected:
    Partida(DtFechaHora, float, Jugador *);
};

#endif
