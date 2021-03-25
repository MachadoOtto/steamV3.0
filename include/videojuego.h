/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Ramilo
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef VIDEOJUEGO
#define VIDEOJUEGO

#include <string>
#include "tipoJuego.h"
#include "partida.h"

class DtVideojuego;
class ListaVideojuego;

class Videojuego {
private:
    std::string nombre;
    TipoJuego genero;
    ListaPartida  * partidas;
public:
    Videojuego(std::string, TipoJuego);
    ~Videojuego();
    DtVideojuego getDt();    
    ListaPartida * getPartidas();
    void agregarPartida(Partida *);
};

class DtVideojuego {
private:
    std::string nombre;
    TipoJuego genero;
    float totalHorasDeJuego;
public:
    DtVideojuego(std::string = "", TipoJuego = TipoJuego::Otro,float = 0.0);
    std::string getNombre();
    TipoJuego getGenero();
    float getTotalHorasDeJuego();
};

class ListaVideojuego{
private:
    Videojuego * video;
    ListaVideojuego * sig;
public:
    ListaVideojuego(Videojuego *);
    ~ListaVideojuego();

    void add(Videojuego *);
    ListaVideojuego * next();
    void masacre(); //luego delete l;
    Videojuego * getVideojuego();
};


#endif

