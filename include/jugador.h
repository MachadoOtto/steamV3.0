/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Baladon 
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */
#ifndef JUGADOR
#define JUGADOR

#include <string>

class DtJugador;
class ListaJugador;

class Jugador{
private:
    std::string nickname;
    int edad;
    std::string contrasena;
public:
    Jugador(std::string,int,std::string);
    DtJugador getDt();
};

class DtJugador{
private:
    std::string nickname;
    int edad;
public:
    DtJugador(std::string = "", int = 0);

    std::string getNickname();
    int getEdad();
};

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
