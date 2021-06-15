/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Integrantes:
 *      Alexis Baladon (5.574.612-4) - alexis.baladon@fing.edu.uy
 *      Guillermo Toyos (5.139.879-9) - guillermo.toyos@fing.edu.uy
 *      Jorge Machado (4.876.616-9) - jorge.machado.ottonelli@fing.edu.uy
 *      Juan Jose Mangado (5.535.227-0) - juan.mangado@fing.edu.uy
 *      Mathias Ramilo (5.665.788-5) - mathias.ramilo@fing.edu.uy
 */

#ifndef HANDLER_CATALOGO
#define HANDLER_CATALOGO

#include <string>
#include <map>
#include <set>
#include "videojuego.h"

using std::string;
using std::map;
using std::set;

class DtVideojuego;

class HandlerCatalogo {
private:
    map<string, Videojuego*>* videojuegos;
    HandlerCatalogo();
public:
    static HandlerCatalogo* getInstance();
    //set<DtVideojuego>* getDatosInactivos(); funcion deshabilitada
    set<Videojuego*>* getSetComplement(set<Videojuego*>*);

    set<DtVideojuego>* getDtVideojuegos();
    Videojuego* findVideojuego(string);
    void addVideojuego(Videojuego*);
    void remove(Videojuego*);
    ~HandlerCatalogo();
};

#endif
