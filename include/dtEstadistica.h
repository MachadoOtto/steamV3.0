/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Integrantes:
 *      Alexis Baladon (5.574.612-4) - alexis.baladon@fing.edu.uy
 *      Guillermo Toyos (5.139.879-9) - guillermo.toyos@fing.edu.uy
 *      Jorge Machado (4.876.616-9) - jorge.machado.ottonelli@fing.edu.uy
 *      Juan Jose Mangado (5.535.227-0) - juan.mangado@fing.edu.uy
 *      Mathias Ramilo (5.665.788-5) - mathias.ramilo@fing.edu.uy
 */

#ifndef DT_ESTADISTICA
#define DT_ESTADISTICA

#include <iostream>
#include <string>

using std::ostream;
using std::string;

class DtEstadistica{
private:
    string nombre,descripcion;
    float valor;
public:
    DtEstadistica(string,string, float);
    float getValor();
    string getDescripcion();
    string getNombre();
};

// Sobrecarga del operador de flujo.
ostream& operator<<(ostream&, DtEstadistica);

bool operator<(const DtEstadistica,const DtEstadistica);
#endif
