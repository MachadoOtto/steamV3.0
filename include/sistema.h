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

#include "../include/dtFechaHora.h"
#include "../include/menuUtilities.h"
#include "../include/fechaSistema.h"

class Sistema{

public:
    Sistema();
    ~Sistema();

    int altaUsuario();
    int modificarFecha();
    int cargarDatosDePrueba();

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

};
#endif
