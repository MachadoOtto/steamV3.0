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
#include "videojuego.h"
#include "dtEstadistica.h"

using std::string;

class Estadistica{
private:
    string nombre;
    string descripcion;
public:
    virtual DtEstadistica* procesarEstadistica(Videojuego*)=0;
protected:
    Estadistica(string name,string desc);
};

