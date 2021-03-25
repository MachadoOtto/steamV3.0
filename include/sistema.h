/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Baladón
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef SISTEMA
#define SISTEMA

#include <string>
#include "jugador.h"
#include "partida.h"
#include "videojuego.h"
#include "constraints.h"
#include "tipoJuego.h"
#include "listaJugador.h"
#include "listaPartida.h"
#include "listaVideojuego.h"

class Sistema{
private:
    ListaJugador * jugadores;
    ListaVideojuego * videojuegos;
    ListaPartida * partidas;
    int cantidadJugadores;
    int cantidadVideojuegos;
    int cantidadPartidas;
public:
    Sistema();
    ~Sistema();

    /*Funcionalidades solicitadas*/
    void agregarJugador(std::string,int,std::string);
    void agregarVideojuego(std::string,TipoJuego);
    DtJugador** obtenerJugadores(int&);
    DtVideojuego** obtenerVideojuegos(int&);
    DtPartida** obtenerPartidas(std::string,int&);
    void iniciarPartida(std::string,std::string,DtPartida*);

    /*Auxiliares*/
    Videojuego * findVideojuego(std::string nombre);
    Jugador * findJugador(std::string nombre);
};

#endif

