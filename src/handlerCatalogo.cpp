/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Integrantes:
 *      Alexis Baladon (5.574.612-4) - alexis.baladon@fing.edu.uy
 *      Guillermo Toyos (5.139.879-9) - guillermo.toyos@fing.edu.uy
 *      Jorge Machado (4.876.616-9) - jorge.machado.ottonelli@fing.edu.uy
 *      Juan Jose Mangado (5.535.227-0) - juan.mangado@fing.edu.uy
 *      Mathias Ramilo (5.665.788-5) - mathias.ramilo@fing.edu.uy
 */

#include <../include/handlerCatalogo.h>

HandlerCatalogo* HandlerCatalogo::instancia = nullptr;

HandlerCatalogo::HandlerCatalogo() {
    videojuegos = new map<string, Videojuego*>;
}

static HandlerCatalogo* HandlerCatalogo::getInstance() {
    if (instancia == nullptr)
        instancia = new HandlerCatalogo();
    return instancia;
}

set<DtVideojuego>* HandlerCatalogo::getDatosInactivos() {
    set<DtVideojuego> dtInactivos* = new set<DtVideojuego>;
    for (map<string, Videojuego*>::iterator it = videojuegos->begin(); it! = videojuegos->end(); ++it) {
        if (!(it->second->esActivo())) {
            dtInactivos->insert(it->second->obtenerDatoVideojuego());
        }
    }
    return dtInactivos;
}

Videojuego HandlerCatalogo::findVideojuego(string nombreVideojuego) {
    map<string, Videojuego*>::iterator it = videojuegos->find(nombreVideojuego);
    return it->second;
}

void HandlerCatalogo::addVideojuego(Videojuego* vj) {
    videojuegos[vj->getNombre()] = vj;
}

void HandlerCatalogo::remove(Videojuego* vj) {
    map<string, Videojuego*>::iterator it = videojuegos->find(vj->getNombre());
    delete it->second;
    videojuegos->erase(it); 
}

HandlerCatalogo::~HandlerCatalogo() {
    for (map<string, Videojuego*>::iterator it = videojuegos->begin(); it != videojuegos->end(); ++it) {
        delete it->second;
    }
    delete videojuegos;
}