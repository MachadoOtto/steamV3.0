/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class implementation 
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "../include/dtSuscripcion.h"
using std::endl;

DtSuscripcion::DtSuscripcion(DtFechaHora f, TipoPago p, TipoValido v, TipoEstado e){
    fecha = f;
    pago = p;
    tipo = v;
    estado = e;
}
DtFechaHora DtSuscripcion::getFecha(){
    return fecha;
}

TipoPago DtSuscripcion::getPago(){
    return pago;
}

TipoValido DtSuscripcion::getTipo(){
    return tipo;
}

TipoEstado DtSuscripcion::getEstado(){
    return estado;
}

bool operator<(const DtSuscripcion dt1, const DtSuscripcion dt2) {
    return (dt1.fecha < dt2.fecha);
}

ostream& operator<<(ostream& o, DtSuscripcion cat) {
    o << "Fecha de compra: " << cat.fecha << endl;
    o << "Metodo de pago: ";
    if (cat.pago == TipoPago::Paypal)
	o << "Paypal\n";
    else
	o << "Tarjeta\n";
    o << "Periodo de suscripcion: ";
    if (cat.tipo == TipoValido::UnMes)
	o << "Un mes.\n";
    if (cat.tipo == TipoValido::TresMeses)
	o << "Tres meses.\n";
    if (cat.tipo == TipoValido::Anio)
	o << "Un anio.\n";
    if (cat.tipo == TipoValido::Vitalicia)
	o << "Vitalicia.\n";
    o << "Estado de suscripcion: ";
    if (cat.estado == TipoEstado::Activa)
	o << "Activa.\n";
    if (cat.estado == TipoEstado::Inactiva)
	o << "Inactiva.\n";
    return o;
}
