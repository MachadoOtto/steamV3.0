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
int Sistema::altaUsuario(){
    return 0;
}
int Sistema::iniciarSesion(){
    return 0;
}
int Sistema::cargarCategoria(){
    return 0;
}
int Sistema::publicarVideojuego(){
    return 0;
}
int Sistema::eliminarVideojuego(){
    return 0;
}

int Sistema::seleccionarEstadistica(){
    return 0;
}

int Sistema::consultarEstadisticas(){
    return 0;
}

int Sistema::verInformacionVideojuego(){
    return 0;
}

int Sistema::suscribirseVideojuego(){
    return 0;
}

int Sistema::asignarPuntajeVideojuego(){
    return 0;
}

int Sistema::iniciarPartida(){
    int idAnterior = -1;
    bool enVivo;
    set<string>* jIngresados = new set<string>;
    LaFabrica* factory = LaFabrica::getInstance();
    IIFPController* interface = factory->getIIFPController();
    interface->iniciarSesion();
    set<string>* vjActivos = interface->obtenerVideojuegosActivos();
    cout << "Iniciar Partida \n \n";
    cout << "Videojuegos con suscripcion activa: \n";
    for (set<string>::iterator it = vjActivos->begin(); it != vjActivos->end(); ++it) {
        cout << *it << "\n";
    }
    cout << "Ingrese el nombre del Videojuego al que quiera iniciar su Partida: ";
    string nombreVj;
    while (true) {
        getline(cin, nombreVj);
        if (vjActivos->find(nombreVj) == vjActivos->end()) {
            reprintln();
            cout << "Porfavor, ingrese un Videojuego valido: ";
        } else {
            break;
        }
    }
    delete vjActivos;
    interface->seleccionarVideojuego(nombreVj);
    cout << "Seleccione un tipo de Partida a iniciar: (1. Individual, 2. Multijugador) \n";
    string tipoPartida;
    while (true) {
        getline(cin, tipoPartida);
        if ((tipoPartida == "1") || (tipoPartida == "2") || (tipoPartida == "Individual") || (tipoPartida == "Multijugador") 
                || (tipoPartida == "individual") || (tipoPartida == "multijugador")) {
            break;
        } else {
            reprintln();
            cout << "Porfavor, ingrese una opcion valida: ";
        }
    }
    if ((tipoPartida == "1") || (tipoPartida == "Individual") || (tipoPartida == "individual")) {
        tipoPartida = "Individual";
        cout << "Su Partida es continuacion de una Partida anterior? (1. Si, 2. No) \n";
        string esCont;
        while (true) {
            getline(cin, esCont);
            if ((esCont == "1") || (esCont == "Si") || (esCont == "si") || (esCont == "2") || (esCont == "No") || (esCont == "no")) {
                break;
            } else {
                reprintln();
                cout << "Porfavor, ingrese una opcion valida: ";
            }
        }
        if ((esCont == "1") || (esCont == "Si") || (esCont == "si")) {
            map<DtFechaHora, DtPartidaIndividual*>* pAnteriores = interface->obtenerHistorialPartidas();
            cout << "Partidas anteriores: \n";
            for (map<DtFechaHora, DtPartidaIndividual*>::iterator it = pAnteriores->begin(); it != pAnteriores->end(); ++it) {
                cout << it->second;
            }
            cout << "Ingrese el Id de la partida a continuar: \n";
            while (true) {
                if (!(cin >> idAnterior)) {
			        clinput();
                    cout << "Porfavor, ingrese un Id correcto: ";
                } else {
                    clinput();
                    bool exId = false;
                    for (map<DtFechaHora, DtPartidaIndividual*>::iterator it = pAnteriores->begin(); it != pAnteriores->end(); ++it) {
                        if (it->second->getId() == idAnterior) {
                            exId = true;
                            break;
                        }
                        cout << it->second;
                    }
                    if (!exId) {
                        reprintln();
                        cout << "Porfavor, ingrese un Id correcto: ";
                    } else {
                        break;
                    }
                }
            }
            for (map<DtFechaHora, DtPartidaIndividual*>::iterator it = pAnteriores->begin(); it != pAnteriores->end(); ++it) {
                delete it->second;
            }
            delete pAnteriores;
            interface->seleccionarContinuacionPartida(idAnterior);
        }
    } else {
        tipoPartida = "Multijugador";
        cout << "Su Partida se transmitira en vivo? (1. Si, 2. No) \n";
        string tEnVivo;
        while (true) {
            getline(cin, tEnVivo);
            if ((tEnVivo == "1") || (tEnVivo == "Si") || (tEnVivo == "si") || (tEnVivo == "2") || (tEnVivo == "No") || (tEnVivo == "no")) {
                if ((tEnVivo == "1") || (tEnVivo == "Si") || (tEnVivo == "si")) {
                    enVivo = true;
                } else {
                    enVivo = false;
                }
                break;
            } else {
                reprintln();
                cout << "Porfavor, ingrese una opcion valida: ";
            }
        }
        interface->setEnVivo(enVivo);
        cout << "Los Jugadores con suscripciones activas actualmente son: \n";
        set<string>* jugadoresSus = interface->obtenerJugadoresSubscriptos();
        for (set<string>::iterator it = jugadoresSus->begin(); it != jugadoresSus->end(); ++it) {
            cout << *it << "\n";
        }
        cout << "Ingrese los nicknames de los jugadores a agregar a la partida. Para finalizar ingrese '0' : \n";
        string nick;
        while (true) {
            getline(cin, nick);
            if (nick != "0") {
                if (jugadoresSus->find(nick) == jugadoresSus->end()) {
                    reprintln();
                    cout << "Porfavor, ingrese un Nickname valido: ";
                } else {
                    jIngresados->insert(nick);
                    interface->aniadirJugadorPartida(nick);
                    break;
                }
            } else {
                break;
            }
        }
        delete jugadoresSus;
    }
    cout << "Los datos ingresados de la partida a Iniciar son: \n";
    cout << "  Videojuego: " << nombreVj << "\n";
    cout << "  Tipo Partida: " << tipoPartida << "\n";
    if (tipoPartida == "Individual") {
        if (idAnterior != -1) {
            cout << "  Id Partida anterior: " << idAnterior << "\n";
        } else {
            cout << "  No es continuacion de otra Partida \n";
        }
    } else {
        if (enVivo) {
            cout << "  La partida se transmite en vivo. \n";
        } else {
            cout << "  La partida no esta siendo transmitida. \n";
        }
        cout << "  Los jugadores unidos son: \n";
        for (set<string>::iterator it = jIngresados->begin(); it != jIngresados->end(); ++it) {
            cout << "    " << *it << "\n";
        }
    }
    delete jIngresados;
    cout << "Confirma el Alta de la Partida? (1. Si, 2. No)";
    string confirmar;
    while (true) {
        getline(cin, confirmar);
        if ((confirmar == "1") || (confirmar == "Si") || (confirmar == "si") || (confirmar == "2") 
                || (confirmar == "No") || (confirmar == "no")) {
            break;
        } else {
            reprintln();
            cout << "Porfavor, ingrese una opcion valida: ";
        }
    }
    if ((confirmar == "1") || (confirmar == "Si") || (confirmar == "si")) {
        interface->confirmarPartida();
        cout << "La partida se ha dado de alta exitosamente. \n";
    }
    interface->clearCache();
    pkey();
    return 0;
}

int Sistema::abandonarPartidaMultijugador(){
    LaFabrica* factory = LaFabrica::getInstance();
    IIFPController* interface = factory->getIIFPController();
    map<DtFechaHora, DtPartidaMultijugador*>* multiActivas = interface->obtenerPartidasMultiActivas();
    cout << "Abandonar Partida Multijugador \n \n";
    cout << "Partidas multijugador activas a las que se unio: \n";
    for (map<DtFechaHora, DtPartidaMultijugador*>::iterator it = multiActivas->begin(); it != multiActivas->end(); ++it) {
        cout << *it->second << "\n";
    }
    cout << "Ingrese la Id de la partida multijugador a abandonar (ingrese '-1' si desea cancelar): \n";
    int id;
    while (true) {
        if (!(cin >> id)) {
		    clinput();
            reprintln();
            cout << "Porfavor, ingrese un Id correcto (ingrese '-1' si desea cancelar): ";
        } else {
            if (id == -1) {
                break;
            }
            clinput();
            bool exId = false;
            for (map<DtFechaHora, DtPartidaMultijugador*>::iterator it = multiActivas->begin(); it != multiActivas->end(); ++it) {
                if (it->second->getId() == id) {
                    exId = true;
                    break;
                }
            }
            if (!exId) {
                reprintln();
                cout << "Porfavor, ingrese un Id correcto (ingrese '-1' si desea cancelar): ";
            } else {
                break;
            }
        }
    }
    for (map<DtFechaHora, DtPartidaMultijugador*>::iterator it = multiActivas->begin(); it != multiActivas->end(); ++it) {
        delete it->second;
    }
    delete multiActivas;
    if (id != -1) {
        interface->confirmarAbandonarPartida(id);
        cout << "Se ha abandonado la partida multijugador (ID: " << id << ") correctamente.";
    } else {
        cout << "Se ha cancelado el abandono de la partida multijugador.";
    }
    interface->clearCache();
    pkey();
    return 0;
}

int Sistema::finalizarPartida(){
    LaFabrica* factory = LaFabrica::getInstance();
    IIFPController* interface = factory->getIIFPController();
    map<DtFechaHora, DtPartida*>* partidasActivas = interface->obtenerPartidasActivas();
    cout << "Finalizar Partida \n \n";
    cout << "Partidas actualmente activas: \n";
    DtPartidaIndividual* pInd;
    DtPartidaMultijugador* pMulti;
    for (map<DtFechaHora, DtPartida*>::iterator it = partidasActivas->begin(); it != partidasActivas->end(); ++it) {
        if ((pInd = dynamic_cast<DtPartidaIndividual*>(it->second))) {
            cout << *pInd << "\n";
        } else {
            pMulti = dynamic_cast<DtPartidaMultijugador*>(it->second);
            cout << *pMulti << "\n";
        }
    }
    cout << "Ingrese la Id de la partida a finalizar (ingrese '-1' si desea cancelar): \n";
    int id;
    while (true) {
        if (!(cin >> id)) {
		    clinput();
            reprintln();
            cout << "Porfavor, ingrese un Id correcto (ingrese '-1' si desea cancelar): ";
        } else {
            clinput();
            bool exId = false;
            for (map<DtFechaHora, DtPartida*>::iterator it = partidasActivas->begin(); it != partidasActivas->end(); ++it) {
                if (it->second->getId() == id) {
                    exId = true;
                    break;
                }
            }
            if (!exId) {
                reprintln();
                cout << "Porfavor, ingrese un Id correcto (ingrese '-1' si desea cancelar): ";
            } else {
                break;
            }
        }
    }
    for (map<DtFechaHora, DtPartida*>::iterator it = partidasActivas->begin(); it != partidasActivas->end(); ++it) {
        delete it->second;
    }
    delete partidasActivas;
    if (id != -1) {
        interface->confirmarAbandonarPartida(id);
        cout << "Se ha finalizado la partida (ID: " << id << ") correctamente.";
    } else {
        cout << "No se ha finalizado la partida.";
    }
    interface->clearCache();
    pkey();
    return 0;
}

string Sistema::getLoggedUserEmail(){
    return "lol";
}

Sistema::~Sistema(){
//Hago las cosas pertinentes para cerrar el sistema... (se libera memoria)
}


