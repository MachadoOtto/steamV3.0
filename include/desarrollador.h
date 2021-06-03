#ifndef DESARROLLADOR
#define DESARROLLADOR

#include "usuario.h"
#include "categoria.h"
#include "estadistica.h"
#include "videojuego.h"

#include <string>
#include <list>

class Desarrollador: public Usuario {
    private:
        std::string empresa;
    public:
        std::list<std::string> getVideojuegosDesarrollados;
        void publishVideogame(DtVideojuego,std::list<Categoria>);
        void suscribirEstadistica(Estadistica);
        std::list<DtEstadistica> solicitarEstadisticas(Videjuego);
};

#endif