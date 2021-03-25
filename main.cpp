/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Implementacion de main
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "include/Sistema.h"
#include "include/Videojuego.h"
#include "include/Partida.h"
#include "include/Jugador.h"
#include "include/PartidaIndividual.h"
#include "include/PartidaMultijugador.h"
#include "include/DtVideouego.h"
#include "include/DtPartida.h"
#include "include/DtJugador.h"
#include "include/DtFechaHora.h"
#include "include/DtPartidaIndividual.h"
#include "include/DtPartidaMultijugador.h"

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

int main() {
    int controlVar;
    while (controlVar != 7) {
        cout << "--- MENU---" << endl << endl;
        cout << "Seleccione una opcion" endl;
        cout << " 1. Agregar Jugador" endl;
        cout << " 2. Agregar Videojuego" endl;
        cout << " 3. Obtener Jugadores" endl;
        cout << " 4. Obtener Videojuegos" endl;
        cout << " 5. Obtener Partidas" endl;
        cout << " 6. Iniciar Partida" endl;
        cout << " 7. Salir" endl << endl;
        cout << "Ingrese una opcion: ";
        cin >> controlVar;
        cout << endl;

        switch (controlVar) {
            case 1: //Agregar Jugador
                Sistema sys();
                string nickname;
                int edad;
                string password;

                cout << "Nickname: ";
                cin >> nickname;
                cout << "Edad: ";
                cin >> edad;
                cout << "Password: ";
                cin >> password;

                try {
                    sys.agregarJugador(nickname, edad, password);
                    cout << "Se ha registrado a " << nickname << " en el sistema." endl;
                }
                catch (invalid_argument &e) {
                    cout << e.what() << endl;
                    break;
                }
            break;

            case 2: //Agregar Videojuego
                Sistema sys();
                string nombre;
                TipoJuego genero;

                cout << "Nombre del videojuego: ";
                cin >> nombre;
                cout << "Genero (Accion/Aventura/Deporte/Otro): "
                cin >> genero;

                try {
                    sys.agregarVideojuego(nombre, genero);
                    cout << "Se ha registrado el videojuego " << nombre << " en el sistema." endl;
                }
                catch (invalid_argument &e) {
                    cout << e.what() << endl;
                    break;
                }
            break;

            case 3: //Obtener Jugadores
                Sistema sys();
                int cantJugadores;
                DtJugador** arrayJugadores = sys.obtenerJugadores(cantJugadores);

                cout << "Hay " << cantJugadores << " jugadores registrados en el sistema." endl;
                cout << endl;
                for (int i = 0; i < cantJugadores; i++) {
                    cout << i+1 << ". Nickname: " << arrayJugadores[i]->getNickname() << endl;
                    cout << "   Edad: " << arrayJugadores[i]->getEdad() << endl;
                    cout << endl;
                } 
                delete[] arrayJugadores;
            break;

            case 4: //Obtener Videojuegos
                Sistema sys();
                int cantVideojuegos;
                DtVideojuego** arrayVideojuegos = sys.obtenerVideojuegos(cantVideojuegos);

                cout << "Hay " << cantVideojuegos << " videojuegos registrados en el sistema." endl;
                cout << endl;
                for (int i = 0; i < cantVideojuegos; i++) {
                    cout << i+1 << ". Titulo: " << arrayVideojuegos[i]->getTitulo() << endl;
                    cout << "   Genero: " << arrayVideojuegos[i]->getGenero() << endl;
                    cout << "   Total horas de juego: " << arrayVideojuegos[i]->getTotalHorasDeJuego() << endl;
                    cout << endl;
                }
                delete[] arrayVideojuegos;
            break;

            case 5: //Obtener Partidas
                Sistema sys();
                string videojuego;
                int cantPartidas;

                cout << "Videojuego del cual desea obtener sus partidas: ";
                cin >> videojuego;

                try {
                    DtPartida** arrayPartidas = sys.obtenerPartidas(videojuego, cantPartidas);
                    cout << "Hay " << cantPartidas << " partidas registradas en el sistema." endl;
                    DtPartidaIndividual* ptrIndividual;
                    DtPartidaMultijugador* ptrMulti;
                    for (int i = 0; i < cantPartidas; i++) {
                        ptrIndividual = dynamic_cast<DtPartidaIndividual*>(arrayPartidas[i]);
                        if (ptrIndividual == nullptr) { //Multijugador
                            ptrMulti = dynamic_cast<DtPartidaMultijugador*>(arrayPartidas[i]);
                            cout << i+1 << ". Fecha: " << ptrMulti->getFecha() << endl;
                            cout << "   Duracion: " << ptrMulti->getDuracion() << endl;
                            string tev = "NO";
                            if (ptrMulti->getTransmitidaEnVivo()) {
                                tev = "SI";
                            }
                            cout << "   Trasmtida en vivo: " << tev << endl;
                            cout << "   Jugadores unidos: " << ptrMulti->getCantidadJugadoresUnidos() << endl << endl;
                            for (int j = 0; j < ptrMulti->getCantidadJugadoresUnidos(); j++) {
                                cout << "    " << j+1 << ". " << ptrMulti->getNicknameJugadoresUnidos[j] << endl;
                            }
                        } else { //Individual
                            cout << i+1 << ". Fecha: " << ptrIndividual->getFecha() << endl;
                            cout << "   Duracion: " << ptrIndividual->getDuracion() << endl;
                            string cpa = "NO";
                            if (ptrIndividual->getContinuarPartidaAnterior()) {
                                cpa = "SI";
                            }
                            cout << "   Es continuacion de una partida anterior: " << cpa << endl;
                        }
                    }
                    delete[] arrayPartidas;
                }
                catch (invalid_argument &e) {
                    cout << e.what() << endl;
                    break;
                }
            break;

            case 6: //Iniciar Partida
                Sistema sys();
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

                time_t now = time(0);
                tm * time = localtime(&now);
                DtFechaHora fechaSistema(time->tm_year, time->tm_mon, time->tm_mday, time->tm_hour, time->tm_min);

                cout << "Duracion: ";
                cin >> duracion; 
                cout << endl;

                cout << "Tipo de partida:" << endl;
                cout << " 1.Individual" << endl;
                cout << " 2.Multijugador" << endl << endl;
                cout << "Seleccione una opcion: ";
                cin >> tipoPartida;
                cout << endl;

                switch(tipoPartida) {
                    case 1: //Individual
                        bool cpa;
                        cout << "Es continuacion de una partida anterior (1.Si/0.No): ";
                        cin >> cpa;
                    break;

                    case 2: //Multijugador
                        bool tev;
                        
                    break;

                    default:
                        cout << "La opcion ingresada no es valida, ingrese otra porfavor." << endl;
                }
                try {
                    sys.iniciarPartida(nickname, videojuego, datos);
                }
                catch (invalid_argument &e) {
                    cout << e.what() << endl;
                    break;
                }
            break;

            case 7: //Salir

            break;

            default:
                cout << "La opcion ingresada no es valida, ingrese otra porfavor." endl;
        }
    }
    return 0;
}
