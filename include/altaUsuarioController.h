/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - 
 * Autores (por nombre):
 * 	Alexis Baladon 
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef ALTAUSUARIOCONTROLLER
#define ALTAUSUARIOCONTROLLER

#include <string>
#include "dtUsuario.h"
#include "handlerUsuario.h"
#include "dtDesarrollador.h"
#include "dtJugador.h"
#include "jugador.h"
#include "desarrollador.h"
#include "iAltaUsuarioController.h"
using std::string;

class AltaUsuarioController: public IAltaUsuarioController{
private:
   DtUsuario datos;
   string empresa, nickname, descripcion;
   AltaUsuarioController();

public:
   static AltaUsuarioController * getInstance();
   virtual void ingresarUsuario(DtUsuario);
   virtual void ingresarEmpresa(string);
   virtual void ingresarNickname(string);
   virtual void ingresarDescripcion(string);
   virtual void clearCache();
   virtual int iniciarSesion();
   virtual void confirmarDarDeAltaUsuario();
   ~AltaUsuarioController();
};

#endif
