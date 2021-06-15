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
    if(estado==TipoEstado::Activa){
	float delta = fecha.diffHoras(fechaSistema::fecha);
	//Se asume que un dia tiene 24hs, un mes tiene 730 horas, un anio 8760 horas
	float x=0.0;
	if(validez == TipoValido::UnMes)
	    x=730.0;
	if(validez == TipoValido::TresMeses)
	    x=2190.0;
	if(validez == TipoValido::Anio)
	    x=8760.0;
	if(delta > x){
	    estado=TipoEstado::Inactiva;
	    return false;
	}
	else
	    return true;
    }
    return false;
}

void SuscripcionTemporal::cancelarSuscripcion(){
    estado = TipoEstado::Inactiva; //En el uml pusieron un estado llamada cancelada. Por que?
}

DtSuscripcion SuscripcionTemporal::getDt(){
    this->esActiva();
    return DtSuscripcion(this->getFecha(),pago,validez,estado);
}

SuscripcionTemporal::SuscripcionTemporal(TipoValido t, TipoEstado ve,DtFechaHora dt,TipoPago tp,Jugador *j, Videojuego *v): Suscripcion(dt,tp,j,v){
    validez = t;
    estado = ve;
}

