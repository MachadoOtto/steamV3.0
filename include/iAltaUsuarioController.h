/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - 
 * Autores (por nombre):
 * 	Alexis Baladon 
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef IALTAUsuario
#define IALTAUsuario

#include <string>

class DtUsuario;

class IAltaUsuario{
private:

public:
   virtual void ingresarUsuario(dtUsuario)=0;
   virtual void ingresarEmpresa(string)=0;
   virtual void ingresarNickname(string)=0;
   virtual void ingresarDescripcion(string)=0;
   virtual void confirmarDarDeAltaUsuario()=0;
   virtual void clearCache()=0;
   
   virtual ~IAltaUsuario
};

#endif
