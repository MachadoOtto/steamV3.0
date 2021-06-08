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

altaUsuarioController::altaUsuarioController(){
    datos = NULL;
}

altaUsuarioController * altaUsuarioController::getInstance(){
   if(instancia == NULL)
      instancia = new altaUsuarioController;
   return instancia;
}

void ingresarUsuario(dtUsuario * d){
   datos = d;   
}

void altaUsuarioController::ingresarEmpresa(string e){
   empresa = e;
}

void altaUsuarioController::ingresarNickname(string n){
   handlerUsuario * hc = handlerUsuario::getInstance();
   if (!hc->existeJugador(n))
      nickname = n;
}

void altaUsuarioController::ingresarDescripcion(string d){
   descripcion = d;
}

void altaUsuarioController::clearCache(){
   delete datos;
}

void altaUsuarioController::confirmarDarDeAltaUsuario(){
     
   HandlerUsuario * hu = HandlerUsuario::getInstance();
   if(empresa != NULL){
      DtUsuario datos(email, contraseña, empresa);
      desarrollador * usu(datos);
   }
   else{

      DtUsuario datos(email, contraseña, nickname, descripcion);
      jugador * usu(datos);
   }
   hu->addUsuario(usu); 
}

altaUsuarioController::~altaUsuarioController(){
   this->clearCache();
   instancia = NULL; 
}

