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

class Jugador;
class Videojuego;

class Partida {
private:
    int identificador;
    DtFechaHora fecha;
    float duracion;
    bool activa;
    Jugador* host;
    Videojuego* videogame;
public:
    virtual Partida(DtPartida*)=0;
    int getId();
    DtFechaHora getDtFechaHora();
    float getDuracion();
    void setActiva(bool);
    bool esActiva();
    void setHost(Jugador*);
    Jugador* getHost();
    void setVideojuego(Videojuego*);
    Videojuego* getVideojuego();
    bool esIgualVideojuego(Videojuego*);
    void asignarHoraFinalizacion(DtFechaHora);
    virtual DtPartida* obtenerDatosPartida()=0;
    virtual void finalizarPartida()=0;
    virtual void eliminarAssoc()=0;
    virtual void remove(Jugador*)=0;
    virtual ~Partida()=0;
};

#endif