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

using namespace std;

void cls(){
    cout << "\033[2J\033[1;1H";
}

void clinput(){
    cin.clear(); 
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
}

void pkey(){
    char t;
    cout << "Presione ENTER para volver al menu principal...\n";
    t = cin.get();
    if(t != '\n')
	clinput();
}

void ptitle(){
    cout << "\nBienvenido a,\n\n"
 "  $$$$$$\\    $$\\                                                              /$$$$$$       /$$$$$$  \n"
 " $$  __$$\\   $$ |                                                             /$$__  $$     /$$$_  $$ \n"
 " $$ /  \\__|$$$$$$\\    $$$$$$\\   $$$$$$\\  $$$$$$\\$$$$\\         /$$    /$$|__/  \\ $$    | $$$$\\ $$ \n"
 " \\$$$$$$\\  \\_$$  _|  $$  __$$\\  \\____$$\\ $$  _$$  _$$\\      |  $$  /$$/   /$$$$$/    | $$ $$ $$ \n"
 "  \\____$$\\   $$ |    $$$$$$$$ | $$$$$$$ |$$ / $$ / $$ |           \\  $$/$$/   |___  $$    | $$\\ $$$$ \n"
 " $$\\   $$ |  $$ |$$\\ $$   ____|$$  __$$ |$$ | $$ | $$ |            \\  $$$/   /$$  \\ $$    | $$ \\ $$$ \n"
 " \\$$$$$$  |  \\$$$$  |\\$$$$$$$\\ \\$$$$$$$ |$$ | $$ | $$ |          \\  $/   |  $$$$$$/ /$$|  $$$$$$/ \n"
 "  \\______/    \\____/  \\_______| \\_______|\\__| \\__| \\__|         \\_/     \\______/ |__/ \\______/  \n";
}


void reprintln(){
    cout << "\033[A                                                                                                 \r";
}
int takeInputrange(int min, int max){
    while(true){
        if (!(cin >> controlVar) || (controlVar > max || controlVar < min)) {
	    clinput();
	    reprintln();
	    cout << "Por favor ingrese una opcion valida: ";
	}
	else
	    break;
    }
    clinput();
    cout << endl;
    return controlVar;
}

int menuUsuario(){
    int controlVar=0;    
    while (controlVar!=7){
	cls();
	ptitle();
	cout << "Fecha actual del sistema: " << FechaSistema::Fecha << endl;
	cout << "Usted ha iniciado sesion como: " << sys->getLoggedUserEmail() << "(Jugador)\n";
        cout << "──────────  Menu Jugador ──────────" << endl << endl;
        cout << "Por favor seleccione una opcion:" << endl;
        cout << " 1. Suscribirse a videojuego" << endl;
        cout << " 2. Asignar puntaje a videojuego" << endl;
        cout << " 3. Iniciar partida" << endl;
        cout << " 4. Abandonar partida multijugador" << endl;
        cout << " 5. Finalizar partida" << endl;
        cout << " 6. Ver informacion de videojuego" << endl;
        cout << " 7. Salir" << endl;
        cout << "Ingrese una opcion: ";		
	
	controlVar = takeInputRange(1,7);
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
		sys->verInformacionDeVideojuego();
		break;
	    }
	}
    }
    return 0;

}

int menuDesarrollador(){
    int controlVar=0;    
    while (controlVar!=7){
	cls();
	ptitle();
	cout << "Fecha actual del sistema: " << FechaSistema::Fecha << endl;
	cout << "Usted ha iniciado sesion como: " << sys->getLoggedUserEmail() << "(Desarrollador)\n";
        cout << "──────────  Menu Desarrollador ──────────" << endl << endl;
        cout << "Por favor seleccione una opcion:" << endl;
        cout << " 1. Agregar categoria" << endl;
        cout << " 2. Publicar videojuego" << endl;
        cout << " 3. Eliminar videojuego" << endl;
        cout << " 4. Seleccionar estadisticas" << endl;
        cout << " 5. Consultar estadisticas" << endl;
        cout << " 6. Ver informacion de videojuego" << endl;
        cout << " 7. Salir" << endl;
        cout << "Ingrese una opcion: ";		
	
	controlVar = takeInputRange(1,7);
        switch (controlVar) {
	    case 1:{
		sys->agregarCategoria();
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
	cout << "Fecha actual del sistema: " << FechaSistema::Fecha << endl;
        cout << "──────────  Menu Principal ──────────" << endl << endl;
        cout << "Por favor seleccione una opcion:" << endl;
        cout << " 1. Alta de Usuario" << endl;
        cout << " 2. Iniciar sesion" << endl;
        cout << " 3. Modificar fecha del sistema" << endl;
        cout << " 4. Cargar datos de prueba" << endl;
        cout << " 5. Salir" << endl;
        cout << "Ingrese una opcion: ";		
	
	controlVar = takeInputRange(1,5);
        switch (controlVar) {
	    case 1: {
		sys->altaUsuario();
		break;
	    }
	    case 2: {
		if ((x = sys->iniciarSesion()) == 1) menuUsusario();
		else if (x==2) menuDesarrollador();
		break;
	    }
	    case 3: {
		sys->modificarFecha();
		break;
	    }
	    case 4: {
		sys->cargarDatosDePrueba();
		break;
	    }
	    case 5: {
		delete sys;
		break;
	    }
	}
    }
    return 0;
}





























            /* Agregar Jugador */
            case 1: { 
                string password,nickname;
                int edad;
		
		cout << "Por favor ingrese los siguientes datos del nuevo jugador.\n";
                cout << "Nickname: ";
                getline(cin, nickname);
                cout << "Edad: ";
                while (true) {
                    if (!(cin >> edad)){
			clinput();
			reprintln();
                        cout << "Porfavor, ingrese una edad interpretable: ";
                    } 
		    else 
			break;
                }
		clinput();
                cout << "Password: ";
                getline(cin, password);
                try {
                    sys->agregarJugador(nickname, edad, password);
                    cout << "Se ha registrado al jugador \"" << nickname << "\" en el sistema.\n";
		    pkey();
                }
                catch (invalid_argument &e) {
                    cout << "Error: " << e.what() << endl;
		    pkey();
                    break;
                }
                break;
            }
            /* Agregar Videojuego */
            case 2: { 
                string nombre;
                string input_genero;
                TipoJuego genero;

		cout << "Por favor ingrese los siguientes datos del nuevo videojuego.\n";
                cout << "Nombre: ";
                getline(cin, nombre);
                cout << "Genero (1.Accion/2.Aventura/3.Deporte/4.Otro): ";
                getline(cin, input_genero);
                if ((input_genero == "Accion") || (input_genero == "accion") || (input_genero == "1"))
                    genero = TipoJuego::Accion;
                else if ((input_genero == "Aventura") || (input_genero == "aventura") || (input_genero == "2"))
                    genero = TipoJuego::Aventura;
                else if ((input_genero == "Deporte") || (input_genero == "deporte") || (input_genero == "3")) 
                    genero = TipoJuego::Deporte;
		else if ((input_genero == "Otro") || (input_genero == "Otro") || (input_genero == "4"))
		    genero = TipoJuego::Otro;
                else{
		    cout << "Nota: El genero \"" << input_genero << "\" no existe como tal en el sistema. Se le ha asignado el genero \"Otro\".\n"; 
                    genero = TipoJuego::Otro;
		}
                try {
                    sys->agregarVideojuego(nombre, genero);
                    cout << "Se ha registrado el videojuego \"" << nombre << "\", de genero ";
                    std::string gen;
                    if(genero == TipoJuego::Accion)
                        cout << "accion";
                    else if(genero == TipoJuego::Aventura)
                        cout << "aventura";
                    else if(genero == TipoJuego::Deporte)
                        cout << "deporte";
                    else if(genero == TipoJuego::Otro)
                        cout << "otro";
                    cout << ", en el sistema." << endl;
		    pkey();
                }
                catch (invalid_argument &e) {
                    cout << "ERROR: "<< e.what() << endl;
		    pkey();
                    break;
                }
                break;
            }
            /* Obtener Jugadores */
            case 3: {
                int cantJugadores;
                DtJugador** arrayJugadores = sys->obtenerJugadores(cantJugadores);
		
		if(cantJugadores == 1)
		    cout << "Hay " << cantJugadores << " jugador registrado en el sistema:" << endl << endl;
		else if(cantJugadores == 0)
		    cout << "No hay jugadores registrados en el sistema." << endl << endl;
		else
		    cout << "Hay " << cantJugadores << " jugadores registrados en el sistema:" << endl << endl;
                for (int i = 0; i < cantJugadores; i++) {
                    cout << i+1 << ". Nickname: " << arrayJugadores[i]->getNickname() << endl;
                    cout << "   Edad: " << arrayJugadores[i]->getEdad() << endl;
                    cout << endl;
                    delete arrayJugadores[i];
                } 
                delete [] arrayJugadores;
		pkey();
                break;
            }
            /* Obtener Videojuegos */
            case 4: { 
                int cantVideojuegos;
                DtVideojuego** arrayVideojuegos = sys->obtenerVideojuegos(cantVideojuegos);
		TipoJuego gen;
                string gen_str;

		if(cantVideojuegos == 0)
		    cout << "No hay videojuegos registrados en el sistema." << endl << endl;
		else if (cantVideojuegos == 1)
		    cout << "Hay " << cantVideojuegos << " videojuego registrado en el sistema:" << endl << endl;
		else
		    cout << "Hay " << cantVideojuegos << " videojuegos registrados en el sistema:" << endl << endl;

                for (int i = 0; i < cantVideojuegos; i++) {
                    gen = arrayVideojuegos[i]->getGenero();
                    if (gen == TipoJuego::Accion)
                        gen_str = "Accion"; 
                    else if (gen == TipoJuego::Aventura)
                        gen_str = "Aventura";
                    else if(gen == TipoJuego::Deporte)
                        gen_str = "Deporte";
                    else if(gen == TipoJuego::Otro)
                        gen_str = "Otro";
                    cout << i+1 << ". Titulo: " << arrayVideojuegos[i]->getNombre() << endl;
                    cout << "   Genero: " << gen_str << endl;
                    cout << "   Total de horas de juego: " << arrayVideojuegos[i]->getTotalHorasDeJuego() << " hs" << endl;
                    cout << endl;
                    delete arrayVideojuegos[i]; // Se borra el DtVideojuego 'i'.
                }
		pkey();
                delete[] arrayVideojuegos;
                break;
            }
            /* Obtener Partidas */
            case 5: {
                string videojuego;
                int cantPartidas;
                cout << "Ingrese el nombre del videojuego del cual desea obtener sus respectivas partidas: ";
                getline(cin, videojuego);
                try {
                    DtPartida** arrayPartidas = sys->obtenerPartidas(videojuego, cantPartidas);
		    DtPartidaIndividual* ptrIndividual;
                    DtPartidaMultijugador* ptrMulti;

		    if(cantPartidas == 0)
                    cout << "El videojuego \"" << videojuego << "\" no tiene partidas registradas en el sistema." << endl;
		    else if(cantPartidas == 1)
			cout << "El videojuego \"" << videojuego << "\" tiene " << cantPartidas << " partida registrada en el sistema." << endl;
		    else
			cout << "El videojuego \"" << videojuego << "\" tiene " << cantPartidas << " partidas registradas en el sistema." << endl;

                    for (int i = 0; i < cantPartidas; i++) {
                        cout << endl;
                        ptrIndividual = dynamic_cast<DtPartidaIndividual*>(arrayPartidas[i]);
                        if (ptrIndividual == nullptr) {
                            /* Multijugador */
                            ptrMulti = dynamic_cast<DtPartidaMultijugador*>(arrayPartidas[i]);
                            cout << *ptrMulti;
                        }
                        else {
                            /* Individual */
                            cout << *ptrIndividual;
                        }
                        delete arrayPartidas[i]; // Se borra el DtPartida 'i'.
                    }
                    delete[] arrayPartidas;
                    cout << endl;
		    pkey();
                }
                catch (invalid_argument &e) {
                    cout << "ERROR: " << e.what() << endl;
		    pkey();
                    break;
                }
                break;
            }
            /* Iniciar Partida */
            case 6: {
                // Se mueve el try a una zona mas global para que pueda obtener el invalid_argument de PIndividual, PMultijugador y
                //  DtFechaHora a la vez; este ultimo no tenia ningun try catch.
                try {
                    string nickname;
                    string videojuego;
                    float duracion;
                    int tipoPartida;
                    int d,m,y,h,min;
                    DtPartidaIndividual* ptrIndividual;
                    DtPartidaMultijugador* ptrMulti;
                    string date_input;
		    cout << "Por favor ingrese los siguientes datos de la nueva partida:\n";

                    cout << "Nickname del jugador que inicia la partida: ";
                    getline(cin, nickname);
                    cout << "Videojuego al cual pertenece la partida: ";
                    getline(cin, videojuego);

                    // Miguel: correccion de time.
		    
		    cout << "Ingrese la fecha de creacion de la partida usando el formato dd/mm/yyyy hh:mm ." << endl;
		    cout << "Si desea iniciar la partida con la fecha actual del sistema escriba 'ahora'." << endl;
		    cout << "Fecha: ";
		    DtFechaHora *fechaSistema;
		    bool fecha_check=false;
		    while(!fecha_check){
			try{
			    getline(cin,date_input);
			    if (date_input == "ahora") {
				time_t now = time(0);
				tm* time = localtime(&now);
				d = time->tm_mday;
				m = time->tm_mon + 1; // tm_mon devuelve el mes donde enero es igual a 0 (por lo tanto se suma uno).
				y = time->tm_year + 1900; // tm_year devuelve los anios despues de 1900 (por lo tanto hay que sumarlos).
				h = time->tm_hour;
				min = time->tm_min;
			    }
			    else{
				if (sscanf(date_input.c_str(),"%d/%d/%d %d:%d",&d,&m,&y,&h,&min) != 5)
				    throw invalid_argument("");	
			    }
			    fechaSistema = new DtFechaHora(d,m,y,h,min); // fechaSistema(dia, mes, anio, hora, min).
			    fecha_check=true;
			}
			catch(invalid_argument &e){
			    reprintln();
			    cout << "Por favor ingrese una fecha valida: ";
			}
		    }
                    cout << "Duracion (en horas): ";
                    while (true) {
                        if (!(cin >> duracion)) {
			    clinput();
			    reprintln();
                            cout << "Porfavor, ingrese una duracion valida: ";
                        }
                        else 
                            break;
                    }
		    clinput();

                    cout << endl;
                    cout << "Tipo de partida:" << endl;
                    cout << " 1.Individual" << endl;
                    cout << " 2.Multijugador" << endl << endl;
                    cout << "Seleccione una opcion: ";
                    while (true) {
                        if (!(cin >> tipoPartida) || !((tipoPartida == 1) || (tipoPartida == 2)) ) {
			    clinput();
			    reprintln();
                            cout << "Por favor ingrese una opcion valida: ";
                        }
                        else
                            break;                            
                    }
                    cout << endl;
		    clinput();
                    switch(tipoPartida) {
                        case 1: { 
                            /* Individual */
                            bool cpa;
			    string cpa_input;
                            cout << "Es continuacion de una partida anterior? (1.Si/0.No): ";
			    while (true) {
				getline(cin,cpa_input);
				if (!( (cpa_input == "1") || (cpa_input == "0") || (cpa_input == "si") || (cpa_input == "no") || (cpa_input == "Si") || (cpa_input == "No"))){
				    reprintln();
				    cout << "Por favor ingrese una opcion valida (1.Si/0.No): ";
				}
				else
				    break;                            
			    }
			    if(cpa_input == "1" || cpa_input == "Si" || cpa_input == "si")
				cpa = true;
			    else
				cpa = false;

                            ptrIndividual = new DtPartidaIndividual(cpa,*fechaSistema,duracion);
			    try{
				sys->iniciarPartida(nickname, videojuego, ptrIndividual);
			    }
			    catch(invalid_argument &e){
				cout << "ERROR: " << e.what() << endl << endl;
				pkey();
				delete ptrIndividual;
				delete fechaSistema;
				break;
			    }
                            cout << "Se registro la partida individual exitosamente en el sistema." << endl;
			    pkey();
                            delete ptrIndividual; 
			    delete fechaSistema;
                            break;
			}
                        case 2: { 
                            /* Multijugador */
                            bool tev;
			    string cpa_input; //guille: reutilizando codigo xdd

                            cout << "Es transmitida en vivo? (1.Si/0.No): ";
			    while (true) {
				getline(cin,cpa_input);
				if (!( (cpa_input == "1") || (cpa_input == "0") || (cpa_input == "si") || (cpa_input == "no") || (cpa_input == "Si") || (cpa_input == "No"))){
				    reprintln();
				    cout << "Por favor ingrese una opcion valida (1.Si/0.No): ";
				}
				else
				    break;                            
			    }
			    if(cpa_input == "1" || cpa_input == "Si" || cpa_input == "si")
				tev = true;
			    else
				tev = false;

                            int cantJugadoresUnidos;
                            cout << "Cantidad de jugadores adicionales que se unen a la partida: ";
                            while (true) {
                                if (!(cin >> cantJugadoresUnidos)) {
				    clinput();
				    reprintln();
                                    cout << "Porfavor, ingrese una cantidad valida: ";
                                }
                                else
                                    break;
                            }
			    clinput();

                            string *nicknameJugadoresUnidos;
			    cantJugadoresUnidos++;
                            nicknameJugadoresUnidos = new string[cantJugadoresUnidos]; //un gracioso se le ocurrio que el host debe estar en la lista
			    nicknameJugadoresUnidos[0] = nickname;
                            cout << "Ingrese el nickname de los jugadores que se unen a la partida: " << endl << endl;
                            for (int i = 1; i < cantJugadoresUnidos; i++) {
                                cout << "Jugador " << i+1 << ": ";
                                getline(cin, nicknameJugadoresUnidos[i]);
                            }
                            ptrMulti = new DtPartidaMultijugador(tev,nicknameJugadoresUnidos,cantJugadoresUnidos,*fechaSistema,duracion);
			    try{
				sys->iniciarPartida(nickname, videojuego, ptrMulti);
			    }
			    catch(invalid_argument &e){
				cout << "ERROR: " << e.what() << endl << endl;
				pkey();
				delete ptrMulti;
				delete fechaSistema;
				break;
			    }
                            cout << endl << "Se registro la partida multijugador exitosamente en el sistema." << endl;
			    pkey();
                            delete ptrMulti; 
			    delete fechaSistema;
                            break;
                        }
                        default: {
                            cout << "Se ha producido un error con su opcion. Volviendo al menu." << endl;
                            break;
                        }
                        break;
                    }
                }
                catch (invalid_argument &e) {
                    cout << "ERROR: " << e.what() << endl << endl;
                    pkey();
                    break;
                }
                break;
            }
            /* Salir */
            case 7: 
            	cout << "Gracias por utilizar Steam 2.0. \n";
                break;
	
            default: {
                cout << "Porfavor, ingrese una opcion valida: ";
                break;
            }
        }
        cout << endl << endl;
    }
    delete sys;
    return 0;
}
