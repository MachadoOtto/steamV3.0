/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef Estadistica
#define Estadistica

#include <string>
#include "estadistica.h"
#include "videojuego.h"
#include "dtEstadistica.h"

using std::string;

class EstadisticaTotalJugadoresSuscriptos: public Estadistica{
public:
    virtual DtEstadistica* procesarEstadistica(Videojuego*);
    EstadisticaTotalJugadoresSuscriptos(string,string);
};

