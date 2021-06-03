#ifndef DESARROLLADOR
#define DESARROLLADOR

#include "usuario.h"
#include "categoria.h"
#include "estadistica.h"
#include "videojuego.h"
#include "dtEstadistica.h"
#include "dtDesarrollador.h"

#include <string>
#include <set>
#include <map>

class Desarrollador: public Usuario {
    private:
        std::string empresa;
        std::map<std::string,Videojuego *> * videojuegosDesarrollados;
        std::map<std::string,Estadistica *> * estadisticas;
    public:
        Desarrollador(DtDesarrollador);
        std::set<std::string> * getVjSinPartidasActivas();
        std::set<std::string> * getVideojuegosDesarrollados();
        void remove(Videojuego *);
        void publishVideogame(DtVideojuego,std::map<std::string,Categoria *> *);
        void suscribirEstadistica(Estadistica *); //POR HACER
        std::set<DtEstadistica> * solicitarEstadisticas(Videjuego *);
        ~Desarrollador();
};

#endif
