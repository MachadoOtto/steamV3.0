/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Implementacion de main
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <ctime>
#include <limits> // necesario para limpiar el buffer de entrada.
#include "include/sistema.h"

using namespace std;

int main() {
    Sistema* sys = new Sistema();
    int controlVar=0;
    while (controlVar != 7) {
        cout << "--- MENU --- \n\n";
        cout << "Seleccione una opcion\n";
        cout << " 1. Agregar Jugador\n";
        cout << " 2. Agregar Videojuego\n";
        cout << " 3. Obtener Jugadores\n";
        cout << " 4. Obtener Videojuegos\n";
        cout << " 5. Obtener Partidas\n";
        cout << " 6. Iniciar Partida\n";
        cout << " 7. Salir\n\n";
        cout << "Ingrese una opcion: ";
        cin >> controlVar;
        if (cin.fail()) {// Miguel: se realiza lo mismo que para 'edad' al ingresar jugadores.
            // Se generaba otro loop infinito si ingresabas 'char'. Basicamente el mismo error.
            cin.clear(); // limpia las flags erroneas.
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // descarta el resto de la entrada.
            controlVar = 0; // Hacemos que salte el error del menu en el switch.
        }
        cout << endl;
        switch (controlVar) {
	    //Agregar Jugador
            case 1:{ 
                string nickname;
                int edad;
                string password;
                cout << "Nickname: ";
                cin >> nickname;
                cout << "Edad: ";
                while (true) {
                    cin >> edad;
                    if (cin.fail()) {// Miguel: ingresa solo si el buffer intenta leer un valor que no sea del tipo int.
                        // si esto no se agrega tendriamos un loop infinito!
                        cin.clear(); // limpia las flags erroneas.
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // descarta el resto de la entrada.
                        cout << "Edad invalida. \nIngresela nuevamente: ";
                    } else {
                        break; // corta el while al ingresar un 'int' sea cual sea.
                    }
                }
                cout << "Password: ";
                cin >> password;
                try {
                    sys->agregarJugador(nickname, edad, password);
                    cout << "Se ha registrado a " << nickname << " en el sistema.\n";
                }
                catch (invalid_argument &e) {
                    cout << e.what() << endl;
                    break;
                }
                break;
	        }
            case 2:{ //Agregar Videojuego
                string nombre;
		        string input_genero;
                TipoJuego genero;

                cout << "Nombre del videojuego: ";
                cin >> nombre;
                cout << "Genero (Accion/Aventura/Deporte/Otro): ";
                cin >> input_genero;
		        if(input_genero == "Accion")
		            genero = TipoJuego::Accion;
		        else if(input_genero == "Aventura")
		            genero = TipoJuego::Aventura;
		        else if(input_genero == "Deporte")
		            genero = TipoJuego::Deporte;
		        else if(input_genero == "Otro")
		            genero = TipoJuego::Otro;
                try {
                    sys->agregarVideojuego(nombre, genero);
                    cout << "Se ha registrado el videojuego " << nombre << " en el sistema.\n";
                }
                catch (invalid_argument &e) {
                    cout << e.what() << endl;
                    break;
                }
		        break;
	        }
            case 3:{ //Obtener Jugadores
                int cantJugadores;
                DtJugador** arrayJugadores = sys->obtenerJugadores(cantJugadores);

                cout << "Hay " << cantJugadores << " jugadores registrados en el sistema.\n\n";
                for (int i = 0; i < cantJugadores; i++) {
                    cout << i+1 << ". Nickname: " << arrayJugadores[i]->getNickname() << endl;
                    cout << "   Edad: " << arrayJugadores[i]->getEdad() << endl;
                    cout << endl;
                    delete arrayJugadores[i];
                } 
                delete[] arrayJugadores;
		        break;
	        }
            case 4:{ //Obtener Videojuegos
                int cantVideojuegos;
                DtVideojuego** arrayVideojuegos = sys->obtenerVideojuegos(cantVideojuegos);
			
                cout << "Hay " << cantVideojuegos << " videojuegos registrados en el sistema.\n";
                cout << endl;
		        TipoJuego gen;
		        string gen_str;
                for (int i = 0; i < cantVideojuegos; i++) {
		            gen = arrayVideojuegos[i]->getGenero();
		            if(gen == TipoJuego::Accion)
			            gen_str = "Accion";	
		            else if(gen == TipoJuego::Aventura)
			            gen_str = "Aventura";
		            else if(gen == TipoJuego::Deporte)
			            gen_str = "Deporte";
		            else if(gen == TipoJuego::Otro)
			            gen_str = "Otro";
                    cout << i+1 << ". Titulo: " << arrayVideojuegos[i]->getNombre() << endl;
                    cout << "   Genero: " << gen_str << endl;
                    cout << "   Total horas de juego: " << arrayVideojuegos[i]->getTotalHorasDeJuego() << endl;
                    cout << endl;
                    delete arrayVideojuegos[i]; // Se borra el DtVideojuego 'i'.
                }
                delete[] arrayVideojuegos;
            break;
	        }
            case 5:{ //Obtener Partidas
                string videojuego;
                int cantPartidas;

                cout << "Videojuego del cual desea obtener sus partidas: ";
                cin >> videojuego;

                try {
                    DtPartida** arrayPartidas = sys->obtenerPartidas(videojuego, cantPartidas);
                    cout << "Hay " << cantPartidas << " partidas registradas en el sistema.\n";
                    DtPartidaIndividual* ptrIndividual;
                    DtPartidaMultijugador* ptrMulti;
                    for (int i = 0; i < cantPartidas; i++) {
                        ptrIndividual = dynamic_cast<DtPartidaIndividual*>(arrayPartidas[i]);
                        if (ptrIndividual == nullptr) { //Multijugador
                            ptrMulti = dynamic_cast<DtPartidaMultijugador*>(arrayPartidas[i]);
			                int cardInvitees = ptrMulti->getCantidadJugadoresUnidos();
                            cout << i+1 << ". Fecha: " << ptrMulti->getFecha() << endl;
                            cout << "   Duracion: " << ptrMulti->getDuracion() << endl;
                            string tev = "NO";
                            if (ptrMulti->getTransmitidaEnVivo()) {
                                tev = "SI";
                            }
                            cout << "   Trasmtida en vivo: " << tev << endl;
                            cout << "   Jugadores unidos: " << cardInvitees << endl << endl;
                            string * ju = ptrMulti->getNicknameJugadoresUnidos();
                            for (int j = 0; j < cardInvitees; j++) {
                                cout << "    " << j+1 << ". " << ju[j] << endl;
                            }
                        } else { //Individual
                            cout << i+1 << ". Fecha: " << ptrIndividual->getFecha() << endl;
                            cout << "   Duracion: " << ptrIndividual->getDuracion() << endl;
                            string cpa = "NO";
                            if (ptrIndividual->getContinuaPartidaAnterior()) {
                                cpa = "SI";
                            }
                            cout << "   Es continuacion de una partida anterior: " << cpa << endl;
                        }
                        delete arrayPartidas[i]; // Se borra el DtPartida 'i'.
                    }
                    delete[] arrayPartidas;
                }
                catch (invalid_argument &e) {
                    cout << e.what() << endl;
                    break;
                }
		        break;
	        }
            case 6:{ //Iniciar Partida
                string nickname;
                string videojuego;
                DtPartida* datos;
                float duracion;
                int tipoPartida;
                DtPartidaIndividual* ptrIndividual;
                DtPartidaMultijugador* ptrMulti;
                cout << "Nickname: ";
                cin >> nickname;
                cout << "Videojuego: ";
                cin >> videojuego;
                // Miguel: correccion de time.
                cout << "Ingrese la fecha de la partida dd/mm/yyyy hh:mm .\nSi desea iniciar la partida con la fecha actual del sistema escriba ""ahora"".\nFecha: ";
		string date_input;
		cin >> date_input;
                int d,m,y,h,min;
		if (date_input == "ahora") {
	            time_t now = time(0);
                    tm* time = localtime(&now);
                    d = time->tm_mday;
                    m = time->tm_mon + 1; // tm_mon devuelve el mes donde enero es igual a 0 (por lo tanto se suma uno).
                    y = time->tm_year + 1900; // tm_year devuelve los anios despues de 1900 (por lo tanto hay que sumarlos).
                    h = time->tm_hour;
    	            min = time->tm_min;
	        }
		else {
                    sscanf(date_input.c_str(),"%d/%d/%d %d:%d",&d,&m,&y,&h,&min);
		}
		DtFechaHora fechaSistema(d,m,y,h,min); // fechaSistema(dia, mes, anio, hora, min).
               
                cout << "Duracion: ";
                while (true) {
                    // Correccion del error del buffer de entrada para float. (Error de loop infinito).
                    cin >> duracion;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                        cout << "Duracion invalida.\nIngresela nuevamente: ";
                    } else {
                        break;
                    }
                }

                cout << endl;
                cout << "Tipo de partida:" << endl;
                cout << " 1.Individual" << endl;
                cout << " 2.Multijugador" << endl << endl;
                cout << "Seleccione una opcion: ";
                // Correccion del error del buffer de entrada para int. (Error de loop infinito).
                cin >> tipoPartida;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    tipoPartida = 0; // Hacemos saltar el error del switch de tipoPartida.
                }
                cout << endl;
                switch(tipoPartida) {
                    case 1:{ //Individual
                        bool cpa;
                        cout << "Es continuacion de una partida anterior (1.Si/0.No): ";
                        cin >> cpa;
			            ptrIndividual = new DtPartidaIndividual(cpa,fechaSistema,duracion);
                        try {
                            sys->iniciarPartida(nickname, videojuego, ptrIndividual);
                        }
                        catch (invalid_argument &e) {
                            cout << e.what() << endl;
                            break;
                        }
			            break;
		            }
                    case 2:{ //Multijugador
                        bool tev;
                        cout << "Es transmitida en vivo (1.Si/0.No): ";
                        cin >> tev;
                        int cantJugadoresUnidos;
                        cout << "Cantidad de jugadores unidos: ";
                        cin >> cantJugadoresUnidos;
                        string *nicknameJugadoresUnidos;
                        nicknameJugadoresUnidos = new string[cantJugadoresUnidos];
                        cout << "Ingrese el nickname de los jugadores unidos" << endl;
                        for (int i = 0; i < cantJugadoresUnidos; i++) {
                            cout << "Jugador " << i+1 << ":";
                            cin >> nicknameJugadoresUnidos[i];
                        }
			            ptrMulti = new DtPartidaMultijugador(tev,nicknameJugadoresUnidos,cantJugadoresUnidos,fechaSistema,duracion);
                        try {
                            sys->iniciarPartida(nickname, videojuego, ptrMulti);
                        }
                        catch (invalid_argument &e) {
                            cout << e.what() << endl;
                            break;
                        }
			            break;
		            }
                    default:{
                        cout << "La opcion ingresada no es valida, ingrese otra porfavor: " << endl;
               	    	break;
		            }
		            break;
		        }
	        }
            case 7: //Salir
		        break;
            default:{
                cout << "La opcion ingresada no es valida, ingrese otra porfavor.\n";
		        break;
	        }
	    }
    }
    delete sys;
    return 0;
}
