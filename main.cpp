/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Implementacion de main (menu)
 * Autores (por nombre):
 *      Alexis Baladon
 *      Guillermo Toyos
 *      Jorge Machado
 *      Juan Jose Mangado
 *      Mathias Ramilo
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <limits> // Necesario para limpiar el buffer de entrada.
#include "include/sistema.h"
#include "include/fechaSistema.h" 
#include "include/menuUtilities.h"

using namespace menuUtilities;
using namespace std;

int menuUsuario(Sistema * sys){
    int controlVar=0;    
    while (controlVar!=7){
	cls();
	ptitle();
	cout << "\nFecha actual del sistema: " << fechaSistema::fecha << endl;
	cout << "Usted ha iniciado sesion como: " << sys->getLoggedUserEmail() << "\n\n";
        cout << "──────────  Menu Jugador ──────────" << endl << endl;
        cout << " 1. Suscribirse a videojuego" << endl;
        cout << " 2. Asignar puntaje a videojuego" << endl;
        cout << " 3. Iniciar partida" << endl;
        cout << " 4. Abandonar partida multijugador" << endl;
        cout << " 5. Finalizar partida" << endl;
        cout << " 6. Ver informacion de videojuego" << endl;
        cout << " 7. Modificar fecha del sistema" << endl;
        cout << " 8. Salir" << endl;
        cout << "Por favor ingrese una opcion: ";		
	
	controlVar = takeInputRange(1,8);
        switch (controlVar) {
	    case 1:{
		sys->suscribirseVideojuego();
		break;
	    }
	    case 2:{
		sys->asignarPuntajeVideojuego();
		break;
	    }
	    case 3:{
		sys->iniciarPartida();
		break;
	    }
	    case 4:{
		sys->abandonarPartidaMultijugador();
		break;
	    }
	    case 5:{
		sys->finalizarPartida();
		break;
	    }
	    case 6:{
		sys->verInformacionVideojuego();
		break;
	    }
	    case 7:{
		sys->modificarFecha();
	    }
	}
    }
    return 0;

}

int menuDesarrollador(Sistema * sys){
    int controlVar=0;    
    while (controlVar!=7){
	cls();
	ptitle();
	cout << "\nFecha actual del sistema: " << fechaSistema::fecha << endl;
	cout << "Usted ha iniciado sesion como: " << sys->getLoggedUserEmail() << "\n\n";
        cout << "──────────  Menu Desarrollador ──────────" << endl << endl;
        cout << " 1. Agregar categoria" << endl;
        cout << " 2. Publicar videojuego" << endl;
        cout << " 3. Eliminar videojuego" << endl;
        cout << " 4. Seleccionar estadisticas" << endl;
        cout << " 5. Consultar estadisticas" << endl;
        cout << " 6. Ver informacion de videojuego" << endl;
        cout << " 7. Modificar fecha del sistema" << endl;
        cout << " 8. Salir" << endl;
        cout << "Por favor ingrese una opcion: ";		
	
	controlVar = takeInputRange(1,7);
        switch (controlVar) {
	    case 1:{
		sys->cargarCategoria();
		break;
	    }
	    case 2:{
		sys->publicarVideojuego();
		break;
	    }
	    case 3:{
		sys->eliminarVideojuego();
		break;
	    }
	    case 4:{
		sys->seleccionarEstadistica();
		break;
	    }
	    case 5:{
		sys->consultarEstadisticas();
		break;
	    }
	    case 6:{
		sys->verInformacionVideojuego();
		break;
	    }
	    case 7:{
		sys->modificarFecha();
		break;
	    }
	}
    }
    return 0;
}

int main() {
    Sistema* sys = new Sistema();
    int controlVar=0;
    
    while (controlVar!=5){
	cls();
	ptitle();
	cout << "\nFecha actual del sistema: " << fechaSistema::fecha << endl<<endl;
        cout << "──────────  Menu Principal ──────────" << endl << endl;
        cout << " 1. Alta de Usuario" << endl;
        cout << " 2. Iniciar sesion" << endl;
        cout << " 3. Modificar fecha del sistema" << endl;
        cout << " 4. Cargar datos de prueba" << endl;
        cout << " 5. Salir" << endl;
        cout << "Por favor ingrese una opcion: ";		
	
	controlVar = takeInputRange(1,5);
        switch (controlVar) {
	    case 1: {
		sys->altaUsuario();
		break;
	    }
	    case 2: {
		int x;
		if ((x = sys->iniciarSesion()) == 1) menuUsuario(sys);
		else if (x==2) menuDesarrollador(sys);
		break;
	    }
	    case 3: {
		sys->modificarFecha();
		break;
	    }
	    case 4: {
		sys->cargarDatosPrueba();
		break;
	    }
	    case 5: {
		delete sys;
		break;
	    }
	}
    }
    cout << "Gracias por utilizar Steam v3.0.\n";
    return 0;
}

