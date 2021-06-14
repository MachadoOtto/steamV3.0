/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class implementation 
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "../include/videojuegoController.h"

static Desarrollador * getDev(){
    HandlerUsuario * hu = HandlerUsuario::getInstance();
    return static_cast<Desarrollador *>(hu->getLoggedUser());
}
/* Funcion desactivada, era usada por los bloques comentados
static Jugador * getPlayer(){
    HandlerUsuario * hu = HandlerUsuario::getInstance();
    return static_cast<Jugador *>(hu->getLoggedUser());
}
*/

set<string> * VideojuegoController::obtenerNombreVideojuegosDesarrollados(){
    Desarrollador * dev = getDev();
    this->setLoggedUser(dev);
    return dev->getVideojuegosDesarrollados();
}

set<string> * VideojuegoController::obtenerNombreVideojuegosInactivos(){
    Desarrollador * dev = getDev();
    this->setLoggedUser(dev);
    return dev->getVjSinPartidasActivas();
}
//Esta funcion no hace lo que tenia que hacer de devolver las activas por un lado y las inactivas por otro...
set<vector<DtVideojuego>> * VideojuegoController::obtenerSuscripcionesVideojuegos(){
   /* Jugador * player = getPlayer();
    this->setLoggedUser(player);
    return player->obtenerDatosVj(); */
    return nullptr;
}

set<DtCategoria> * VideojuegoController::obtenerCategoriasGenero(){
    HandlerCategoria * hc = HandlerCategoria::getInstance();
    return hc->getDtGenders();
}
set<DtCategoria> * VideojuegoController::obtenerCategoriasPlataforma(){
    HandlerCategoria * hc = HandlerCategoria::getInstance();
    return hc->getDtPlatforms();
}

set<DtCategoria> * VideojuegoController::obtenerCategoriasOtro(){
    HandlerCategoria * hc = HandlerCategoria::getInstance();
    return hc->getDtCategories();
}

set<DtEstadistica> * VideojuegoController::obtenerEstadisticas(string x){
    HandlerCatalogo * hc = HandlerCatalogo::getInstance();
    Videojuego * v = hc->findVideojuego(x);
    Desarrollador * dev = static_cast<Desarrollador *>(loggedUser);
    set<DtEstadistica> * y = dev->solicitarEstadisticas(v);
    this->clearCache();
    return y;
}

void VideojuegoController::ingresarDatosVideojuego(DtVideojuego d){
    datos = d; 
}

void VideojuegoController::ingresarSuscripcion(TipoValido ts, TipoPago d){
    tPago = d; 
    tSus = ts;
}

void VideojuegoController::seleccionarVideojuego(string x){
    HandlerCatalogo * hc = HandlerCatalogo::getInstance();
    videoCache = hc->findVideojuego(x);
}

void VideojuegoController::seleccionarGenero(string x){
    HandlerCategoria * hc = HandlerCategoria::getInstance();
    categoriaCache->insert(static_cast<Categoria * >(hc->findGender(x)));
}
void VideojuegoController::seleccionarPlataforma(string x){
    HandlerCategoria * hc = HandlerCategoria::getInstance();
    categoriaCache->insert(static_cast<Categoria * >(hc->findPlatform(x)));
}
void VideojuegoController::seleccionarCategoriaOtro(string x){
    HandlerCategoria * hc = HandlerCategoria::getInstance();
    categoriaCache->insert(static_cast<Categoria * >(hc->findCategory(x)));
}

void VideojuegoController::confirmarPublicacion(){
    HandlerCatalogo * hc = HandlerCatalogo::getInstance();
    HandlerUsuario * hu = HandlerUsuario::getInstance();
    Desarrollador * dev = static_cast<Desarrollador *>(hu->getLoggedUser());
    Videojuego * v = dev->publishVideogame(datos,categoriaCache); 
    hc->addVideojuego(v);
    this->clearCache();
}

void VideojuegoController::confirmarSuscripcion(){
    videoCache->confirmarSuscripcion(static_cast<Jugador *>(loggedUser),tSus,tPago);
    this->clearCache();
}

void VideojuegoController::confirmarEliminarVideojuego(){
    HandlerCatalogo * hc = HandlerCatalogo::getInstance();
    videoCache->eliminarInfoAsociada();
    static_cast<Desarrollador *>(loggedUser)->remove(videoCache);
    hc->remove(videoCache);
}

void VideojuegoController::cancelarSuscripcion(){
    videoCache->cancelarSuscripcion(static_cast<Jugador *>(loggedUser));
    this->clearCache();
}

void VideojuegoController::clearCache(){
    categoriaCache->clear(); //Supuestamente esto borraria los punteros pero no los objetos...
}

void VideojuegoController::setLoggedUser(Usuario * x){
    loggedUser=x;
}

bool VideojuegoController::existeVideojuego(string nombreVj) {
    HandlerCatalogo* hc = HandlerCatalogo::getInstance();
    return (hc->findVideojuego(nombreVj) != NULL);
}

set<string>* VideojuegoController::obtenerNombreCategorias(){
    set<string>* s = new set<string>;
    HandlerCategoria * hc = HandlerCategoria::getInstance();
    
    set<DtCategoria>* g = hc->getDtGenders();
    for(set<DtCategoria>::iterator it = g->begin(); it != g->end(); ++it)
	s->insert((*it).getNombre());	
    g = hc->getDtPlatforms();
    for(set<DtCategoria>::iterator it = g->begin(); it != g->end(); ++it)
	s->insert((*it).getNombre()); 
    g = hc->getDtCategories();
    for(set<DtCategoria>::iterator it = g->begin(); it != g->end(); ++it)
	s->insert((*it).getNombre()); 
    return s;
}
int VideojuegoController::cargarCategoria(DtCategoria c){
    catData = c;
    return 0;
}

void VideojuegoController::confirmarAgregarCategoria(){
    Categoria * c = nullptr;
    if (catData.getTipoCategoria() == TipoCategoria::Plataforma)
	c = new Plataforma(catData);
    else if (catData.getTipoCategoria() == TipoCategoria::Genero)
	c = new Genero(catData);
    else
	c = new Categoria(catData);
    HandlerCategoria * hc = HandlerCategoria::getInstance();
    hc->addCategoria(c);
}

VideojuegoController * VideojuegoController::getInstance(){
    static VideojuegoController instance;
    return &instance;
} 

set<DtVideojuego>* VideojuegoController::verVideojuegos(){
    HandlerCatalogo * hc = HandlerCatalogo::getInstance();
    return hc->getDtVideojuegos();
}

void VideojuegoController::puntuar(string v,int p){
    HandlerCatalogo * hc = HandlerCatalogo::getInstance();
    Videojuego * vp = hc->findVideojuego(v);
    vp->addOpinion(p);
}

VideojuegoController::VideojuegoController():datos("","",0,0,0,0),catData("","",TipoCategoria::Otro){
    categoriaCache = new set<Categoria*>;
    loggedUser = nullptr;
    videoCache = nullptr;
}

VideojuegoController::~VideojuegoController(){
    this->clearCache();
    delete categoriaCache;
}


