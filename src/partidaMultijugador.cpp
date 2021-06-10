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
}
    
bool PartidaMultijugador::getTransmitidaEnVivo(){ return transmitidaEnVivo; }

void PartidaMultijugador::setJugadoresUnidos(map<string, Jugador*>* jAUnir) {
    jugadoresUnidos = jAUnir;
}

map<string, Jugador*>* PartidaMultijugador::getJugadoresUnidos() { 
    return jugadoresUnidos; 
}

DtPartida PartidaMultijugador::obtenerDatosPartida() {
    DtPartidaMultijugador datos(this->getId(), this->getDtFechaHora(), this->getDuracion(), this->esActiva(), transmitidaEnVivo);
    return datos;
}

/* quien es fechaFinal? La fecha del sistema? Creo que el param. no es necesario*/
void PartidaMultijugador::asignarHoraFinalizacion(DtFechaHora fechaFinal) {
    /* DEP. CIRCULAR se precisa conocer jugador para calcular la fecha? Error en it->second->getJugadorMulti(this) considerar reestructurar logica
    float sum=0;
    for (map<string, Jugador*>::iterator it = jugadoresUnidos->begin(); it != jugadoresUnidos->end(); ++it) {
        sum += this->getDtFechaHora().diffHoras(it->second->getJugadorMulti(this)->getFecha());
    }
    sum += this->getDtFechaHora().diffHoras(fechaSistema::fecha); //Correccion para usar fechaSistema
    this->setDuracion(sum);
    */
}
// el param ya no es necesario
void PartidaMultijugador::finalizarPartida(DtFechaHora horaFinal) {
    this->setActiva(false);
    for (map<string, Jugador*>::iterator it = jugadoresUnidos->begin(); it != jugadoresUnidos->end(); ++it) {
        //it->second->abandonarPartidaMulti(this); mismo problema que el anterior sobre req. jugador
    }
    this->asignarHoraFinalizacion(fechaSistema::fecha);
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

PartidaMultijugador::~PartidaMultijugador() { 
    delete jugadoresUnidos;
}
