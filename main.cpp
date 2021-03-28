/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Implementacion de main
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
#include <conio.h> // System("clear") para Linux
#include <ctime>
#include <limits> // Necesario para limpiar el buffer de entrada.
#include "include/sistema.h"

using namespace std;

int main() {
    Sistema* sys = new Sistema();
    int controlVar=0;
    while (controlVar != 7) {
        cout << "--- MENU ---" << endl << endl;
        cout << "Seleccione una opcion:" << endl;
        cout << " 1. Agregar Jugador" << endl;
        cout << " 2. Agregar Videojuego" << endl;
        cout << " 3. Obtener Jugadores" << endl;
        cout << " 4. Obtener Videojuegos" << endl;
        cout << " 5. Obtener Partidas" << endl;
        cout << " 6. Iniciar Partida" << endl;
        cout << " 7. Salir" << endl << endl;
        cout << "Ingrese una opcion: ";
        if (!(cin >> controlVar)) {// Miguel: se realiza lo mismo que para 'edad' al ingresar jugadores.
            // Se generaba otro loop infinito si ingresabas 'char'. Basicamente el mismo error.
            cin.clear(); // Limpia flags erroneas.
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta el resto de la entrada.
            controlVar = 0; // Hacemos que salte el error del menu en el switch.
        }
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << endl;
        switch (controlVar) {
            /* Agregar Jugador */
            case 1: { 
                string nickname;
                int edad;
                string password;
                cout << "Nickname: ";
                getline(cin, nickname);
                cout << "Edad: ";
                while (true) {
                    if (!(cin >> edad)) {// Miguel: ingresa solo si el buffer intenta leer un valor que no sea del tipo int.
                        // Si esto no se agrega tendriamos un loop infinito!
                        cin.clear(); // Limpia flags erroneas.
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta el resto de la entrada.
                        cout << "Porfavor, ingrese una edad valida: ";
                    } else {
                        break; // Corta el while al ingresar un 'int' sea cual sea.
                    }
                }
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Password: ";
                getline(cin, password);
                try {
                    sys->agregarJugador(nickname, edad, password);
                    cout << "Se ha registrado a " << nickname << " en el sistema." << endl << endl;
                }
                catch (invalid_argument &e) {
                    cout << e.what() << endl << endl;
                    break;
                }
                break;
            }
            /* Agregar Videojuego */
            case 2: { 
                string nombre;
                string input_genero;
                TipoJuego genero;
                cout << "Nombre del videojuego: ";
                getline(cin, nombre);
                cout << "Genero (Accion/Aventura/Deporte/Otro): ";
                getline(cin, input_genero);
                if ((input_genero == "Accion") || (input_genero == "accion"))
                    genero = TipoJuego::Accion;
                else if ((input_genero == "Aventura") || (input_genero == "aventura"))
                    genero = TipoJuego::Aventura;
                else if ((input_genero == "Deporte") || (input_genero == "deporte"))
                    genero = TipoJuego::Deporte;
                else
                    genero = TipoJuego::Otro;
                try {
                    sys->agregarVideojuego(nombre, genero);
                    cout << "Se ha registrado el videojuego " << nombre << ", de tipo ";
                    std::string gen;
                    if(genero == TipoJuego::Accion)
                        cout << "Accion";
                    else if(genero == TipoJuego::Aventura)
                        cout << "Aventura";
                    else if(genero == TipoJuego::Deporte)
                        cout << "Deporte";
                    else if(genero == TipoJuego::Otro)
                        cout << "Otro";
                    cout << ", en el sistema." << endl;
                }
                catch (invalid_argument &e) {
                    cout << e.what() << endl << endl;
                    break;
                }
                break;
            }
            /* Obtener Jugadores */
            case 3: {
                int cantJugadores;
                DtJugador** arrayJugadores = sys->obtenerJugadores(cantJugadores);
                cout << "Hay " << cantJugadores << " jugadores registrados en el sistema." << endl << endl;
                for (int i = 0; i < cantJugadores; i++) {
                    cout << i+1 << ". Nickname: " << arrayJugadores[i]->getNickname() << endl;
                    cout << "   Edad: " << arrayJugadores[i]->getEdad() << endl;
                    cout << endl;
                    delete arrayJugadores[i];
                } 
                delete [] arrayJugadores;
                break;
            }
            /* Obtener Videojuegos */
            case 4: { 
                int cantVideojuegos;
                DtVideojuego** arrayVideojuegos = sys->obtenerVideojuegos(cantVideojuegos);
                cout << "Hay " << cantVideojuegos << " videojuegos registrados en el sistema." << endl << endl;
                TipoJuego gen;
                string gen_str;
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
                    cout << "   Total horas de juego: " << arrayVideojuegos[i]->getTotalHorasDeJuego() << endl;
                    cout << endl;
                    delete arrayVideojuegos[i]; // Se borra el DtVideojuego 'i'.
                }
                delete[] arrayVideojuegos;
                break;
            }
            /* Obtener Partidas */
            case 5: {
                string videojuego;
                int cantPartidas;
                cout << "Videojuego del cual desea obtener sus partidas: ";
                getline(cin, videojuego);
                try {
                    DtPartida** arrayPartidas = sys->obtenerPartidas(videojuego, cantPartidas);
                    cout << "El videojuego " << videojuego << " tiene " << cantPartidas << " partidas registradas en el sistema." << endl;
                    DtPartidaIndividual* ptrIndividual;
                    DtPartidaMultijugador* ptrMulti;
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
                }
                catch (invalid_argument &e) {
                    cout << e.what() << endl << endl;
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
                    DtPartida* datos;
                    float duracion;
                    int tipoPartida;
                    DtPartidaIndividual* ptrIndividual;
                    DtPartidaMultijugador* ptrMulti;
                    cout << "Nickname: ";
                    getline(cin, nickname);
                    cout << "Videojuego: ";
                    getline(cin, videojuego);
                    // Miguel: correccion de time.
                    cout << "Ingrese la fecha de la partida dd/mm/yyyy hh:mm ." << endl;
                    cout << "Si desea iniciar la partida con la fecha actual del sistema escriba 'ahora'." << endl << "Fecha: ";
                    string date_input;
                    //cin >> date_input;
                    getline(cin,date_input);
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
                    else
                        sscanf(date_input.c_str(),"%d/%d/%d %d:%d",&d,&m,&y,&h,&min);
                    DtFechaHora fechaSistema(d,m,y,h,min); // fechaSistema(dia, mes, anio, hora, min).
                    cout << "Duracion: ";
                    while (true) {
                        // Correccion del error del buffer de entrada para float. (Error de loop infinito).
                        if (!(cin >> duracion)) {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                            cout << "Porfavor, ingrese una duracion valida: ";
                        }
                        else 
                            break;
                    }
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << endl;
                    cout << "Tipo de partida:" << endl;
                    cout << " 1.Individual" << endl;
                    cout << " 2.Multijugador" << endl << endl;
                    cout << "Seleccione una opcion: ";
                    // Correccion del error del buffer de entrada para int. (Error de loop infinito).
                    while (true) {
                        if (!(cin >> tipoPartida)) {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            tipoPartida = 0; // Hacemos saltar el error del switch de tipoPartida.
                        }
                        if (!((tipoPartida == 1) || (tipoPartida == 2))) {
                            cout << "Porfavor, ingrese una opcion valida: ";
                        }
                        else
                            break;                            
                    }
                    cout << endl;
                    switch(tipoPartida) {
                        case 1: { 
                            /* Individual */
                            bool cpa;
                            cout << "Es continuacion de una partida anterior (1.Si/0.No): ";
                            cin >> cpa;
                            ptrIndividual = new DtPartidaIndividual(cpa,fechaSistema,duracion);
                            sys->iniciarPartida(nickname, videojuego, ptrIndividual);
                            cout << "Se registro la Partida Individual al sistema." << endl;
                            delete ptrIndividual; // Hay que borrarlo porque luego este Dt queda colgado. Solo borra el puntero (no lo que contiene).
                            break;
                        }
                        case 2: { 
                            /* Multijugador */
                            bool tev;
                            cout << "Es transmitida en vivo (1.Si/0.No): ";
                            cin >> tev;
                            int cantJugadoresUnidos;
                            cout << "Cantidad de jugadores unidos: ";
                            while (true) {
                                // Correccion del error del buffer de entrada para int. (Error de loop infinito).
                                if (!(cin >> cantJugadoresUnidos)) {
                                    cin.clear();
                                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                                    cout << "Porfavor, ingrese una cantidad valida: ";
                                }
                                else
                                    break;
                            }
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            string *nicknameJugadoresUnidos;
                            nicknameJugadoresUnidos = new string[cantJugadoresUnidos];
                            cout << "Ingrese el nickname de los jugadores unidos" << endl;
                            for (int i = 0; i < cantJugadoresUnidos; i++) {
                                cout << "Jugador " << i+1 << ":";
                                getline(cin, nicknameJugadoresUnidos[i]);
                            }
                            ptrMulti = new DtPartidaMultijugador(tev,nicknameJugadoresUnidos,cantJugadoresUnidos,fechaSistema,duracion);
                            sys->iniciarPartida(nickname, videojuego, ptrMulti);
                            cout << "Se registro la Partida Multijugador al sistema." << endl;
                            delete ptrMulti; // Hay que borrarlo porque luego este Dt queda colgado. Solo borra el puntero (no lo que contiene).
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
                    cout << e.what() << endl << endl;
                    break;
                }
            }
            /* Salir */
            case 7: 
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