/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class implementation 
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "../include/dtCategoria.h"

DtCategoria::DtCategoria(string n,string d,TipoCategoria t){
    nombre = n;
    descripcion = d;
    tipo = t;
}

string DtCategoria::getNombre(){
    return nombre;
}

string DtCategoria::getDescripcion(){
    return descripcion;
}

TipoCategoria DtCategoria::getTipoCategoria(){
    return tipo;
}
    