/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Integrantes:
 *      Alexis Baladon (5.574.612-4) - alexis.baladon@fing.edu.uy
 *      Guillermo Toyos (5.139.879-9) - guillermo.toyos@fing.edu.uy
 *      Jorge Machado (4.876.616-9) - jorge.machado.ottonelli@fing.edu.uy
 *      Juan Jose Mangado (5.535.227-0) - juan.mangado@fing.edu.uy
 *      Mathias Ramilo (5.665.788-5) - mathias.ramilo@fing.edu.uy
 */

#include <../include/dtPrecios.h>

using std::string;

DtPrecios::DtPrecios(float men, float tri, float an, float vit) {
    mensual = men;
    trimestral = tri;
    anual = an;
    vitalicia = vit;
}

float DtPrecios::getMensual() { return mensual; }

float DtPrecios::getTrimestral() { return trimestral; }

float DtPrecios::getAnual() { return anual; }

float DtPrecios::getVitalicia() { return vitalicia; }

ostream& operator<<(ostream& o, DtPrecios p) {
    o << "Lista de precios: \n" << "Mensual: " << p.getMensual() << "\n" << "Trimestral: " << p.getTrimestral()
        << "\n" << "Anual: " << p.getAnual() << "\n" << "Vitalicia: " << p.getVitalicia() << "\n";
    return o;
}