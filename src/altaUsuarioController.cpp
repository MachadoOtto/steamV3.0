/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4
 * Autores (por nombre):
 * 	Alexis Baladon 
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

/* LAS CLASES VAN EN MAYUSUCOLA CAMBIAR TODO!!!!!!!
 * INCLUIDO EL .H
 */

#include "../include/altaUsuarioController.h"

AltaUsuarioController::AltaUsuarioController(){
    datos = NULL;
}

AltaUsuarioController * AltaUsuarioController::getInstance(){
    static AltaUsuarioController instancia();
    return &instancia;
}

void AltaUsuarioController::ingresarUsuario(dtUsuario * d){
   datos = d;   
}

void AltaUsuarioController::ingresarEmpresa(string e){
   empresa = e;
}

void AltaUsuarioController::ingresarNickname(string n){
   handlerUsuario * hc = handlerUsuario::getInstance();
   if (!hc->existeJugador(n))
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
   Usuario* usu;
   if(empresa != NULL){
      Desarrollador* usu = new Desarrollador(email, contrasenia, empresa);
   }
   else{
      jugador* usu = new Jugador(email, contrasenia, nickname, descripcion);
   }
   hu->addUsuario(usu); 
}

AltaUsuarioController::~altaUsuarioController(){
   this->clearCache();
}

