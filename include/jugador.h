/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Ramilo
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */
#ifndef JUGADOR
#define JUGADOR

#include <string>
class Jugador{
private:
    string nickname;
    int edad;
    string constrasena;
public:
    Jugador(string,int,string);
    DtJugador getDt();
};

class DtJugador{
private:
    string nickname;
    int edad;
public:
    DtJugador(string,int);

    string getNickname();
    int getEdad();
};
#endif
