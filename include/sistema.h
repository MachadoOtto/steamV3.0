/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef SISTEMA
#define SISTEMA

#include <ctime>
#include <iostream>
#include <stdio.h>

#include "laFabrica.h"
#include "iAltaUsuarioController.h"
#include "iIFPController.h"
#include "iVideojuegoController.h"
#include "fechaSistema.h"
#include "menuUtilities.h"

using std::string;

class Sistema{
public:
    Sistema();
    ~Sistema();

    int altaUsuario();
    int modificarFecha();
    int cargarDatosPrueba();
    int iniciarSesion();

    int cargarCategoria();
    int publicarVideojuego();
    int eliminarVideojuego();
    int seleccionarEstadistica();
    int consultarEstadisticas();
    int verInformacionVideojuego();

    int suscribirseVideojuego();
    int asignarPuntajeVideojuego();
    int iniciarPartida();
    int	abandonarPartidaMultijugador();
    int finalizarPartida();

    string getLoggedUserEmail();
};
#endif
