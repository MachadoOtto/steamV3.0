/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef GENERO
#define GENERO

#include <string>
#include "tipoGenero.h"

class Genero : public Categoria {
    private:
        
    public:
        Genero(DtCategoria);
        ~Genero();

        virtual DtCategoria getDt();
}

#endif
