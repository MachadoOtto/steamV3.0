/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Integrantes:
 *      Alexis Baladon (5.574.612-4) - alexis.baladon@fing.edu.uy
 *      Guillermo Toyos (5.139.879-9) - guillermo.toyos@fing.edu.uy
 *      Jorge Machado (4.876.616-9) - jorge.machado.ottonelli@fing.edu.uy
 *      Juan Jose Mangado (5.535.227-0) - juan.mangado@fing.edu.uy
 *      Mathias Ramilo (5.665.788-5) - mathias.ramilo@fing.edu.uy
 */

#ifndef HANDLER_CATEGORIA
#define HANDLER_CATEGORIA

#include <string>
#include <map>
#include <set>
#include "categoria.h"

using std::string;
using std::map;
using std::set;

class DtCategoria;
class Genero;
class Plataforma;

class HandlerCategoria {
private:
    static HandlerCategoria* instancia;
    map<string, Categoria*>* categorias;
    HandlerCategoria();
public:
    static HandlerCategoria* getInstance();
    set<DtCategoria>* getDtGenders();
    set<DtCategoria>* getDtPlatforms();
    set<DtCategoria>* getDtCategories();
    Genero* findGender(string);
    Plataforma* findPlatform(string);
    Categoria* findCategory(string);
    void addCategoria(Categoria*);
    ~HandlerCategoria();
};

#endif