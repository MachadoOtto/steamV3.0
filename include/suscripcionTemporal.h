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

#include "suscripcion.h"
#include "tipoEstado.h"

enum class TipoValido;

class SuscripcionTemporal: public Suscripcion{
private:
    TipoValido validez;
    TipoEstado estado;
public:
    virtual bool esActiva();
    void cancelarSuscripcion();
    SuscripcionTemporal(TipoValido,TipoEstado,DtFechaHora , TipoPago, Jugador *, Videojuego *);
};

#endif
