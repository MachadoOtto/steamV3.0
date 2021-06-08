/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef DTDESARROLLADOR
#define DTDESARROLLADOR

#include <string>
#include "dtUsuario.h"

using std::string;

class DtDesarrollador: public DtUsuario{
private:
    string empresa;
public:
    DtDesarrollador(string m,string name, string pass);
    string getEmpresa();
};

#endif
