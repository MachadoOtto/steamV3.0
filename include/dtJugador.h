/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef DTJUGADOR
#define DTJUGADOR

#include <string>
#include "dtUsuario.h"

using std::string;

class DtJugador: public DtUsuario{
private:
    string descripcion;
    string nickname;
public:
    DtJugador(string,string,string,string);
    string getNickname();
    string getDescripcion();
};

#endif
