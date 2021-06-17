/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Integrantes:
 *      Alexis Baladon (5.574.612-4) - alexis.baladon@fing.edu.uy
 *      Guillermo Toyos (5.139.879-9) - guillermo.toyos@fing.edu.uy
 *      Jorge Machado (4.876.616-9) - jorge.machado.ottonelli@fing.edu.uy
 *      Juan Jose Mangado (5.535.227-0) - juan.mangado@fing.edu.uy
 *      Mathias Ramilo (5.665.788-5) - mathias.ramilo@fing.edu.uy
 */

#include "../include/desarrollador.h"
#include "../include/usuario.h"
#include "../include/categoria.h"
#include "../include/estadistica.h"
#include "../include/videojuego.h"
#include "../include/dtEstadistica.h"

#include <string>
#include <set>
#include <map>
#include <iterator>
#include <utility>

Desarrollador::Desarrollador(DtDesarrollador des): Usuario(DtUsuario(des.getEmail(),des.getContrasenia())){
    empresa = des.getEmpresa();
    videojuegosDesarrollados = new std::map<std::string,Videojuego *>;
    estadisticas = new std::map<std::string,Estadistica *>;
}

void Desarrollador::setEmpresa(std::string empresa) {
    this->empresa = empresa;
}

std::string Desarrollador::getEmpresa() {
    return empresa;
}

void Desarrollador::add(Videojuego * vj) {
    videojuegosDesarrollados->insert(std::pair<std::string,Videojuego *>(vj->getNombre(),vj));
}

void Desarrollador::remove(Videojuego * vj) {
    videojuegosDesarrollados->erase(vj->getNombre());
}

Videojuego * Desarrollador::findVideojuego(std::string nombreVj) {
    return (*videojuegosDesarrollados)[nombreVj];
}
void Desarrollador::resetEstadisticas(){
    estadisticas->clear();
}

void Desarrollador::add(Estadistica * est) {
    estadisticas->insert(std::pair<std::string,Estadistica *>(est->getNombre(),est));
}

void Desarrollador::remove(Estadistica * est) {
    estadisticas->erase(est->getNombre());
}

Estadistica * Desarrollador::findEstadistica(std::string est) {
    return (*estadisticas)[est];
}

std::set<std::string> * Desarrollador::getVjSinPartidasActivas() {
    std::set<std::string> * res = new std::set<std::string>;
    for(std::map<std::string,Videojuego *>::iterator it = videojuegosDesarrollados->begin(); it != videojuegosDesarrollados->end(); it++) {
        Videojuego * vj = it->second;
        bool activo = vj->estaActivo();
        if(!activo) {
            std::string nombreVj = vj->getNombre();
            res->insert(nombreVj);
        }
    }
    return res;
}

std::set<std::string> * Desarrollador::getVideojuegosDesarrollados() {
    std::set<std::string> * res = new std::set<std::string>;
    for(std::map<std::string,Videojuego *>::const_iterator it = videojuegosDesarrollados->cbegin(); it != videojuegosDesarrollados->cend(); it++) {
        Videojuego * vj = it->second;
        std::string nombreVideojuego = vj->getNombre();
        res->insert(nombreVideojuego);
    }
    return res;
}

Videojuego * Desarrollador::publishVideogame(DtVideojuego gameData, std::map<std::string,Categoria *> * categorias) {
    Videojuego * vj = new Videojuego(gameData,categorias);
    videojuegosDesarrollados->insert(std::pair<std::string,Videojuego *>(vj->getNombre(),vj));
    return vj;
}

void Desarrollador::suscribirEstadistica(Estadistica * est) {
    add(est);
}

std::set<DtEstadistica> * Desarrollador::solicitarEstadisticas(Videojuego * vj) {
    std::set<DtEstadistica> * res = new std::set<DtEstadistica>;
    for(std::map<std::string,Estadistica *>::const_iterator it = estadisticas->cbegin(); it != estadisticas->cend(); it++) {
        Estadistica * es = it->second;
        DtEstadistica val = es->procesarEstadistica(vj);
        res->insert(val);
    }
    return res;
}

std::set<Estadistica *> * Desarrollador::getEstadisticas(){
    std::set<Estadistica *> *x = new std::set<Estadistica *>;
    for(std::map<std::string,Estadistica*>::iterator it = estadisticas->begin(); it != estadisticas->end(); it++){
	x->insert(it->second);
    }
    return x;
}
   
Desarrollador::~Desarrollador() {
    delete videojuegosDesarrollados;
    delete estadisticas;
}