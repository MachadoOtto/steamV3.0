/* Laboratorio Programacion IV - INCO/FING/UDELAR 
 * Integrantes:
 *      Alexis Baladon (5.574.612-4) - alexis.baladon@fing.edu.uy
 *      Guillermo Toyos (5.139.879-9) - guillermo.toyos@fing.edu.uy
 *      Jorge Machado (4.876.616-9) - jorge.machado.ottonelli@fing.edu.uy
 *      Juan Jose Mangado (5.535.227-0) - juan.mangado@fing.edu.uy
 *      Mathias Ramilo (5.665.788-5) - mathias.ramilo@fing.edu.uy
 */

#include "../include/dtPartida.h"
#include "../include/dtFechaHora.h"

DtPartida::DtPartida(int id,DtFechaHora fecha,float duracion, bool activa,string h,string vj) {
    this->id = id;
    this->fecha = fecha;
    this->duracion = duracion;
    this->activa = activa;
    host = h;
    videojuego = vj;
}

int DtPartida::getId() {
    return id;
}

DtFechaHora DtPartida::getFecha() {
    return fecha;
}

float DtPartida::getDuracion() {
    return duracion;
}

bool DtPartida::getActiva() {
    return activa;
}

bool DtPartida::esActiva() { //alias
    return getActiva();
}
string DtPartida::getHost(){
    return host;
}
string DtPartida::getVideojuego(){
    return videojuego;
}

bool operator<(const DtPartida p1,const DtPartida p2){
    return p1.fecha<p2.fecha;
}

