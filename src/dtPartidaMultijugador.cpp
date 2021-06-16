/* Laboratorio Programacion IV - INCO/FING/UDELAR 
 * Integrantes:
 *      Alexis Baladon (5.574.612-4) - alexis.baladon@fing.edu.uy
 *      Guillermo Toyos (5.139.879-9) - guillermo.toyos@fing.edu.uy
 *      Jorge Machado (4.876.616-9) - jorge.machado.ottonelli@fing.edu.uy
 *      Juan Jose Mangado (5.535.227-0) - juan.mangado@fing.edu.uy
 *      Mathias Ramilo (5.665.788-5) - mathias.ramilo@fing.edu.uy
 */

#include "../include/dtPartidaMultijugador.h"
#include "../include/dtPartida.h"
#include "../include/dtFechaHora.h"

DtPartidaMultijugador::DtPartidaMultijugador(int id,DtFechaHora fecha,float duracion,bool activa,bool trans): DtPartida(id,fecha,duracion,activa) {
    transmitidaEnVivo = trans;
}

bool DtPartidaMultijugador::getTransmitidaEnVivo(){
    return transmitidaEnVivo;
}

string DtPartidaMultijugador::getString() {
    string texto = "";
    texto = texto + "ID: " + std::to_string(id) + "\n" + "Duracion: " + std::to_string(duracion) 
    + "\n" + "Fecha de creacion: " + fecha.getString() + "\n";
    if (activa) 
        texto = texto + "La partida se encuentra en curso.\n";
    else 
        texto = texto + "La partida ha finalizado.\n";
    if (transmitidaEnVivo) 
        texto = texto + "Se esta transmitiendo en vivo\n";
    else 
        texto = texto + "No se ha transmitido en vivo\n";
    return texto;
}

std::ostream & operator << (std::ostream &o,DtPartidaMultijugador p) {
    o << "ID: " << p.getId() << "\n" << "Duracion: " << p.getDuracion() 
    << "\n" << "Fecha de creacion: " << p.getFecha() << "\n";
    if (p.getActiva()) 
        o << "La partida se encuentra en curso.\n";
    else 
        o << "La partida ha finalizado.\n";
    if(p.getTransmitidaEnVivo()) 
        o << "Se esta transmitiendo en vivo\n";
    else 
        o << "No se ha transmitido en vivo\n";
    o << "\n";
    return o;
}
