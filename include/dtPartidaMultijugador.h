/* Laboratorio Programacion IV - INCO/FING/UDELAR 
 * Integrantes:
 *      Alexis Baladon (5.574.612-4) - alexis.baladon@fing.edu.uy
 *      Guillermo Toyos (5.139.879-9) - guillermo.toyos@fing.edu.uy
 *      Jorge Machado (4.876.616-9) - jorge.machado.ottonelli@fing.edu.uy
 *      Juan Jose Mangado (5.535.227-0) - juan.mangado@fing.edu.uy
 *      Mathias Ramilo (5.665.788-5) - mathias.ramilo@fing.edu.uy
 */

#ifndef DTPARTIDAMULTIJUGADOR
#define DTPARTIDAMULTIJUGADOR
#include <string>
#include <set>
#include "dtPartida.h"
#include "dtFechaHora.h"

using std::set;
using std::string;

class DtPartidaMultijugador: public DtPartida {
    private:
        bool transmitidaEnVivo;
    public:
        DtPartidaMultijugador(int,DtFechaHora,float,bool,bool);
	    bool getTransmitidaEnVivo();
};

std::ostream& operator<<(std::ostream&, DtPartidaMultijugador);

#endif
