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

Videojuego * Suscripcion::obtenerVideojuego(){
    return vj;
}

bool Suscripcion::esDeJugador(Jugador *x){
    return x==comprador;
}
DtFechaHora Suscripcion::getFecha(){
    return fecha;
}

Jugador * Suscripcion::getComprador(){
    return comprador;
}
Suscripcion::Suscripcion(DtFechaHora f,TipoPago x,Jugador * j,Videojuego * v){
    fecha = f;
    pago = x;
    comprador = j;
    vj = v;
}

Suscripcion::~Suscripcion(){}
