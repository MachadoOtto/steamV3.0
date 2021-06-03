#include "../include/desarrollador.h"
#include "../include/usuario.h"
#include "../include/categoria.h"
#include "../include/estadistica.h"
#include "../include/videojuego.h"
#include "../include/dtEstadistica.h"

#include <string>
#include <set>
#include <map>
#include <pair>

Desarrollador::Desarrollador(DtDesarrollador des) {
    empresa = des.empresa;
    videojuegosDesarrollados = NULL;
    estadisticas = NULL;
}

std::set<std::string> * getVjSinPartidasActivas() {
    std::set<std::string> * res = new std::set<std::string>;
    for(std::map<std::string,Videojuego *>::const_iterator it = videojuegosDesarrollados->cbegin(); it != videojuegosDesarrollados->cend(); it++) {
        Videojuego * vj = *it;
        bool activo = vj->estaActivo();
        if(!activo) {
            std::string nombreVj = vj->nombre;
            res->push_back(nombreVj);
        }
    }
    return res;
}

std::set<std::string> * Desarrollador::getVideojuegosDesarrollados() {
    std::set<std::string> * res = new std::set<std::string>;
    for(std::map<std::string,Videojuego *>::const_iterator it = videojuegosDesarrollados->cbegin(); it != videojuegosDesarrollados->cend(); it++) {
        Videojuego * vj = *it;
        std::string nombreVideojuego = vj->nombre;
        res->push_back(nombreVideojuego);
    }
    return res;
}

void Desarrollador::remove(Videojuego * vj) {
    videojuegosDesarrollados->erase(vj->nombre);
}

void Desarrollador::publishVideogame(DtVideojuego gameData, std::map<std::string,Categoria *> * categorias) {
    Videjuego * vj = new Videojuego(gameData,categorias);
    videojuegosDesarrollados->insert(std::pair<std::string,Videojuego *>(vj->nombre,vj));
}

void Desarrollador::suscribirEstadistica(Estadistica * est) {
//POR HACER
}

std::set<DtEstadistica> * Desarrollador::solicitarEstadisticas(Videjuego * vj) {
    std::set<DtEstadistica> * res = new std::set<DtEstadistica>;
    HandlerEstadistica * he = Handler::getInstance();
    std::map<std::string,Estadistica *> ests = he->getEstadisticas();
    for(std::set<DtEstadistica>::const_iterator it = ests->cbegin(); it != ests->cend(); it++) {
        Estadistica * es = *it;
        DtEstadistica val = es->procesarEstadistica(vj);
        res->push_back(val);
    }
    return res;
}
