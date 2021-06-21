/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef SuScripcionTemporal
#define SuScripcionTemporal

#include "fechaSistema.h"
#include "suscripcion.h"
#include "tipoEstado.h"

enum class TipoValido;

class SuscripcionTemporal: public Suscripcion{
private:
    TipoValido validez;
    TipoEstado estado;
    bool cancelada;
public:
    virtual bool esActiva();
    DtSuscripcion getDt();
    void cancelarSuscripcion();
    SuscripcionTemporal(TipoValido,TipoEstado,DtFechaHora , TipoPago, Jugador *, Videojuego *);
};

#endif
