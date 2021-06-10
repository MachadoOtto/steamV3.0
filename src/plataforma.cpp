/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "../include/plataforma.h"

Plataforma::Plataforma(DtCategoria dtCat):Categoria(dtCat){
}

Plataforma::~Plataforma() {}

DtCategoria Plataforma::getDt() {
    DtCategoria dtCat(this->getNombre(),this->getDescripcion(),TipoCategoria::Plataforma);
    return dtCat;
}
