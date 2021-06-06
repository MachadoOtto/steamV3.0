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
    // FALTA IMPLEMENTAR!!!
}

FinalizarPartida::~FinalizarPartida() { }