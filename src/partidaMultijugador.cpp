/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Integrantes:
 *      Alexis Baladon (5.574.612-4) - alexis.baladon@fing.edu.uy
 *      Guillermo Toyos (5.139.879-9) - guillermo.toyos@fing.edu.uy
 *      Jorge Machado (4.876.616-9) - jorge.machado.ottonelli@fing.edu.uy
 *      Juan Jose Mangado (5.535.227-0) - juan.mangado@fing.edu.uy
 *      Mathias Ramilo (5.665.788-5) - mathias.ramilo@fing.edu.uy
 */

#include "../include/partidaMultijugador.h"

PartidaMultijugador::PartidaMultijugador(DtPartidaMultijugador datos) : Partida(DtPartida(datos.getId(), datos.getFecha(),
        datos.getDuracion(), datos.getActiva())) {
    transmitidaEnVivo = datos.getTransmitidaEnVivo();
    jugadoresUnidos = new map<string, Jugador*>;
    jugadoresMultis = new vector<JugadorMulti*>;
}
    
bool PartidaMultijugador::getTransmitidaEnVivo(){ return transmitidaEnVivo; }

void PartidaMultijugador::setJugadoresUnidos(map<string, Jugador*>* jAUnir) {
    jugadoresUnidos = jAUnir;
}

map<string, Jugador*>* PartidaMultijugador::getJugadoresUnidos() { 
    return jugadoresUnidos; 
}

DtPartida* PartidaMultijugador::obtenerDatosPartida() {
    DtPartidaMultijugador* datos = new DtPartidaMultijugador(this->getId(), this->getDtFechaHora(), this->getDuracion(), this->esActiva(),transmitidaEnVivo);
    return datos;
}

void PartidaMultijugador::asignarHoraFinalizacion() {
    float sum=0;
    for (vector<JugadorMulti*>::iterator it = jugadoresMultis->begin(); it != jugadoresMultis->end(); ++it) {
        sum += this->getDtFechaHora().diffHoras((*it)->getDesconexion());
    }
    sum += this->getDtFechaHora().diffHoras(fechaSistema::fecha); //Correccion para usar fechaSistema
    this->setDuracion(sum);
}

void PartidaMultijugador::eliminarAssoc() {
    /* problema similar... se le pida hablar a jugador cuando la partida no deberia
    host.remove(this);
    for (map<string, Jugador*>::iterator it = jugadoresUnidos->begin(); it! = jugadoresUnidos->end(); ++it) {
        it->second->remove(this);
    }
    jugadoresUnidos->clear();
    */
}

void PartidaMultijugador::abandonar(JugadorMulti* jMulti) {
    jugadoresMultis->insert(jugadoresMultis->begin(), jMulti);
}

PartidaMultijugador::~PartidaMultijugador() {
    for (vector<JugadorMulti*>::iterator it = jugadoresMultis->begin(); it != jugadoresMultis->end(); ++it) {
        delete *it;
    }
    delete jugadoresMultis;
    delete jugadoresUnidos;
}