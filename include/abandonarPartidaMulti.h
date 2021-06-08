/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Integrantes:
 *      Alexis Baladon (5.574.612-4) - alexis.baladon@fing.edu.uy
 *      Guillermo Toyos (5.139.879-9) - guillermo.toyos@fing.edu.uy
 *      Jorge Machado (4.876.616-9) - jorge.machado.ottonelli@fing.edu.uy
 *      Juan Jose Mangado (5.535.227-0) - juan.mangado@fing.edu.uy
 *      Mathias Ramilo (5.665.788-5) - mathias.ramilo@fing.edu.uy
 */

#ifndef ABANDONAR_PARTIDA_MULTI
#define ABANDONAR_PARTIDA_MULTI

#include "laFabrica.h"

class IIFPController;
class DtPartidaMultijugador;

class AbandonarPartidaMulti {
private:
    static AbandonarPartidaMulti* instancia;
    AbandonarPartidaMulti();
public:
    static AbandonarPartidaMulti* getInstance();
    void iniciar();
    ~AbandonarPartidaMulti();
};

#endif