/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef CATEGORIA
#define CATEGORIA

#include <string>
#include "dtCategoria.h"
#include "tipoCategoria.h"

using std::string;

class Categoria {
    private:
        string nombre;
        string descripcion;
    public:
        Categoria(DtCategoria);
        string getNombre();
        string getDescripcion();
        ~Categoria();
        
        virtual DtCategoria getDt();
};

#endif
