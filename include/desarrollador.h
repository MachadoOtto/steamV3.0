#ifndef DESARROLLADOR
#define DESARROLLADOR

#include "usuario.h"
#include "categoria.h"
#include "estadistica.h"
#include "videojuego.h"

#include <string>
#include <set>
#include <map>

class Desarrollador: public Usuario {
    private:
        std::string empresa;
        std::map<std::string,Videojuego *> * videojuegosDesarrollados;
        std::map<std::string,Estadistica *> * estadisticas;
    public:
        std::set<std::string> * getVjSinPartidasActivas();
        std::map<std::string,Videojuego *> * getVideojuegosDesarrollados();
        void publishVideogame(DtVideojuego,std::map<std::string,Categoria *> *);
        void suscribirEstadistica(Estadistica *);
        std::set<DtEstadistica> * solicitarEstadisticas(Videjuego *);
};

#endif