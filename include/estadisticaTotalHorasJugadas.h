/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef ESTADISTICATOTALHORASJUGADAS
#define ESTADISTICATOTALHORASJUGADAS

#include <string>
#include "estadistica.h"
#include "videojuego.h"
#include "dtEstadistica.h"

using std::string;

class EstadisticaTotalHorasJugadas: public Estadistica{
public:
    virtual DtEstadistica procesarEstadistica(Videojuego*);
    EstadisticaTotalHorasJugadas(string,string);
};

#endif
