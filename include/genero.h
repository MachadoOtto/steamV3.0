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
#include "dtCategoria.h"
#include "categoria.h"

class Genero : public Categoria {
public:
    Genero(DtCategoria);
    ~Genero();
    virtual DtCategoria getDt();
};


#endif
