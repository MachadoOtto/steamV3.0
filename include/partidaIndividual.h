/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Integrantes:
 *      Alexis Baladon (5.574.612-4) - alexis.baladon@fing.edu.uy
 *      Guillermo Toyos (5.139.879-9) - guillermo.toyos@fing.edu.uy
 *      Jorge Machado (4.876.616-9) - jorge.machado.ottonelli@fing.edu.uy
 *      Juan Jose Mangado (5.535.227-0) - juan.mangado@fing.edu.uy
 *      Mathias Ramilo (5.665.788-5) - mathias.ramilo@fing.edu.uy
 */

#ifndef PARTIDA_INDIVIDUAL
#define PARTIDA_INDIVIDUAL

#include "dtPartidaIndividual.h"
#include "partida.h"
#include "fechaSistema.h"

class DtFechaHora;
class Jugador;
class Videojuego;
class DtPartida;

class PartidaIndividual: public Partida {
    private:
        PartidaIndividual* partidaAnterior;
    public:
        PartidaIndividual(DtPartidaIndividual);
        float getDuracion();
        void setPartidaAnterior(PartidaIndividual*);
        PartidaIndividual* getPartidaAnterior();
        virtual void asignarHoraFinalizacion();
        ~PartidaIndividual();
};

#endif
