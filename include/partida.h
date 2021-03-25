/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Ramilo
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */
#ifndef PARTIDA
#define PARTIDA

#include <string>
#include "jugador.h"
#include "dtFechaHora.h"

class DtPartida;
class DtPartidaIndividual;
class DtPartidaMultijugador;
class ListaPartida;

class Partida{
private:
    DtFechaHora fecha;
    float duracion;
    Jugador * host;
public:
    virtual float darTotalHorasParticipantes()=0;
    float getDuracion();
    DtFechaHora getFecha();
    //Partida * fabricarPartida(DtPartidaIndividual, Jugador *,ListaJugador *);
    //Partida * fabricarPartida(DtPartidaMultijugador, Jugador *,ListaJugador *);
    virtual DtPartida *getDt()=0;
    //Jugador * gethost()
protected:
    Partida(DtFechaHora, float, Jugador *);
};

class PartidaIndividual: public Partida{
private:
    bool continuarPartidaAnterior;
public:
    PartidaIndividual(bool,DtFechaHora,float,Jugador*);

    virtual float darTotalHorasParticipantes();
    virtual DtPartida * getDt();
};

class PartidaMultijugador: public Partida{
private:
    bool transmitidaEnVivo;
    ListaJugador * invitados;   
public:
    PartidaMultijugador(bool,DtFechaHora,float,Jugador*,ListaJugador *);
    ~PartidaMultijugador();
    //ListaPartidas getInvitados();
    virtual float darTotalHorasParticipantes();
    virtual DtPartida *getDt(); 
};

class DtPartida{
private:
    DtFechaHora fecha;
    float duracion;
protected:
    DtPartida(DtFechaHora,float);
public:
    DtFechaHora getFecha();
    float getDuracion();
    virtual Partida * fabricarPartida(Jugador *,ListaJugador *)=0;
};
class DtPartidaIndividual : public DtPartida{
private:
    bool continuaPartidaAnterior;
public:
    DtPartidaIndividual(bool,DtFechaHora,float);
    bool getContinuaPartidaAnterior();
    virtual Partida * fabricarPartida(Jugador *,ListaJugador *);
};
class DtPartidaMultijugador : public DtPartida{
private:
    bool transmitidaEnVivo;
    std::string nicknameJugadoresUnidos;
    int cantidadJugadoresUnidos;
public:
    DtPartidaMultijugador(bool,ListaJugador * ,DtFechaHora,float);
    std::string getNicknameJugadoresUnidos();
    int getCantidadJugadoresUnidos();
    bool getTransmitidaEnVivo();
    virtual Partida * fabricarPartida(Jugador *,ListaJugador *);

};

class ListaPartida{
private:
    Partida * match;
    ListaPartida * sig;
public:
    ListaPartida(Partida *);
    ~ListaPartida();
    void masacre();

    void add(Partida *);
    ListaPartida * next();
    //bool esVacia();
    Partida * getPartida();
};

//Funciones de sobrecarga de flujo
std::ostream &operator<<(std::ostream &, DtPartidaIndividual &);
std::ostream &operator<<(std::ostream &, DtPartidaMultijugador &);


#endif
