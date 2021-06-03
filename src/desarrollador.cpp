#include "../include/desarrollador.h"
#include "../include/categoria.h"
#include "../include/estadistica.h"

#include <string>
#include <list>
#include <map>

Desarrollador::Desarrollador(DtDesarrollador) {
    
}

std::list<std::string> * Desarrollador::getVideojuegosDesarrollados() {
    return getVideojuegosDesarrollados;
}

void Desarrollador::publishVideogame(DtVideojuego * dtvj,std::map<std::string,Categoria> * categorias) {
    Videjuego * vj = create(dtvj,categorias); //el new?
    videojuegosDesarrollados->insert(vj);
}

void Desarrollador::suscribirEstadistica(Estadistica est) {
    
}

std::list<DtEstadistica> Desarrollador::solicitarEstadisticas(Videjuego) {

}
