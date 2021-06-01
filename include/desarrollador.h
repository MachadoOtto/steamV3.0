#ifndef DESARROLLADOR
#define DESARROLLADOR

#include "usuario.h"
#include "categoria.h"
#include "estadistica.h"
#include "videojuego.h"

#include <string>

class Desarrollador: public Usuario {
    private:
        std::string empresa;
    public:
        //Set(String) getVideojuegosDesarrollados;
        //void publishVideogame(DtVideojuego,Set(Categoria));
        void suscribirEstadistica(Estadistica);
        //Set(DtEstadistica) solicitarEstadisticas(Videjuego);
};

#endif