/* Laboratorio Programacion IV - INCO/FING/UDELAR 
 * Integrantes:
 *      Alexis Baladon (5.574.612-4) - alexis.baladon@fing.edu.uy
 *      Guillermo Toyos (5.139.879-9) - guillermo.toyos@fing.edu.uy
 *      Jorge Machado (4.876.616-9) - jorge.machado.ottonelli@fing.edu.uy
 *      Juan Jose Mangado (5.535.227-0) - juan.mangado@fing.edu.uy
 *      Mathias Ramilo (5.665.788-5) - mathias.ramilo@fing.edu.uy
 */

#include "../include/dtPartidaIndividual.h"
#include "../include/dtFechaHora.h"

DtPartidaIndividual::DtPartidaIndividual(int id,DtFechaHora fecha,float duracion,bool activa,int w): DtPartida(id,fecha,duracion,activa) {
    idPartidaAnterior = w;
}

int DtPartidaIndividual::getIdPartidaAnterior() {
    return idPartidaAnterior;
}

std::ostream & operator<<(std::ostream &o, DtPartidaIndividual p) {
    o << "ID: " << p.getId() << "\n" << "Duracion: " << p.getDuracion() 
    << "\n" << "Fecha de creacion: " << p.getFecha() << "\n" << "Es activa?: ";
    if (p.getActiva()) 
        o << "Si" << "\n";
    else 
        o << "No" << "\n";
    if (p.getIdPartidaAnterior() == -1)
        o << "No es continuacion de otra partida \n";
    else
        o << "ID partida anterior: " << p.getIdPartidaAnterior() << "\n";
    o << "\n";
    return o;
}