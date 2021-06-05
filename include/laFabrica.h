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

class laFabrica{
private:
   laFabrica instancia;
   laFabrica();

public:
   IVideojuego getVideojuegoInterface();
   IIFPartidas getIFPartidasInterface();
   IAltaUsuario getAltaUsuarioInterface(); 
};

#endif