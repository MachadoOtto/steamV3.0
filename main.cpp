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

int main() {
    int controlVar;
    while (controlVar) {
        cout << "1. Agregar Jugador" endl;
        cout << "2. Agregar Videojuego" endl;
        cout << "3. Obtener Jugadores" endl;
        cout << "4. Obtener Videojuegos" endl;
        cout << "5. Obtener Partidas" endl;
        cout << "6. Iniciar Partida" endl;
        cout << "7. Salir" endl;
        cout << "Ingrese una opcion: "
        cin >> controlVar;

        switch (controlVar) {
            case 1: //Agregar Jugador
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
                    agregarJugador(nickname, edad, password);
                    cout << "Se ha registrado a " << nickname << " en el sistema." endl;
                }
                catch (std::invalid_argument) {
                }
            break;

            case 2: //Agregar Videojuego
                string nombre;
                TipoJuego genero;

                cout << "Nombre del videojuego: ";
                cin >> nombre;
                cout << "Genero (Accion/Aventura/Deporte/Otro): "
                cin >> genero;

                try {
                    agregarVideojuego(nombre, genero);
                    cout << "Se ha registrado " << nombre << " En el sistema." endl;
                }
                catch (std::invalid_argument) {
                }
            break;

            case 3: //Obtener Jugadores
                int cantJugadores;
                DtJugador** arrayJugadores = obtenerJugadores(cantJugadores);
                for (int i = 0; i < cantJugadores; i++) {
                    cout << i << ". Nickname: " << arrayJugadores[i]
                    cout << "   Edad: " << arrayJugadores[i].edad;
                }
            break;

            case 4: //Obtener Videojuegos

            break;

            case 5: //Obtener Partidas

            break;

            case 6: //Iniciar Partida

            break;

            case 7: //Salir

            break;

            default:
                cout << "La opcion ingresada no es valida, ingrese otra porfavor." endl;
        }
    }
    return 0;
}
