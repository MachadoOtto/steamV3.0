/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Integrantes:
 *      Alexis Baladon (5.574.612-4) - alexis.baladon@fing.edu.uy
 *      Guillermo Toyos (5.139.879-9) - guillermo.toyos@fing.edu.uy
 *      Jorge Machado (4.876.616-9) - jorge.machado.ottonelli@fing.edu.uy
 *      Juan Jose Mangado (5.535.227-0) - juan.mangado@fing.edu.uy
 *      Mathias Ramilo (5.665.788-5) - mathias.ramilo@fing.edu.uy
 */

#include <../include/handlerUsuario.h>

HandlerUsuario::HandlerUsuario(){
    usuarios = new map<string, Usuario*>;
    loggedUser = nullptr;
}

HandlerUsuario* HandlerUsuario::getInstance() {
    static HandlerUsuario instancia;
    return &instancia;
}

void HandlerUsuario::setLoggedUser(Usuario* user) {
    loggedUser = user;
}

Usuario* HandlerUsuario::getLoggedUser() { return loggedUser; }

Usuario* HandlerUsuario::findUsuario(string emailUsuario) {
    return usuarios->find(emailUsuario)->second;
}

Jugador* HandlerUsuario::findJugador(string nick) {
    bool siga = true;
    Jugador* player = NULL;
    for (map<string,Usuario*>::iterator it = usuarios->begin(); (it != usuarios->end()) && siga; ++it) {
        if ((player = dynamic_cast<Jugador*>(it->second))) {
            if (player->getNickname() == nick) {
                siga = false;
            }
        }
    }
    if (siga) {
        player = NULL;
    }
    return player;
}

bool HandlerUsuario::existeUsuario(string emailUsuario) {
    return (usuarios->find(emailUsuario) != usuarios->end());
}

void HandlerUsuario::addUsuario(Usuario* user) {
    usuarios->insert(map<string, Usuario*>::value_type(user->getEmail(), user));
}
//corregir si es necesario para que retorne una estructura deleteable
map<string, Usuario*>* HandlerUsuario::obtenerUsuarios() { return usuarios; }

bool HandlerUsuario::hayUsuarios() { return (!(usuarios->empty())); }

HandlerUsuario::~HandlerUsuario() {
    for (map<string, Usuario*>::iterator it = usuarios->begin(); it != usuarios->end(); ++it) {
        delete it->second;
    }
    delete usuarios;
}
