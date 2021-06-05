/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef VIDEOJUEGO
#define VIDEOJUEGO

#include <map>
#include <set>
#include <string>
#include "Suscripcion.h"
#include "Partida.h"
#include "Categoria.h"
#include "Jugador.h"
#include "DtPrecios.h"

using std::string
using std::map
using std::set

class Videojuego {
    private:
        string nombre;
        string descripcion;
        DtPrecios costoSuscripciones;
        float totalHorasJugadas;
        float puntaje;
        int totalJugadoresSuscriptos;

        //Associations
        set<Suscripcion*> *suscripciones;
        map<int,Partida*> *partidas;
        map<string,Categoria*> *categorias;
        
    public:
        Videojuego(DtVideojuego,set<Categoria*>*);
        ~Videojuego();
        DtVideojuego obtenerDatosVideojuego();
        set<Jugador*>* obtenerJugadoresSuscriptos();
        bool estaActivo();
        void confirmarPartida(Jugador*,bool,bool,set<Jugador*>*);
        void cancelarSuscripcion(Jugador*);
        void confirmarSuscripcion(Jugador*,id,DtFechaHora,TipoSuscripcion,TipoPago);
        void eliminarInfoAsociada();

        //Getters
        string getNombre();
        string getDescripcion();
        DtPrecios getCostoSuscripciones();
        float getTotalHorasJugadas();
        float getPuntaje();
        int getTotalJugadoresSuscriptos();
        Suscripcion* getSuscripciones();
        map<int,Partida> getPartidas();
        Categoria* getCategorias();

        //Setters
        void setNombre(string);
        void setDescripcion(string);
        void setCostoSuscripciones(DtPrecios);
        void setTotalHorasJugadas(float);
        void setPuntaje(float);
        void setTotalJugadoresSuscriptos(int);
}
#endif
