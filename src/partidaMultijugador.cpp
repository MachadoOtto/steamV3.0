/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Integrantes:
 *      Alexis Baladon (5.574.612-4) - alexis.baladon@fing.edu.uy
 *      Guillermo Toyos (5.139.879-9) - guillermo.toyos@fing.edu.uy
 *      Jorge Machado (4.876.616-9) - jorge.machado.ottonelli@fing.edu.uy
 *      Juan Jose Mangado (5.535.227-0) - juan.mangado@fing.edu.uy
 *      Mathias Ramilo (5.665.788-5) - mathias.ramilo@fing.edu.uy
 */

#include <../include/partidaMultijugador.h>

PartidaMultijugador::PartidaMultijugador(DtPartidaMultijugador datos) : Partida(DtPartida dpartida(datos.getIdentificador(), datos.getFechaHora(),
        datos.getDuracion(), datos.getActiva())) {
    transmitidaEnVivo = datos.getTransmitidaEnVivo();
    jugadoresUnidos = new map<string, Jugador*>;
}
    
bool PartidaMultijugador::getTransmitidaEnVivo { return transmitidaEnVivo; }

void PartidaMultijugador::setJugadoresUnidos(map<string, Jugador*>* jAUnir) {
    jugadoresUnidos = jAUnir;
}

map<string, Jugador*>* PartidaMultijugador::getJugadoresUnidos() { 
    return jugadoresUnidos; 
}

virtual DtPartida PartidaMultijugador::obtenerDatosPartida() {
    DtPartidaMultijugador datos(identificador, fecha, duracion, activa, transmitidaEnVivo);
    return datos;
}

virtual void PartidaMultijugador::asignarHoraFinalizacion(DtFechaHora fechaFinal) {
    for (map<string, Jugador*>::iterator it = jugadoresUnidos->begin(); it! = jugadoresUnidos->end(); ++it) {
        duracion += fecha.diffHoras(it->second->getJugadorMulti(this)->getFecha());
    }
    duracion += fecha.diffHoras(fechaFinal);
}

virtual void PartidaMultijugador::finalizarPartida(DtFechaHora horaFinal) {
    this.setActiva(false);
    for (map<string, Jugador*>::iterator it = jugadoresUnidos->begin(); it! = jugadoresUnidos->end(); ++it) {
        it->second->abandonarPartidaMulti(this);
    }
    this.asignarHoraFinalizacion(horafinal);
}

virtual void PartidaMultijugador::eliminarAssoc() {
    host.remove(this);
    for (map<string, Jugador*>::iterator it = jugadoresUnidos->begin(); it! = jugadoresUnidos->end(); ++it) {
        it->second->remove(this);
    }
    jugadoresUnidos->clear();
}

PartidaMultijugador::~Partida() { 
    delete jugadoresUnidos;
}
