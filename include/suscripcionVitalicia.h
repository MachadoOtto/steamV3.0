/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef SuscripcionVitalicia
#define SuscripcionVitalicia

#include "suscripcion.h"

class SuscripcionVitalicia: public Suscripcion{
public:
    virtual bool esActiva();
};

#endif
