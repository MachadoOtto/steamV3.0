/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class implementation 
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "../include/sistema.h"

using namespace menuUtilities;
using namespace std;

Sistema::Sistema(){
//Hago las cosas pertinentes para iniciar el sistema...
}

int Sistema::modificarFecha(){
    cout << "Ingrese la fecha del sistema usando el formato dd/mm/yyyy hh:mm ." << endl;
    cout << "Si desea iniciar la partida con la fecha actual del sistema operativo (GNU/Linux) escriba 'ahora'." << endl;
    cout << "Fecha: ";
    string date_input;
    int d,m,y,h,min;
    bool fecha_check=false;
    while(!fecha_check){
	try{
	    getline(cin,date_input);
	    if (date_input == "ahora") {
		time_t now = time(0);
		tm* time = localtime(&now);
		d = time->tm_mday;
		m = time->tm_mon + 1; 		// tm_mon devuelve el mes donde enero es igual a 0 (por lo tanto se suma uno).
		y = time->tm_year + 1900; 	// tm_year devuelve los anios despues de 1900 (por lo tanto hay que sumarlos).
		h = time->tm_hour;
		min = time->tm_min;
	    }
	    else{
		if (sscanf(date_input.c_str(),"%d/%d/%d %d:%d",&d,&m,&y,&h,&min) != 5)
		    throw invalid_argument("");
	    }
	    fechaSistema::fecha = DtFechaHora(y,m,d,h,min); 	//fechaSistema(dia, mes, anio, hora, min).
	    fecha_check=true;
	}
	catch(invalid_argument &e){
	    reprintln();
	    cout << "Por favor ingrese una fecha valida: ";
	}
    }
    cout << "Se registro exitosamente la nueva fecha del sistema." << endl;
    pkey();
    return 0;
}

int Sistema::cargarDatosPrueba(){
    //Aqui se realizan la secuencia de operaciones para generar el estado predefinido del sistema
    //solicitado
    
    return 0;
}

Sistema::~Sistema(){
//Hago las cosas pertinentes para cerrar el sistema... (se libera memoria)
}

int Sistema::iniciarPartida() {
	iIFPController * interfaz = iIFPController::getInstance();
	std::set<std::string> videojuegosActivos = interfaz->obtenerVideojuegosActivos();
	std::cout << "Sus videojuegos activovs son: \n";
	for(std::set<std::string>::const_iterator it = videojuegosActivos->begin(); it != videojuegosActivos->end(); it++) {
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Que videojuego desea seleccionar?" << std::endl;
	std::string videojuegoSeleccionado;
	getline(std::cin,videojuegoSeleccionado);
	std::cout << std::endl;
	interfaz->seleccionarVideojuego(videojuegoSeleccionado);
	std::cout << "Que tipo de partida desea iniciar?" << std::endl;
	std::cout << "1) Individual" << std::endl;
	std::cout << "2) Multijugador" << std::endl;
	std::cout << std::endl;
	
	if(getchar() == '1') { //es individual
		std::cout << "Desea continuar una partida ya creada?" << std::endl;
		std::cout << "1) Si" << std::endl;
		std::cout << "2) No" << std::endl;
		std::cout << std::endl;
		if(getchar() == '1') { //Es continuacion
			std::set<DtPartidaIndividual> * historialPartidas = interfaz->obtenerHistorialPartidas();
			std::cout << "Lista de partidas individuales: " << std::endl;
			for(std::set<DtPartidaIndividual>::const_iterator it = historialPartidas->begin(); it != historialPartidas->end(); it++) {
				std::cout << *it << std::endl;
			}
			std::cout << std::endl;
			std::cout << "Ingrese el identificador de la partida a la que desea ingresar: " << std::endl;
			std::cout << std::endl;
			int idContinuacion;
			std::cin >> idContinuacion;
			std::cout << std::endl;
			interfaz->seleccionarContinuacionPartida(idContinuacion);
		}
	}
	else { //es multijugador
		std::cout << "Su partida es transmitida en vivo?" << std::endl;
		std::cout << "1) Si" << std::endl;
		std::cout << "2) No" << std::endl;
		std::cout << std::endl;
		bool enVivo = getchar() == '1';
		interfaz->transmitidaEnVivo(enVivo);
		std::set<std::string> * jugadoresSuscritos = interfaz->obtenerJugadoresSubscriptos();
		std::cout << "Los jugadores suscritos al videojuego seleccionado son: " << std::endl;
		std::cout << std::endl;
		for(std::set<std::string>::const_iterator it = jugadoresSuscritos->begin(); it != jugadoresSuscritos->end(); it++) {
				std::cout << *it << std::endl;
			}
		std::cout << "Ingrese la cantidad de usuarios que desea unir a su partida: " << std::endl;
		int cantidadJugadoresAUnir;
		std::cin >> cantidadJugadoresAUnir;
		while(cantidadJugadoresAUnir--) {
			std::cout << "Nombre a cada jugador presionando la tecla enter de por medio: " << std::endl;
			std::cout << std::endl;
			std::string jugadorAUnir;
			getline(std::cin,jugadorAUnir);
			interfaz->agregarJugadorAPartida(jugadorAUnir);
		}
	}
	std::cout << "Desea confirmar la creacion de su partida?" << std::endl;
	std::cout << "1) Si" << std::endl;
	std::cout << "2) No" << std::endl;
	std::cout << std::endl;
	if(getchar() == '1') {
		interfaz->confirmarPartida();
	}
	else interfaz->clearCache();
	return 0;
}

int Sistema::finalizarPartida() {
	iIFPController * interfaz = iIFPController::getInstance();
	std::set<DtPartida> * partidasActivas = interfaz->obtenerPartidasActivas();
	std::cout << "Partidas existenes en el sistema: " << std::endl;
	std::cout << std::endl;
	for(std::set<DtPartida>::const_iterator it = partidasActivas->begin(); it != partidasActivas->end(); it++) {
				std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Ingrese el identificador de la partida que desee finalizar: " << std::endl;
	std::cout << std::endl;
	int idPartidaAFinalizar;
	std::cin >> idPartidaAFinalizar;
	std::cout << "Esta seguro que desea finalizar esta partida?" << std::endl;
	std::cout << "1) Si" << std::endl;
	std::cout << "2) No" << std::endl;
	std::cout << std::endl;
	if(getchar() == '1') {
		interfaz->confirmarFinalizacionPartida(idPartidaAFinalizar);
	}
	else {
		interfaz->clearCache();
	}
	return 0;
}


