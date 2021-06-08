/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef PLATAFORMA
#define PLATAFORMA

#include <string>
#include "tipoPlataforma.h"
#include "categoria.h"

class Plataforma : public Categoria {
    private:
    
    public:
        Plataforma(DtCategoria);
        ~Plataforma();

        virtual DtCategoria getDt();
};

#endif
