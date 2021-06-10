/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4
 * Autores (por nombre):
 * 	Alexis Baladon 
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "../include/altaUsuarioController.h"

AltaUsuarioController::AltaUsuarioController():datos("",""){
    empresa = "";
}

AltaUsuarioController * AltaUsuarioController::getInstance(){
    static AltaUsuarioController instancia;
    return &instancia;
}

void AltaUsuarioController::ingresarUsuario(DtUsuario d){
   datos = d;   
}

void AltaUsuarioController::ingresarEmpresa(string e){
   empresa = e;
}

void AltaUsuarioController::ingresarNickname(string n){
   nickname = n;
}

void AltaUsuarioController::ingresarDescripcion(string d){
   descripcion = d;
}

void AltaUsuarioController::clearCache(){
    datos = DtUsuario("",""); 
}

void AltaUsuarioController::confirmarDarDeAltaUsuario(){
     
   HandlerUsuario * hu = HandlerUsuario::getInstance();
   if(!empresa.empty()){
	DtDesarrollador dat(empresa, datos.getEmail(), datos.getContrasenia());
	Desarrollador* usu = new Desarrollador(dat);
	hu->addUsuario(usu); 
   }
   else{
	DtJugador dat(nickname, descripcion, datos.getEmail(), datos.getContrasenia());
	Jugador* usu = new Jugador(dat);
	hu->addUsuario(usu); 
   }
}

int AltaUsuarioController::iniciarSesion(){
    HandlerUsuario * hu = HandlerUsuario::getInstance();
    bool x = hu->existeUsuario(datos.getEmail());
    if(x){
	Usuario * u = hu->findUsuario(datos.getEmail());
	if(datos.getContrasenia() == u->getContrasenia()){
	    hu->setLoggedUser(u);
	    Jugador * j = dynamic_cast<Jugador *>(u);
	    if(j == nullptr) return 0;
	    else return 1;
	} else return 3;
    } else return 2;
}

AltaUsuarioController::~AltaUsuarioController(){
   this->clearCache();
}

