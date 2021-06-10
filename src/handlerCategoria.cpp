/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Integrantes:
 *      Alexis Baladon (5.574.612-4) - alexis.baladon@fing.edu.uy
 *      Guillermo Toyos (5.139.879-9) - guillermo.toyos@fing.edu.uy
 *      Jorge Machado (4.876.616-9) - jorge.machado.ottonelli@fing.edu.uy
 *      Juan Jose Mangado (5.535.227-0) - juan.mangado@fing.edu.uy
 *      Mathias Ramilo (5.665.788-5) - mathias.ramilo@fing.edu.uy
 */

#include <../include/handlerCategoria.h>

#include <typeinfo>

HandlerCategoria::HandlerCategoria(){
    categorias = new map<string, Categoria*>;
}

HandlerCategoria* HandlerCategoria::getInstance() {
    static HandlerCategoria instancia;
    return &instancia;
}

set<DtCategoria>* HandlerCategoria::getDtGenders() {
    set<DtCategoria>* setGenero = new set<DtCategoria>;
    for (map<string, Categoria*>::iterator it = categorias->begin(); it != categorias->end(); ++it) {
        if (dynamic_cast<Genero*>(it->second)) {
            setGenero->insert(it->second->getDt()); // Inserta un DtCategoria del Genero.
        }
    }
    return setGenero;
}

set<DtCategoria>* HandlerCategoria::getDtPlatforms() {
    set<DtCategoria>* setPlatform = new set<DtCategoria>;
    for (map<string, Categoria*>::iterator it = categorias->begin(); it != categorias->end(); ++it) {
        if (dynamic_cast<Plataforma*>(it->second)) {
            setPlatform->insert(it->second->getDt()); // Inserta un DtCategoria de la Plataforma.
        }
    }
    return setPlatform;
}

set<DtCategoria>* HandlerCategoria::getDtCategories() {
    set<DtCategoria>* setCategOtro = new set<DtCategoria>;
    for (map<string, Categoria*>::iterator it = categorias->begin(); it != categorias->end(); ++it) {
        if (!((dynamic_cast<Genero*>(it->second)) || (dynamic_cast<Plataforma*>(it->second)))) {
            setCategOtro->insert(it->second->getDt()); // Inserta un DtCategoria de CategoriaOtro.
        }
    }
    return setCategOtro;
}

Genero* HandlerCategoria::findGender(string nombreGenero) {
    return  static_cast<Genero *>(categorias->find(nombreGenero)->second);
}

Plataforma* HandlerCategoria::findPlatform(string nombrePlataforma) {
    return static_cast<Plataforma *>(categorias->find(nombrePlataforma)->second);
}

Categoria* HandlerCategoria::findCategory(string nombreCategoria) {
    return categorias->find(nombreCategoria)->second;
}

void HandlerCategoria::addCategoria(Categoria* cat) {
    categorias->insert(std::pair<std::string,Categoria *>(cat->getNombre(), cat));
}

HandlerCategoria::~HandlerCategoria() {
    for (map<string, Categoria*>::iterator it = categorias->begin(); it != categorias->end(); ++it) {
        delete it->second;
    }
    delete categorias;
}
