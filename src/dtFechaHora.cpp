/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Baladón
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include <stdexcept>
#include "../include/dtFechaHora.h"

DtFechaHora::DtFechaHora(int d, int m, int a, int h, int min){
    if( (d < 1 || d > 31) || (m < 1 || m > 12) || (a < 1900) )
	throw std::invalid_argument("La fecha indicada no es valida");
    dia = d;
    mes = m;
    anio = a;
    hora = h;
    minuto = min;
}
DtFechaHora::DtFechaHora(const DtFechaHora &d){
    dia=d.dia;
    mes=d.mes;
    anio=d.anio;
    hora=d.hora;
    minuto=d.minuto;
}

DtFechaHora & DtFechaHora::operator=(DtFechaHora &d){
    if(this != &d){
	dia=d.dia;
	mes=d.mes;
	anio=d.anio;
	hora=d.hora;
	minuto=d.minuto;
    }
    return *this;
}
int DtFechaHora::getDia(){
    return dia;
}

int DtFechaHora::getMes(){
    return mes;
}

int DtFechaHora::getAnio(){
    return anio;
}

int DtFechaHora::getHora(){
    return hora;
}

int DtFechaHora::getMinuto(){
    return minuto;
}

