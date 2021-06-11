/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef DTvideojuego
#define DTvideojuego

#include <string>
#include "dtPrecios.h"

using std::string;

class DtVideojuego{
private:
    string nombre;
    string descripcion;
    DtPrecios costos;
public:
    DtVideojuego(string nombre,string desc,float men,float tri,float an, float vita);
    string getNombre() const;
    string getDescripcion() const;
    DtPrecios getDtPrecios();
    ~DtVideojuego();
    friend bool operator<(const DtVideojuego, const DtVideojuego);  
};

#endif
