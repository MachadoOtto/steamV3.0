/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Baladon 
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef DT_PARTIDA
#define DT_PARTIDA

#include <string>
//#include "jugador.h"
//#include "listaJugador.h"
#include "dtFechaHora.h"

//Foward declaration
class Partida;
class Jugador;
class ListaJugador;

class DtPartida {
private:
    DtFechaHora fecha;
    float duracion;
protected:
    DtPartida(DtFechaHora,float);
public:
    DtFechaHora getFecha();
    float getDuracion();
    virtual Partida * fabricarPartida(Jugador *,ListaJugador *)=0;
};

#endif
