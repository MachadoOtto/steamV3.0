/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Baladón
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef LISTA_PARTIDA
#define LISTA_PARTIDA

#include "partida.h"
#include <string>
#include "jugador.h"

class ListaPartida{
private:
    Partida * match;
    ListaPartida * sig;
public:
    ListaPartida(Partida *);
    ~ListaPartida();
    void masacre();

    void add(Partida *);
    ListaPartida * next();
    //bool esVacia();
    Partida * getPartida();
};

#endif