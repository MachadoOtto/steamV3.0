/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Integrantes:
 *      Alexis Baladon (5.574.612-4) - alexis.baladon@fing.edu.uy
 *      Guillermo Toyos (5.139.879-9) - guillermo.toyos@fing.edu.uy
 *      Jorge Machado (4.876.616-9) - jorge.machado.ottonelli@fing.edu.uy
 *      Juan Jose Mangado (5.535.227-0) - juan.mangado@fing.edu.uy
 *      Mathias Ramilo (5.665.788-5) - mathias.ramilo@fing.edu.uy
 */

#ifndef DT_FECHAHORA
#define DT_FECHAHORA

#include <string>

using std::string;

class DtFechaHora {
private:
    int anio, mes, dia, hora, min, segundo;
public:
    DtFechaHora(int, int, int, int, int, int);
    int getAnio();
    int getMes();
    int getDia();
    int getHora();
    int getMin();
    int getSegundo();
    string getFechaHora(); // Retorna un string con el formato correcto para la fecha.
};

#endif