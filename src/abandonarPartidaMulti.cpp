/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Integrantes:
 *      Alexis Baladon (5.574.612-4) - alexis.baladon@fing.edu.uy
 *      Guillermo Toyos (5.139.879-9) - guillermo.toyos@fing.edu.uy
 *      Jorge Machado (4.876.616-9) - jorge.machado.ottonelli@fing.edu.uy
 *      Juan Jose Mangado (5.535.227-0) - juan.mangado@fing.edu.uy
 *      Mathias Ramilo (5.665.788-5) - mathias.ramilo@fing.edu.uy
 */

#include <../include/abandonarPartidaMulti.h>

#include <iostream>
#include <limits>
#include <string>
#include <set>

using std::cout;
using std::cin;
using std::string;
using std::set;

AbandonarPartidaMulti* AbandonarPartidaMulti::instancia = nullptr;

AbandonarPartidaMulti::AbandonarPartidaMulti() { }

static AbandonarPartidaMulti* AbandonarPartidaMulti::getInstance() {
    if (instancia == nullptr)
        instancia = new AbandonarPartidaMulti();
    return instancia;
}

void iniciar() {
    LaFabrica* factory = LaFabrica::getInstance();
    IIFPController* interface = factory->getIFPartidasInterface();
    set<DtPartidaMultijugador>* multiActivas = interface->obtenerPartidasMultiActivas(); // IMPLEMENTAR EN EL CONTROLLER!!!!
    cout << "Abandonar Partida Multijugador \n \n";
    cout << "Partidas multijugador activas a las que se unio: \n";
    for (set<DtPartidaMultijugador>::iterator it = multiActivas->begin(); it != multiActivas->end(); ++it) {
        cout << it << "\n";
    }
    cout << "Ingrese la Id de la Partida Multijugador a abandonar: \n";
    int id;
    while (true) {
        if (!(cin >> id)) {
		    cin.clear(); 
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Porfavor, ingrese un Id correcto: ";
        } else {
            cin.clear(); 
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            bool exId = false;
            set<DtPartidaMultijugador>::iterator it = multiActivas->begin();
            while (true) {
                if (it.getIdentificador() == id) {
                    exId = true;
                    break;
                }
                if (it == multiActivas->end()) {
                    break;
                }
                ++it;
            }
            if (!exId) {
                cout << "Porfavor, ingrese un Id correcto: ";
            } else {
                break;
            }
        }
    }
    delete multiActivas;
    interface->confirmarAbandonarPartida(id); // IMPLEMENTAR EN EL CONTROLLER!!!
    cout << "Se ha abandonado la Partida Multijugador (ID: " << id << ") correctamente."
    // CLEAR CACHE???
}

AbandonarPartidaMulti::~AbandonarPartidaMulti() { }