/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Integrantes:
 *      Alexis Baladon (5.574.612-4) - alexis.baladon@fing.edu.uy
 *      Guillermo Toyos (5.139.879-9) - guillermo.toyos@fing.edu.uy
 *      Jorge Machado (4.876.616-9) - jorge.machado.ottonelli@fing.edu.uy
 *      Juan Jose Mangado (5.535.227-0) - juan.mangado@fing.edu.uy
 *      Mathias Ramilo (5.665.788-5) - mathias.ramilo@fing.edu.uy
 */

#include <../include/finalizarPartida.h>

#include <iostream>
#include <limits>
#include <string>
#include <set>

using std::cout;
using std::cin;
using std::string;
using std::set;

FinalizarPartida* FinalizarPartida::instancia = nullptr;

FinalizarPartida::FinalizarPartida() { }

static FinalizarPartida* FinalizarPartida::getInstance() {
    if (instancia == nullptr)
        instancia = new FinalizarPartida();
    return instancia;
}

void iniciar() {
    LaFabrica* factory = LaFabrica::getInstance();
    IIFPController* interface = factory->getIFPartidasInterface();
    set<DtPartida>* partidasActivas = interface->obtenerPartidasActivas();
    cout << "Finalizar Partida \n \n";
    cout << "Partidas actualmente activas: \n";
    for (set<DtPartida>::iterator it = partidasActivas->begin(); it != partidasActivas->end(); ++it) {
        cout << it << "\n";
    }
    cout << "Ingrese la Id de la Partida a finalizar: \n";
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
            set<DtPartida>::iterator it = partidasActivas->begin();
            while (true) {
                if (it.getIdentificador() == id) {
                    exId = true;
                    break;
                }
                if (it == partidasActivas->end()) {
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
    delete partidasActivas;
    interface->confirmarFinalizarPartida(id);
    cout << "Se ha finalizado la Partida (ID: " << id << ") correctamente."
    // CLEAR CACHE???
}

FinalizarPartida::~FinalizarPartida() { }