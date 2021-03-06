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
    valor = vit;
    nombre = nom;
    descripcion = des;
}

float DtEstadistica::getValor() const{
    return valor; 
}

string DtEstadistica::getNombre() const{ 
    return nombre;
}

string DtEstadistica::getDescripcion() const{
    return descripcion;
}

//corregir luego :^)
ostream& operator<<(ostream& o, DtEstadistica p) {
    o << "Lista de precios: en desarrollo...\n";
    return o;
}

bool operator<(const DtEstadistica v1,const DtEstadistica v2){
    return (v1.nombre < v2.nombre);
}


