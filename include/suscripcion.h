/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef SuScripcion
#define SuScripcion

#include <vector>
#include "dtFechaHora.h"
#include "dtVideojuego.h"
#include "dtSuscripcion.h"

using std::vector;

enum class TipoPago;

class Videojuego;
class Jugador;

class Suscripcion{
protected:
    DtFechaHora fecha;
    TipoPago pago;
    Jugador * comprador;
    Videojuego * vj;
public:
    Videojuego * obtenerVideojuego();
    Jugador * getComprador();
    DtFechaHora getFecha();
    virtual bool esActiva()=0;
    virtual DtSuscripcion getDt()=0;
    bool esDeJugador(Jugador *);
    void eliminarAssoc();
    virtual ~Suscripcion();
protected:
    Suscripcion(DtFechaHora, TipoPago,Jugador *,Videojuego *);
};

#endif
