/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Integrantes:
 *      Alexis Baladon (5.574.612-4) - alexis.baladon@fing.edu.uy
 *      Guillermo Toyos (5.139.879-9) - guillermo.toyos@fing.edu.uy
 *      Jorge Machado (4.876.616-9) - jorge.machado.ottonelli@fing.edu.uy
 *      Juan Jose Mangado (5.535.227-0) - juan.mangado@fing.edu.uy
 *      Mathias Ramilo (5.665.788-5) - mathias.ramilo@fing.edu.uy
 */

#ifndef PARTIDA
#define PARTIDA

#include "dtFechaHora.h"
#include "dtPartida.h"
#include "fechaSistema.h"

class Jugador;
class Videojuego;

class Partida {
    private:
        int identificador;
        DtFechaHora fecha;
        bool activa;
        Jugador* host;
        Videojuego* videogame;
    protected:
        float duracion;
        Partida(DtPartida);
    public:
        int getId();
        Jugador* getHost();
        DtFechaHora getDtFechaHora();
        virtual float getDuracion() = 0;
        void setDuracion(float);
        void setActiva(bool);
        bool esActiva();
        void setHost(Jugador*);
        void remove(Jugador*);
        void setVideojuego(Videojuego*);
        Videojuego* getVideojuego();
        virtual void asignarHoraFinalizacion()=0;
        void finalizarPartida();
        virtual void eliminarAssoc()=0;
        virtual ~Partida();
};

#endif
