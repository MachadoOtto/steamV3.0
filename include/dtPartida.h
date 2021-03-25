/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Baladón
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef DT_PARTIDA
#define DT_PARTIDA

#include "partida.h"
#include <string>
#include "jugador.h"
#include "dtFechaHora.h"
#include "listaJugador.h"

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