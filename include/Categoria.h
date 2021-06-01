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
#include "DtCategoria.h"

class Categoria {
    private:
        std::string nombre;
        std::string descripcion;
    public:
        Categoria();
        DtCategoria getDt();
}

#endif