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
   int ingresarUsuario(DtUsuario);
   void ingresarEmpresa(string);
   bool ingresarNickname(string);
   void ingresarDescripcion(string);
   void clearCache();
   int iniciarSesion();
   void confirmarDarDeAltaUsuario();
   bool hayUsuarios();

   string getLoggedName();
   ~AltaUsuarioController();
};

#endif
