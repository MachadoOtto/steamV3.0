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

class Categoria {
    private:
        std::string nombre;
        std::string descripcion;
    public:
        Categoria(DtCategoria);
        std::string getNombre();
        std::string getDescripcion();
        ~Categoria();
        
        virtual DtCategoria getDt();
}

#endif
