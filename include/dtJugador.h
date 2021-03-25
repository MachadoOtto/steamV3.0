/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Baladon 
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef DT_JUGADOR
#define DT_JUGADOR

#include <string>

class DtJugador{
private:
    std::string nickname;
    int edad;
public:
    DtJugador(std::string = "", int = 0);

    std::string getNickname();
    int getEdad();
};

#endif