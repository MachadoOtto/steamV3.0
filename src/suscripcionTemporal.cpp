/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class implementation 
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "../include/suscripcionTemporal.h"

bool SuscripcionTemporal::esActiva(){
    return estado==TipoEstado::Activa;
}

void SuscripcionTemporal::cancelarSuscripcion(){
    estado = TipoEstado::Inactiva; //En el uml pusieron un estado llamada cancelada. Por que?
}

SuscripcionTemporal::SuscripcionTemporal(TipoValido t, TipoEstado v,DtFechaHora *dt,TipoPago tp,Jugador *j,Videojuego *v): Suscripcion(dt,tp,j,v){
    validez = t;
    estado = v;
}

