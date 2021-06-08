/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Integrantes:
 *      Alexis Baladon (5.574.612-4) - alexis.baladon@fing.edu.uy
 *      Guillermo Toyos (5.139.879-9) - guillermo.toyos@fing.edu.uy
 *      Jorge Machado (4.876.616-9) - jorge.machado.ottonelli@fing.edu.uy
 *      Juan Jose Mangado (5.535.227-0) - juan.mangado@fing.edu.uy
 *      Mathias Ramilo (5.665.788-5) - mathias.ramilo@fing.edu.uy
 */

#include <../include/dtEstadistica.h>

using std::string;

DtEstadistica::DtEstadistica(string nom, string des, float vit) {
    vitalicia = vit;
    nombre = nom;
    descripcion = des;
}

float DtEstadistica::getValor() { return valor; }

float DtEstadistica::getNombre() { return nombre; }

float DtEstadistica::getDescripcion() { return descripcion; }

//corregir luego :^)
ostream& operator<<(ostream& o, DtEstadistica p) {
    o << "Lista de precios: en desarrollo...\n";
    return o;
}
