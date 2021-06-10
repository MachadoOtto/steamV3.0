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

DtPartidaMultijugador::DtPartidaMultijugador(int id,DtFechaHora fecha,float duracion,bool activa,string h,string vj, bool trans,set<string> ss): DtPartida(id,fecha,duracion,activa,h,vj) {
    transmitidaEnVivo = trans;
    jugadoresUnidos = ss;
}

bool DtPartidaMultijugador::getTransmitidaEnVivo(){
    return transmitidaEnVivo;
}
//falta imprimir los jugadores unidos. videojuego y host y sacar los gets (no existen)
std::ostream & operator << (std::ostream &o,DtPartidaMultijugador p) {
	/*
        o << "ID: " << p.getId() << "\n" << "Duracion: " << p.getDuracion()
        << "\n" << "Es activa?: ";
        if(p.getActiva()) o << "Si";
        else o << "No";
        o << "\n" << "Fecha de creacion: " << p.getFecha() << "Es una transmicion en vivo?: ";
        if(p.getTransmitidaEnVivo()) o << "Si";
        else o << "No";
        o << "\n";
	*/
    return o;
}
