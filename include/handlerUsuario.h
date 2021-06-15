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
#include "jugador.h"

using std::string;
using std::map;

class HandlerUsuario {
private:
    static HandlerUsuario* instancia;
    Usuario* loggedUser;
    map<string, Usuario*>* usuarios;
    HandlerUsuario();
public:
    static HandlerUsuario* getInstance();
    void setLoggedUser(Usuario*);
    Usuario* getLoggedUser();
    Usuario* findUsuario(string);
    Jugador* findJugador(string);
    bool existeUsuario(string);
    void addUsuario(Usuario*);
    bool hayUsuarios();
    map<string, Usuario*>* obtenerUsuarios();
    ~HandlerUsuario();
};

#endif
