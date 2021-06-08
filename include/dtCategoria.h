/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef DTcategoria
#define DTcategoria

#include <string>
#include "tipoCategoria.h"

using std::string;

class DtCategoria{
private:
    string nombre;
    string descripcion;
    TipoCategoria tipo;
public:
    DtCategoria(string nom, string desc, TipoCategoria);
    string getNombre();
    string getDescripcion();
    TipoCategoria getTipoCategoria();
};

#endif
