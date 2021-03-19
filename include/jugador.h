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
    std::string nickname;
    int edad;
    std::string constrasena;
public:
    Jugador(std::string,int,std::string);
    DtJugador getDt();
};

class DtJugador{
private:
    std::string nickname;
    int edad;
public:
    DtJugador(std::string,int);

    std::string getNickname();
    int getEdad();
};
#endif
