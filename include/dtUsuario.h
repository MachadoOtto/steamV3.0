/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef DTUSUARIO
#define DTUSUARIO 

#include <string>

using std::string;

class DtUsuario{
private:
    string email;
    string contrasenia;
public:
    DtUsuario(string m,string cont);
    string getEmail();
    string getContrasenia();
};

#endif
