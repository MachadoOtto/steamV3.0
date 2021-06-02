/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Integrantes:
 *      Alexis Baladon (5.574.612-4) - alexis.baladon@fing.edu.uy
 *      Guillermo Toyos (5.139.879-9) - guillermo.toyos@fing.edu.uy
 *      Jorge Machado (4.876.616-9) - jorge.machado.ottonelli@fing.edu.uy
 *      Juan Jose Mangado (5.535.227-0) - juan.mangado@fing.edu.uy
 *      Mathias Ramilo (5.665.788-5) - mathias.ramilo@fing.edu.uy
 */

#include <../include/dtFechaHora.h>

DtFechaHora::DtFechaHora(int a, int m, int d, int hh, int mm, int ss) {
    anio = a;
    mes = m;
    dia = d;
    hora = hh;
    min = mm;
    segundo = ss;
}

int DtFechaHora::getAnio() { return anio; }

int DtFechaHora::getMes() { return mes; }

int DtFechaHora::getDia() { return dia; }

int DtFechaHora::getHora() { return hora; }

int DtFechaHora::getMin() { return min; }

int DtFechaHora::getSegundo() { return segundo; }

// Retorna un string con el formato correcto para la fecha.
string DtFechaHora::getFechaHora() {
    string fecha;
    fecha = "%d" + '/' + "%d" + '/' + "%d" + " " (dia, mes, anio);
    if (hora < 10)
        fecha = fecha + "0%d" (hora);
    else
        fecha = fecha + "%d" (hora);
    if (min < 10)
        fecha = fecha + "0%d" (min);
    else
        fecha = fecha + "%d" (min);
    if (segundo < 10)
        fecha = fecha + "0%d" (segundo);
    else
        fecha = fecha + "%d" (segundo);
}