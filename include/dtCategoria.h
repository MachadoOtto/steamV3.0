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

#include <set>
#include <string>
#include <iostream>
#include "tipoCategoria.h"

using std::ostream;
using std::string;

class DtCategoria{
private:
    string nombre;
    string descripcion;
    TipoCategoria tipo;
public:
    DtCategoria(string nom, string desc, TipoCategoria);
    string getNombre() const;
    string getDescripcion();
    TipoCategoria getTipoCategoria();
    friend bool operator<(const DtCategoria, const DtCategoria);

    // Sobrecarga del operador de flujo.
    friend ostream& operator<<(ostream&, DtCategoria);
};

#endif