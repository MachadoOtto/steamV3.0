/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Baladon 
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef DT_PARTIDA_INDIVIDUAL
#define DT_PARTIDA_INDIVIDUAL

#include <string>
#include "dtPartida.h"
#include "dtFechaHora.h"
#include "partida.h"

class Jugador;
class ListaJugador;

class DtPartidaIndividual : public DtPartida {
private:
    bool continuaPartidaAnterior;
public:
    DtPartidaIndividual(bool,DtFechaHora,float);
    bool getContinuaPartidaAnterior();
    virtual Partida * fabricarPartida(Jugador *,ListaJugador *);

    //Funciones de sobrecarga de flujo
    friend std::ostream &operator<<(std::ostream &, DtPartidaIndividual &);
};

#endif
