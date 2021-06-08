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

altaUsuarioController::altaUsuarioController(){
    datos = NULL;
}

altaUsuarioController * altaUsuarioController::getInstance(){
    static AltaUsuarioController instancia();
    return &instancia;
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
/*
void altaUsuarioController::confirmarDarDeAltaUsuario(){
     
   HandlerUsuario * hu = HandlerUsuario::getInstance();
   if(empresa != NULL){
      DtDesarrollador datos(email, contrasena, empresa);
      desarrollador * usu(datos);
   }
   else{

      DtUsuario datos(email, contraseña, nickname, descripcion);
      jugador * usu(datos);
   }
   hu->addUsuario(usu); 
}
* Ta todo mal volver a hacer. Mirar los tipos de datatype dtUsuario dtDesarrollador y ver los constructores disponibles.
NO USAR LA ENIE!!!
*/

altaUsuarioController::~altaUsuarioController(){
   this->clearCache();
}

