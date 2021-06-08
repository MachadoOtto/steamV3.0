/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */
#ifndef JUGADORMULTI 
#define JUGADORMULTI 

#include "dtFechaHora.h"

class JugadorMulti {
    private:
        DtFechaHora desconexion;
    public:
        JugadorMulti(DtFechaHora);
        DtFechaHora getDesconexion();
        void setDesconexion(DtFechaHora);
        ~JugadorMulti();
};

#endif
