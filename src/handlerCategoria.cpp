/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Integrantes:
 *      Alexis Baladon (5.574.612-4) - alexis.baladon@fing.edu.uy
 *      Guillermo Toyos (5.139.879-9) - guillermo.toyos@fing.edu.uy
 *      Jorge Machado (4.876.616-9) - jorge.machado.ottonelli@fing.edu.uy
 *      Juan Jose Mangado (5.535.227-0) - juan.mangado@fing.edu.uy
 *      Mathias Ramilo (5.665.788-5) - mathias.ramilo@fing.edu.uy
 */

#include <../include/handlerCategoria.h>

HandlerCategoria::HandlerCategoria(){
    categorias = new map<string, Categoria*>;
}

static HandlerCategoria* HandlerCategoria::getInstance() {

}

set<DtCategoria>* HandlerCategoria::getDtGenders() {

}

set<DtCategoria>* HandlerCategoria::getDtPlatforms() {

}

set<DtCategoria>* HandlerCategoria::getDtCategories() {

}

Genero* HandlerCategoria::findGender(string nombreGenero) {
    return categorias->find(nombreGenero)->second;
}

Plataforma* HandlerCategoria::findPlatform(string nombrePlataforma) {
    return categorias->find(nombrePlataforma)->second;
}

Categoria* HandlerCategoria::findCategory(string nombreCategoria) {
    return categorias->find(nombreCategoria)->second;
}

void HandlerCategoria::addCategoria(Categoria* cat) {
    categorias->insert(cat->getNombre(), cat);
}

HandlerCategoria::~HandlerCategoria() {
    for (map<string, Categoria*>::iterator it = categorias.begin(); it! = categorias.end(); ++it) {
        delete it->second;
    }
    delete categorias;
}