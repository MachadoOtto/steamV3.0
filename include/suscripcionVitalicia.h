/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef SuScripcionVitalicia
#define SuScripcionVitalicia

#include "suscripcion.h"

class SuscripcionVitalicia: public Suscripcion{
public:
    SuscripcionVitalicia(DtFechaHora, TipoPago, Jugador *, Videojuego *);
    DtSuscripcion getDt();
    virtual bool esActiva();
};

#endif
