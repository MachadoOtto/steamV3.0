/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class implementation 
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "../include/suscripcion.h"

DtVideojuego * Suscripcion::obtenerVideojuego(){
    return vj->obtenerDatoVideojuego();
}

bool Suscripcion::esDeJugador(Jugador *x){
    return x==comprador;
}

void Suscripcion::eliminarAssoc(){
    comprador->removeSus(this);
}

Suscripcion::Suscripcion(DtFechaHora *f,TipoPago x,Jugador * j,Videojuego * v){
    fecha = f;
    pago = x;
    comprador = j;
    vj = v;
}

Suscripcion::~Suscripcion(){
    delete fecha;
}
