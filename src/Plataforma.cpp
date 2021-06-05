/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "Plataforma.h"
#include "tipoPlataforma.h"
#include "dtCategoria.h"

Plataforma::Plataforma(DtCategoria dtCat) {
    nombre = dtCat.getNombre();
    descripcion = dtCat.getDescripcion();
}

std::string Plataforma::getNombre() {
    return nombre;
}

std::string Plataforma::getDescripcion() {
    return descripcion;
}

Plataforma::~Plataforma() {
    
}

DtCategoria Plataforma::getDt() {
    DtCategoria dtCat(nombre,descripcion,tipoCategoria::Genero);
    return dtCat;
}
