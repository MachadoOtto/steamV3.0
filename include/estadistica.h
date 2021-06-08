/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef EStadistica
#define EStadistica

#include <string>
#include "videojuego.h"
#include "dtEstadistica.h"

using std::string;

class Estadistica{
protected:
    string nombre;
    string descripcion;
    Estadistica(string name,string desc);
public:
    virtual DtEstadistica procesarEstadistica(Videojuego*)=0;
    string getNombre();
    string getDescripcion();
    virtual ~Estadistica();
};

#endif
