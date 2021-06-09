/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class implementation 
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "../include/estadistica.h"

Estadistica::Estadistica(string name,string desc){
    nombre = name;
    descripcion = desc;
}

string Estadistica::getNombre(){
    return nombre;
}

string Estadistica::getDescripcion(){
    return descripcion;
}