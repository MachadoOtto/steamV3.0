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

AltaUsuarioController::AltaUsuarioController(){
    datos = NULL;
    empresa = "";
}

AltaUsuarioController * AltaUsuarioController::getInstance(){
    static AltaUsuarioController instancia;
    return &instancia;
}

void AltaUsuarioController::ingresarUsuario(DtUsuario * d){
   datos = d;   
}

void AltaUsuarioController::ingresarEmpresa(string e){
   empresa = e;
}

void AltaUsuarioController::ingresarNickname(string n){
   HandlerUsuario * hc = HandlerUsuario::getInstance();
   if (!hc->existeUsuario(n))
      nickname = n;
}

void AltaUsuarioController::ingresarDescripcion(string d){
   descripcion = d;
}

void AltaUsuarioController::clearCache(){
   delete datos;
}

void AltaUsuarioController::confirmarDarDeAltaUsuario(){
     
   HandlerUsuario * hu = HandlerUsuario::getInstance();
   if(!empresa.empty()){
	DtDesarrollador dat(empresa, datos->getEmail(), datos->getContrasenia());
	Desarrollador* usu = new Desarrollador(dat);
	hu->addUsuario(usu); 
   }
   else{
	DtJugador dat(nickname, descripcion, datos->getEmail(), datos->getContrasenia());
	Jugador* usu = new Jugador(dat);
	hu->addUsuario(usu); 
   }
}

AltaUsuarioController::~AltaUsuarioController(){
   this->clearCache();
}

