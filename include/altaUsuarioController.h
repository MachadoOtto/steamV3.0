/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - 
 * Autores (por nombre):
 * 	Alexis Baladon 
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include <string>
#include "dtUsuario.h"

using std::string;

class altaUsuarioController{
private:
   altaUsuarioController * instancia;
   dtUsuario * datos;
   string empresa, nickname, descripcion;
   altaUsuarioController();

public:
   static altaUsuarioController * getInstance();
   virtual void ingresarUsuario(dtUsuario);
   virtual void ingresarEmpresa(string);
   virtual void ingresarNickname(string);
   virtual void ingresarDescripcion(string);
   virtual void clearCache();
   virtual void confirmarDarDeAltaUsuario();
   ~altaUsuarioController();
};

#endif