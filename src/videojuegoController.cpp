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

VideojuegoController * VideojuegoController::instancia = nullptr;

static Desarrollador * getDev(){
    HandlerUsuario * hu = HandlerUsuario::getInstance();
    return static_cast<Desarrollador *>(hu->getLoggedUser());
}
static Jugador * getPlayer(){
    HandlerUsuario * hu = HandlerUsuario::getInstance();
    return static_cast<Jugador *>(hu->getLoggedUser());
}

vector<string> * VideojuegoController::obtenerNombreVideojuegosDesarrollados(){
    Desarrollador * dev = getDev();
    this->setLoggedUser(dev);
    return dev->getVideojuegosDesarrollados();
}

vector<string> * VideojuegoController::obtenerNombreVideojuegosInactivos(){
    Desarrollador * dev = getDev();
    this->setLoggedUser(dev);
    return dev->getVjSinPartidasActivas();
}

vector<DtVideojuego> * VideojuegoController::obtenerSuscripcionesVideojuegos(){
    Jugador * player = getPlayer();
    this->setLoggedUser(player);
    return player->obtenerDatosVj();
}

vector<DtCategoria> * VideojuegoController::obtenerCategoriasGenero(){
    HandlerCategoria * hc = HandlerCategoria::getInstance();
    return hc->getDtGenders();
}
vector<DtCategoria> * VideojuegoController::obtenerCategoriasPlataforma(){
    HandlerCategoria * hc = HandlerCategoria::getInstance();
    return hc->getDtPlatforms();
}

vector<DtCategoria> * VideojuegoController::obtenerCategoriasOtro(){
    HandlerCategoria * hc = HandlerCategoria::getInstance();
    return hc->getDtCategories();
}

vector<DtEstadistica> * VideojuegoController:obtenerEstadisticas(string x){
    HandlerCatalogo * hc = HandlerCatalogo::getInstance();
    Videojuego * v = findVideojuego(x);
    Desarrollador * dev = static_cast<Desarrollador *>(loggedUser);
    vector<DtEstadistica> * y = dev->solicitarEstadisticas(v);
    this->clearCache();
    return y;
}

void VideojuegoController::ingresarDatosVideojuego(DtVideojuego * d){
    datos = d; 
}

void VideojuegoController::ingresarSuscripcion(TipoSuscripcion ts, TipoPago d){
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
    Videojuego * v = dev->publishVideogame();
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
    static_cast<Desarrollador *>(loggedUser)->removeVideojuego(videoCache);
    hc->remove(videoCache);
}

void VideojuegoController::cancelarSuscripcion(){
    videoCache->cancelarSuscripcion(static_cast<Jugador *>(loggedUser));
    this->clearCache();
}

void VideojuegoController::clearCache(){
    delete datos;
    categoriaCache->clear(); //Supuestamente esto borraria los punteros pero no los objetos...
    delete categoriaCache;
}

void VideojuegoController::setLoggedUser(Usuario * x){
    loggedUser=x;
}

VideojuegoController * VideojuegoController::getInstance(){
    if(instancia==nullptr)
	instancia = new VideojuegoController();
    return instancia;
} 

VideojuegoController::VideojuegoController(){
    categoriaCache = new vector<Categoria*>;
    datos = nullptr;
    loggedUser = nullptr;
    videoCache = nullptr;
}

VideojuegoController::~VideojuegoController(){
    this->clearCache();
    instancia = nullptr;
}


