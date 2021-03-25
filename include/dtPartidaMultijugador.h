/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Baladon 
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef DT_PARTIDA_MULTIJUGADOR
#define DT_PARTIDA_MULTIJUGADOR

#include <string>
#include "dtPartida.h"

class DtPartidaMultijugador : public DtPartida{
private:
    bool transmitidaEnVivo;
    std::string nicknameJugadoresUnidos;
    int cantidadJugadoresUnidos;
public:
    DtPartidaMultijugador(bool,ListaJugador * ,DtFechaHora,float);
    std::string getNicknameJugadoresUnidos();
    int getCantidadJugadoresUnidos();
    bool getTransmitidaEnVivo();
    virtual Partida * fabricarPartida(Jugador *,ListaJugador *);

};

//Funciones de sobrecarga de flujo
std::ostream &operator<<(std::ostream &, DtPartidaMultijugador &);

#endif
