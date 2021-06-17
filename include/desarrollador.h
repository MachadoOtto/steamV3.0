/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Integrantes:
 *      Alexis Baladon (5.574.612-4) - alexis.baladon@fing.edu.uy
 *      Guillermo Toyos (5.139.879-9) - guillermo.toyos@fing.edu.uy
 *      Jorge Machado (4.876.616-9) - jorge.machado.ottonelli@fing.edu.uy
 *      Juan Jose Mangado (5.535.227-0) - juan.mangado@fing.edu.uy
 *      Mathias Ramilo (5.665.788-5) - mathias.ramilo@fing.edu.uy
 */

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
        void setEmpresa(std::string);
        std::string getEmpresa();
        void add(Videojuego *);
        void remove(Videojuego *);
        Videojuego * findVideojuego(std::string); 
        void add(Estadistica *);
        void remove(Estadistica *);
        Estadistica * findEstadistica(std::string);
	std::set<Estadistica *> * getEstadisticas(); 
        std::set<std::string> * getVjSinPartidasActivas();
        std::set<std::string> * getVideojuegosDesarrollados();
        Videojuego * publishVideogame(DtVideojuego,std::map<std::string,Categoria *> *);
        void suscribirEstadistica(Estadistica *);
        std::set<DtEstadistica> * solicitarEstadisticas(Videojuego *);
	void resetEstadisticas();
        ~Desarrollador();
};

#endif
