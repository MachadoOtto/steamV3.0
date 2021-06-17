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
    //if(estado==TipoEstado::Activa){
	float delta = fecha.diffHoras(fechaSistema::fecha);
	//Dado que el calendario no es uniforme, se toman los siguientes criterios para definir las suscripciones:
	//Una suscripcion de un mes es de 30 dias. Esto significa que las demas suscripciones son de 90 dias y 360 dias respectivamente.
	//Un dia tiene 24 horas.
	float x=0.0;
	if(validez == TipoValido::UnMes)
	    x=720.0;
	if(validez == TipoValido::TresMeses)
	    x=2160.0;
	if(validez == TipoValido::Anio)
	    x=8640.0;
	if(delta > x){
	    estado=TipoEstado::Inactiva;
	    return false;
	}
	else{
	    estado=TipoEstado::Activa;
	    return true;
	}
    //}
    return false;
}

void SuscripcionTemporal::cancelarSuscripcion(){
    estado = TipoEstado::Inactiva; 
}

DtSuscripcion SuscripcionTemporal::getDt(){
    this->esActiva();
    return DtSuscripcion(this->getFecha(),pago,validez,estado);
}

SuscripcionTemporal::SuscripcionTemporal(TipoValido t, TipoEstado ve,DtFechaHora dt,TipoPago tp,Jugador *j, Videojuego *v): Suscripcion(dt,tp,j,v){
    validez = t;
    estado = ve;
}

