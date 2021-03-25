/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Baladón
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef LISTA_JUGADOR
#define LISTA_JUGADOR

#include "jugador.h"

/*
 * La clase ListaJugador permite tener una lista encadenada de Jugadores.
 * La siguiente tiene las siguientes caracteristicas: 
 * ListaJugador * l = NULL; representa la lista vacia.
 * l->add(jugadorptr); agrega un nuevo nodo entre l y el consecutivo al mismo con el
 * puntero al nuevo jugador.
 * sigl = l->next(); Retorna el siguiente nodo de la lista. Si l es el ultimo nodo se retorna nullptr 
 */

class ListaJugador{
private:
    Jugador * player;
    ListaJugador * sig;
public:
    ListaJugador(Jugador *);
    ~ListaJugador();

    void add(Jugador *);
    ListaJugador * next();
    Jugador * getJugador();

    void masacre(); //tras la masacre: delete l;
};

#endif