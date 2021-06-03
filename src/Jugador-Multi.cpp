/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "DtFechaHora.h"

Jugador-Multi::Jugador-Multi(DtFechaHora fechaHora) {
    this->desconexion = fechaHora;
}

DtFechaHora Jugador-Multi::getDesconexion() {
    return this->desconexion;
}

void Jugador-Multi::setDesconexion(DtFechaHora fechaHora) {
    this->desconexion = fechaHora;
}

Jugador-Multi::~Jugador-Multi() {
    delete Jugador-Multi;
}