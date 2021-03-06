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

DtVideojuego::DtVideojuego(string n,string d,float men,float tri,float an,float vita):costos(men,tri,an,vita){
    nombre = n;
    descripcion = d;
}

string DtVideojuego::getNombre() const{
    return nombre;
}

string DtVideojuego::getDescripcion() const{
    return descripcion;
}

DtPrecios DtVideojuego::getDtPrecios() const{
    return costos;
}

DtVideojuego::~DtVideojuego(){ }

bool operator<(const DtVideojuego dt1, const DtVideojuego dt2) {
    return (dt1.nombre < dt2.nombre);
}

ostream& operator<<(ostream& o, DtVideojuego game) {
    o << "Nombre: " << game.getNombre() << ".\n" << "Descripcion: " << game.getDescripcion()
        << ".\n" << game.getDtPrecios();
    return o;
}
