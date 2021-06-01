/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class implementation 
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "../include/dtVideojuego.h"

DtVideojuego::DtVideojuego(string n,string d,float men,float an,float tri,float vita){
    nombre = n;
    descripcion = d;
    costos = new DtPrecios(men,tri,an,vita);
}

string DtVideojuego::getNombre(){
    return nombre;
}

string DtVideojuego::getDescripcion(){
    return descripcion;
}

DtPrecios* DtVideojuego::getDtPrecios(){
    return costos;
}

DtVideojuego::~DtVideojuego(){
    delete costos;
}
    
