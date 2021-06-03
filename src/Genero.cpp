/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "Genero.h"
#include "tipoGenero.h"

Genero::Genero(DtCategoria dtCat) {
    nombre = dtCat.getNombre();
    descripcion = dtCat.getDescripcion();
}

std::string Genero::getNombre() {
    return nombre;
}

std::string Genero::getDescripcion() {
    return descripcion;
}

Genero::~Genero() {
    
}

DtCategoria Genero::getDt() {
    DtCategoria dtCat(nombre,descripcion,tipoCategoria::Genero);
    return dtCat;
}
