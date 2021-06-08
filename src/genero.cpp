/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "../include/genero.h"
#include "../include/tipoGenero.h"
#include "../include/dtCategoria.h"

Genero::Genero(DtCategoria dtCat): Categoria(dtCat){}

Genero::~Genero() {}

DtCategoria Genero::getDt() {
    DtCategoria dtCat(this->getNombre(),this->getDescripcion(),TipoCategoria::Genero);
    return dtCat;
}
