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

static Jugador * getPlayer(){
    HandlerUsuario * hu = HandlerUsuario::getInstance();
    return static_cast<Jugador *>(hu->getLoggedUser());
}


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

vector<set<DtVideojuego>> * VideojuegoController::obtenerSuscripcionesVideojuegos(){
    Jugador * player = getPlayer();
    HandlerCatalogo * cc = HandlerCatalogo::getInstance();
    vector<set<DtVideojuego>> * x = new vector<set<DtVideojuego>>;
    this->setLoggedUser(player);

    set<Videojuego*> * t = player->obtenerDatosVj();
    set<Videojuego*> * aBorrar = new set<Videojuego*>;
    set<DtVideojuego> * da = new set<DtVideojuego>;
    bool activeV=false;
    for(set<Videojuego*>::iterator it=t->begin(); it != t->end();++it){
	for(set<Suscripcion*>::iterator it2=(*it)->getSuscripciones()->begin(); it2 != (*it)->getSuscripciones()->end();++it2){
	    if((*it2)->getComprador() == player && (*it2)->esActiva()){
		da->insert((*it)->obtenerDatosVideojuego());
		activeV = true;
	    }
	}
	if(!activeV)
	    aBorrar->insert(*it); 
	activeV = false;
    }
    for(set<Videojuego*>::iterator it=aBorrar->begin(); it != aBorrar->end();++it){
	t->erase(*it);
    }
    delete aBorrar;
    x->push_back(*da);
    delete da; 
    set<Videojuego*>* tc = cc->getSetComplement(t);
    da = new set<DtVideojuego>;
    for(set<Videojuego*>::iterator it=tc->begin(); it != tc->end();++it){
	da->insert((*it)->obtenerDatosVideojuego());
    }
    x->push_back(*da);
    delete da;
    delete t;
    delete tc;
    return x;
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
    categoriaCache->insert(map<string,Categoria *>::value_type(x,static_cast<Categoria * >(hc->findGender(x))));
}
void VideojuegoController::seleccionarPlataforma(string x){
    HandlerCategoria * hc = HandlerCategoria::getInstance();
    categoriaCache->insert(map<string,Categoria *>::value_type(x,static_cast<Categoria * >(hc->findPlatform(x))));
}
void VideojuegoController::seleccionarCategoriaOtro(string x){
    HandlerCategoria * hc = HandlerCategoria::getInstance();
    categoriaCache->insert(map<string,Categoria *>::value_type(x,static_cast<Categoria * >(hc->findCategory(x))));
}

void VideojuegoController::confirmarPublicacion(){
    HandlerCatalogo * hc = HandlerCatalogo::getInstance();
    HandlerUsuario * hu = HandlerUsuario::getInstance();
    Desarrollador * dev = static_cast<Desarrollador *>(hu->getLoggedUser());
    Videojuego * v = dev->publishVideogame(datos,categoriaCache); 
    hc->addVideojuego(v);
    categoriaCache = new map<string, Categoria*>;
    this->clearCache();
}

void VideojuegoController::confirmarSuscripcion(){
    HandlerUsuario * hu = HandlerUsuario::getInstance();
    videoCache->confirmarSuscripcion(static_cast<Jugador *>(hu->getLoggedUser()),tSus,tPago);
    this->clearCache();
}

void VideojuegoController::confirmarEliminarVideojuego(){
    HandlerCatalogo * hc = HandlerCatalogo::getInstance();
    for (map<int, Partida*>::iterator it = videoCache->getPartidas()->begin(); it != videoCache->getPartidas()->end(); ++it) {
        Jugador* player = it->second->getHost();
        player->quitar(it->second);
    }
    for (set<Suscripcion*>::iterator it = videoCache->getSuscripciones()->begin(); it != videoCache->getSuscripciones()->end(); ++it) {
        Jugador* player = (*it)->getComprador();
        player->remove(*it);
    }
    static_cast<Desarrollador*>(loggedUser)->remove(videoCache);
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

bool VideojuegoController::hayCategorias() { return (exGen && exPlatf); }

set<string>* VideojuegoController::obtenerNombreCategorias(){
    set<string>* s = new set<string>;
    HandlerCategoria * hc = HandlerCategoria::getInstance();
    set<DtCategoria>* g = hc->getDtGenders();
    for(set<DtCategoria>::iterator it = g->begin(); it != g->end(); ++it)
	s->insert((*it).getNombre());	
    delete g;
    g = hc->getDtPlatforms();
    for(set<DtCategoria>::iterator it = g->begin(); it != g->end(); ++it)
	s->insert((*it).getNombre()); 
    delete g;
    g = hc->getDtCategories();
    for(set<DtCategoria>::iterator it = g->begin(); it != g->end(); ++it)
	s->insert((*it).getNombre()); 
    delete g;
    return s;
}
int VideojuegoController::cargarCategoria(DtCategoria c){
    catData = c;
    return 0;
}

void VideojuegoController::confirmarAgregarCategoria(){
    Categoria * c = nullptr;
    if (catData.getTipoCategoria() == TipoCategoria::Plataforma) {
    	c = new Plataforma(catData);
        exPlatf = true;
    }
    else if (catData.getTipoCategoria() == TipoCategoria::Genero) {
	    c = new Genero(catData);
        exGen = true;
    }
    else
	    c = new Categoria(catData);
    HandlerCategoria * hc = HandlerCategoria::getInstance();
    hc->addCategoria(c);
}
set<string> * VideojuegoController::obtenerNombreCatVideojuego(){
    set<string> * x = new set<string>;
    for (map<string,Categoria*>::iterator it = videoCache->getCategorias()->begin(); it != videoCache->getCategorias()->end(); it++) {
	x->insert(it->first);
    }
    return x;
}

vector<string> *  VideojuegoController::obtenerInfoVideojuegoExtra() {
    vector<string> * x = new vector<string>;
    Desarrollador * des = nullptr;
    HandlerUsuario* hUsuario = HandlerUsuario::getInstance();
    map<string,Usuario*>* usuarios = hUsuario->obtenerUsuarios();
    bool f = false;
    for (map<string,Usuario*>::iterator it = usuarios->begin(); it != usuarios->end() && !f; it++){
        if ((des = dynamic_cast<Desarrollador*>(it->second))){
	    set<string>* vdd = des->getVideojuegosDesarrollados();
	    if (vdd->find(videoCache->getNombre()) != vdd->end()){
		x->push_back("Desarrolladora: "+des->getEmpresa());
		f = true;
	    }
	    delete vdd;
	}
    }
    x->push_back("Puntaje promedio: " + std::to_string(videoCache->getPuntaje()));
    if(dynamic_cast<Desarrollador*>(hUsuario->getLoggedUser()))
	x->push_back("Total de horas jugadas: " + std::to_string(videoCache->getTotalHorasJugadas()));
    return x;
}

VideojuegoController * VideojuegoController::getInstance(){
    static VideojuegoController instance;
    return &instance;
} 

set<DtVideojuego>* VideojuegoController::verVideojuegos(){
    HandlerCatalogo * hc = HandlerCatalogo::getInstance();
    return hc->getDtVideojuegos();
}

int VideojuegoController::puntuar(string v,int p){
    HandlerCatalogo * hc = HandlerCatalogo::getInstance();
    Videojuego * vp = hc->findVideojuego(v);
    return vp->addOpinion(getPlayer()->getEmail(),p);
}

DtSuscripcion VideojuegoController::getSuscripcion(string v){
    set<Suscripcion*> * s = getPlayer()->getSuscripciones();
    for(set<Suscripcion*>::iterator it = s->begin(); it != s->end(); ++it){
	if ((*it)->obtenerVideojuego()->getNombre() == v && (*it)->esActiva())
	    return (*it)->getDt();
    }
    return DtSuscripcion(DtFechaHora(0,0,0,0,0),TipoPago::Tarjeta,TipoValido::Vitalicia,TipoEstado::Inactiva); 
}

set<DtEstadistica> * VideojuegoController::obtenerEstadisticas(){
    /* F
    set<DtEstadistica> * x = new set<DtEstadistica>;
    Desarrollador * dev = getDev();
    set<Estadistica*> * deve = dev->getEstadisticas();
    for(set<Estadistica*>::iterator it = deve->begin(); it != deve->end(); ++it){
	x->insert((*it)->procesarEstadistica(nullptr));
    }
    
    delete deve;
    return x;
    */
    set<DtEstadistica> * x = new set<DtEstadistica>;
    HandlerEstadistica * h = HandlerEstadistica::getInstance();
    map<string,Estadistica*>* senbu = h->getEstadistica();
    for(map<string,Estadistica*>::iterator it = senbu->begin(); it!=senbu->end();++it){
	x->insert(it->second->procesarEstadistica(nullptr));
    }
    return x;
}

set<DtEstadistica> * VideojuegoController::obtenerEstadisticasInv(){
    set<DtEstadistica> * x = new set<DtEstadistica>;
    HandlerEstadistica * h = HandlerEstadistica::getInstance();
    map<string,Estadistica*>* senbu = h->getEstadistica();
    Desarrollador * dev = getDev();
    set<Estadistica*> * deve = dev->getEstadisticas();
    for(map<string,Estadistica*>::iterator it = senbu->begin(); it!=senbu->end();++it)
	if(deve->find(it->second) == deve->end())
	    x->insert(it->second->procesarEstadistica(nullptr));
    delete deve;
    return x;
}

void VideojuegoController::cargarEstadisticas(set<string> x){
    Desarrollador * d = getDev();
    HandlerEstadistica * h = HandlerEstadistica::getInstance();
    map<string,Estadistica*>* senbu = h->getEstadistica();
    //Resetea las estadisticas seleccionadas por el developer
    d->resetEstadisticas();
    for(map<string,Estadistica*>::iterator it = senbu->begin(); it!=senbu->end();++it)
	if(x.find(it->first) != x.end())
	    d->add(it->second);
}

VideojuegoController::VideojuegoController():datos("","",0,0,0,0),catData("","",TipoCategoria::Otro){
    categoriaCache = new map<string,Categoria *>;
    loggedUser = nullptr;
    videoCache = nullptr;
    exGen = false;
    exPlatf = false;
}

VideojuegoController::~VideojuegoController(){
    this->clearCache();
    delete categoriaCache;
}