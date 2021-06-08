/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Integrantes:
 *      Alexis Baladon (5.574.612-4) - alexis.baladon@fing.edu.uy
 *      Guillermo Toyos (5.139.879-9) - guillermo.toyos@fing.edu.uy
 *      Jorge Machado (4.876.616-9) - jorge.machado.ottonelli@fing.edu.uy
 *      Juan Jose Mangado (5.535.227-0) - juan.mangado@fing.edu.uy
 *      Mathias Ramilo (5.665.788-5) - mathias.ramilo@fing.edu.uy
 */

#include <../include/handlerEstadistica.h>

HandlerEstadistica* HandlerEstadistica::instancia = nullptr;

HandlerEstadistica::HandlerEstadistica(){
    estadisticas = new set<Estadistica*>;
}

static HandlerEstadistica* HandlerEstadistica::getInstance() {
    static HandlerEstadistica instancia();
    return &instancia;
}

set<Estadistica>* HandlerEstadistica::getEstadistica() {
    return estadisticas;
}

HandlerEstadistica::~HandlerEstadistica() {
    for (set<Estadistica*>::iterator it = estadisticas->begin(); it != estadisticas->end(); ++it) {
        delete *it;
    }
    delete estadisticas;
}
