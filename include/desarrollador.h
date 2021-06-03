#ifndef DESARROLLADOR
#define DESARROLLADOR

#include "usuario.h"
#include "categoria.h"
#include "estadistica.h"
#include "videojuego.h"

#include <string>
#include <list>
#include <map>

class Desarrollador: public Usuario {
    private:
        std::string empresa;
        std::map<std::string,Videojuego *> * videojuegosDesarrollados;
        std::map<std::string,Estadistica *> * estadisticas;
    public:
        std::list<std::string> * getVjSinPartidasActivas();
        std::map<std::string,Videojuego *> * getVideojuegosDesarrollados();
        void publishVideogame(DtVideojuego *,std::map<std::string,Categoria *> *);
        void suscribirEstadistica(Estadistica *);
        std::list<DtEstadistica *> * solicitarEstadisticas(Videjuego *);
};

#endif