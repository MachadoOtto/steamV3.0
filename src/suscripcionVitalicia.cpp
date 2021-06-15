/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class implementation 
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "../include/suscripcionVitalicia.h"

SuscripcionVitalicia::SuscripcionVitalicia(DtFechaHora dt, TipoPago tp, Jugador *j, Videojuego *v):
    Suscripcion(dt,tp,j,v){}

DtSuscripcion SuscripcionVitalicia::getDt(){
    return DtSuscripcion(this->getFecha(),pago,TipoValido::Vitalicia,TipoEstado::Activa);
}

bool SuscripcionVitalicia::esActiva(){
    return true;
}

