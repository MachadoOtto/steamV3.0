/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "Jugador-Multi.h"
#include "dtFechaHora.h"

JugadorMulti::JugadorMulti(DtFechaHora fechaHora) {
    this->desconexion = fechaHora;
}

DtFechaHora JugadorMulti::getDesconexion() {
    return this->desconexion;
}

void JugadorMulti::setDesconexion(DtFechaHora fechaHora) {
    this->desconexion = fechaHora;
}

JugadorMulti::~JugadorMulti() {
    
}
