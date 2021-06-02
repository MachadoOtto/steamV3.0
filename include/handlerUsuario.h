/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Integrantes:
 *      Alexis Baladon (5.574.612-4) - alexis.baladon@fing.edu.uy
 *      Guillermo Toyos (5.139.879-9) - guillermo.toyos@fing.edu.uy
 *      Jorge Machado (4.876.616-9) - jorge.machado.ottonelli@fing.edu.uy
 *      Juan Jose Mangado (5.535.227-0) - juan.mangado@fing.edu.uy
 *      Mathias Ramilo (5.665.788-5) - mathias.ramilo@fing.edu.uy
 */

#ifndef HANDLER_USUARIO
#define HANDLER_USUARIO

#include <string>
#include <map>
#include "usuario.h"

using std::string;
using std::map;

class Jugador;

class HandlerUsuario {
private:
    static HandlerUsuario* instancia;
    map<string, Usuario*>* usuarios;
    HandlerUsuario();
public:
    static HandlerUsuario* getInstance();
    Usuario* getLoggedUser();
    Jugador* findJugador(string);
    bool existeJugador(string);
    void addUsuario(Usuario*);
    ~HandlerUsuario();
};

#endif