/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "categoria.h"
#include "tipoCategoria.h"
#include "dtCategoria.h"

Categoria::Categoria(DtCategoria dtCat) {
    nombre = dtCat.getNombre();
    descripcion = dtCat.getDescripcion();
}

std::string Categoria::getNombre() {
    return nombre;
}

std::string Categoria::getDescripcion() {
    return descripcion;
}

Categoria::~Categoria() {

}

DtCategoria Categoria::getDt() {
    DtCategoria dtCat(nombre,descripcion,TipoCategoria::Otro);
    return dtCat;
}
