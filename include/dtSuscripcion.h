/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef DTSUS
#define DTSUS

#include <set>
#include <string>
#include <iostream>
#include "tipoPago.h"
#include "tipoEstado.h"
#include "tipoValido.h"
#include "dtFechaHora.h"

using std::ostream;
using std::string;

class DtSuscripcion{
private:
    DtFechaHora fecha;
    TipoPago pago;
    TipoValido tipo;
    TipoEstado estado;
public:
    DtSuscripcion(DtFechaHora,TipoPago,TipoValido,TipoEstado);
    DtFechaHora getFecha();
    TipoPago getPago();
    TipoValido getTipo();
    TipoEstado getEstado();
    friend bool operator<(const DtSuscripcion, const DtSuscripcion);

    // Sobrecarga del operador de flujo.
    friend ostream& operator<<(ostream&, DtSuscripcion);
};

#endif
