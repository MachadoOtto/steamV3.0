/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Integrantes:
 *      Alexis Baladon (5.574.612-4) - alexis.baladon@fing.edu.uy
 *      Guillermo Toyos (5.139.879-9) - guillermo.toyos@fing.edu.uy
 *      Jorge Machado (4.876.616-9) - jorge.machado.ottonelli@fing.edu.uy
 *      Juan Jose Mangado (5.535.227-0) - juan.mangado@fing.edu.uy
 *      Mathias Ramilo (5.665.788-5) - mathias.ramilo@fing.edu.uy
 */

#include <../include/iniciarPartida.h>

#include <iostream>
#include <limits>
#include <string>
#include <set>

using std::cout;
using std::cin;
using std::string;
using std::set;

IniciarPartida* IniciarPartida::instancia = nullptr;

IniciarPartida::IniciarPartida() { }

static IniciarPartida* IniciarPartida::getInstance() {
    if (instancia == nullptr)
        instancia = new IniciarPartida();
    return instancia;
}

void iniciar() {
    int idAnterior = -1;
    bool enVivo;
    set<string>* jIngresados = new set<string>;
    LaFabrica* factory = LaFabrica::getInstance();
    IIFPController* interface = factory->getIFPartidasInterface();
    set<string>* vjActivos = interface->obtenerVideojuegosActivos();
    cout << "Iniciar Partida \n \n";
    cout << "Videojuegos con suscripcion activa: \n";
    for (set<string>::iterator it = vjActivos->begin(); it != vjActivos->end(); ++it) {
        cout << it << "\n";
    }
    cout << "Ingrese el nombre del Videojuego al que quiera iniciar su Partida: ";
    string nombreVj;
    while (true) {
        std::getline(cin, nombreVj);
        if (vjActivos->find(nombreVj) == vjActivos->end()) {
            cout << "Porfavor, ingrese un Videojuego valido: ";
        } else {
            break;
        }
    }
    delete vjActivos;
    interface->seleccionarVideojuego(vjActivos);
    cout << "Seleccione un tipo de Partida a iniciar: (1. Individual, 2. Multijugador) \n";
    string tipoPartida;
    while (true) {
        std::getline(cin, tipoPartida);
        if ((tipoPartida == "1") || (tipoPartida == "2") || (tipoPartida == "Individual") || (tipoPartida == "Multijugador") 
                || (tipoPartida == "individual") || (tipoPartida == "multijugador")) {
            break;
        } else {
            cout << "Porfavor, ingrese una opcion valida: ";
        }
    }
    if ((tipoPartida == "1") || (tipoPartida == "Individual") || (tipoPartida == "individual")) {
        tipoPartida = "Individual";
        cout << "Su Partida es continuacion de una Partida anterior? (1. Si, 2. No) \n";
        string esCont;
        while (true) {
            std::getline(cin, esCont);
            if ((esCont == "1") || (esCont == "Si") || (esCont == "si") || (esCont == "2") || (esCont == "No") || (esCont == "no")) {
                break;
            } else {
                cout << "Porfavor, ingrese una opcion valida: ";
            }
        }
        if ((esCont == "1") || (esCont == "Si") || (esCont == "si")) {
            set<DtPartidaIndividual>* pAnteriores = interface->obtenerHistorialPartidas();
            cout << "Partidas anteriores: \n";
            for (set<DtPartidaIndividual>::iterator it = pAnteriores->begin(); it != pAnteriores->end(); ++it) {
                cout << it;
            }
            cout << "Ingrese el Id de la partida a continuar: \n";
            while (true) {
                if (!(cin >> idAnterior)) {
			        cin.clear(); 
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Porfavor, ingrese un Id correcto: ";
                } else {
                    cin.clear(); 
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    bool exId = false;
                    set<DtPartidaIndividual>::iterator it = pAnteriores->begin();
                    while (true) {
                        if (it.getIdentificador() == idAnterior) {
                            exId = true;
                            break;
                        }
                        if (it == pAnteriores->end()) {
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
            delete pAnteriores;
            interface->seleccionarContinuacionPartida(idAnterior);
        }
    } else {
        tipoPartida = "Multijugador";
        cout << "Su Partida se transmitira en vivo? (1. Si, 2. No) \n";
        string tEnVivo;
        while (true) {
            std::getline(cin, tEnVivo);
            if ((tEnVivo == "1") || (tEnVivo == "Si") || (tEnVivo == "si") || (tEnVivo == "2") || (tEnVivo == "No") || (tEnVivo == "no")) {
                if ((tEnVivo == "1") || (tEnVivo == "Si") || (tEnVivo == "si")) {
                    enVivo = true;
                } else {
                    enVivo = false;
                }
                break;
            } else {
                cout << "Porfavor, ingrese una opcion valida: ";
            }
        }
        interface->partidaEnVivo(enVivo);
        set<string>* jugadoresSus = interface->obtenerJugadoresSubscriptos();
        cout << "Ingrese los nicknames de los jugadores a agregar a la partida. Para finalizar ingrese '0' : \n";
        string nick;
        while (true) {
            std::getline(cin, nick);
            if (nick != "0") {
                if (jugadoresSus->find(nick) == jugadoresSus->end()) {
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
            cout << "    " << it << "\n";
        }
    }
    delete jIngresados;
    cout << "Confirma el Alta de la Partida? (1. Si, 2. No)";
    string confirmar;
    while (true) {
        std::getline(cin, confirmar);
        if ((confirmar == "1") || (confirmar == "Si") || (confirmar == "si") || (confirmar == "2") 
                || (confirmar == "No") || (confirmar == "no")) {
            break;
        } else {
            cout << "Porfavor, ingrese una opcion valida: ";
        }
    }
    if ((confirmar == "1") || (confirmar == "Si") || (confirmar == "si")) {
        interface->confirmarPartida();
    }
    // CLEAR CACHE???
}

IniciarPartida::~IniciarPartida() { }
