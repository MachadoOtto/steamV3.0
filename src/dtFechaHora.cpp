/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Integrantes:
 *      Alexis Baladon (5.574.612-4) - alexis.baladon@fing.edu.uy
 *      Guillermo Toyos (5.139.879-9) - guillermo.toyos@fing.edu.uy
 *      Jorge Machado (4.876.616-9) - jorge.machado.ottonelli@fing.edu.uy
 *      Juan Jose Mangado (5.535.227-0) - juan.mangado@fing.edu.uy
 *      Mathias Ramilo (5.665.788-5) - mathias.ramilo@fing.edu.uy
 */

#include <../include/dtFechaHora.h>

#include <ctime>

DtFechaHora::DtFechaHora() {
    time_t now = time(0);
	tm* time = localtime(&now);
	dia = time->tm_mday;
	mes = time->tm_mon + 1; // tm_mon devuelve el mes donde enero es igual a 0 (por lo tanto se suma uno).
	anio = time->tm_year + 1900; // tm_year devuelve los anios despues de 1900 (por lo tanto hay que sumarlos).
    hora = time->tm_hour;
	min = time->tm_min;
    //segundo = time->tm_min;
}

DtFechaHora::DtFechaHora(int a, int m, int d, int hh, int mm) {
    if( (d < 1 || d > 31) || (m < 1 || m > 12) || (a < 1900) ) {
	    throw std::invalid_argument("La fecha indicada no es valida");
    }
    dia = d;
    mes = m;
    anio = a;
    hora = hh;
    min = mm;
}

int DtFechaHora::getAnio() { return anio; }

int DtFechaHora::getMes() { return mes; }

int DtFechaHora::getDia() { return dia; }

int DtFechaHora::getHora() { return hora; }

int DtFechaHora::getMinuto() { return min; }

//int DtFechaHora::getSegundo() { return segundo; }

float DtFechaHora::diffHoras(DtFechaHora fFinal) {
    int min1, min2 = 0;
    min1 = min + (hora + (dia + (mes + (anio) * 12) * 31) * 24) * 60;
    min2 = fFinal.min + (fFinal.hora + (fFinal.dia + (fFinal.mes + (fFinal.anio) * 12) * 31) * 24) * 60;
    return ((min2 - min1) / 60);
}

bool operator<(const DtFechaHora dt1, const DtFechaHora dt2) {
    int min1, min2 = 0;
    min1 = dt1.min + (dt1.hora + (dt1.dia + (dt1.mes + (dt1.anio) * 12) * 31) * 24) * 60;
    min2 = dt2.min + (dt2.hora + (dt2.dia + (dt2.mes + (dt2.anio) * 12) * 31) * 24) * 60;
    return (min1 < min2);
}

string DtFechaHora::getString() {
    string texto = "";
    texto = texto + std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(anio) + " - ";
    if (hora < 10)
        texto = texto + "0";
    texto = texto + std::to_string(hora) + ":";
    if (min < 10)
        texto = texto + "0";
    texto = texto + std::to_string(min);
    return texto;
}

ostream& operator<<(ostream& o, DtFechaHora d) {
    o << d.getDia() << "/" << d.getMes() << "/" << d.getAnio() << " - ";
    if (d.getHora() < 10)
        o << "0";
    o << d.getHora() << ":";
    if (d.getMinuto() < 10)
        o << "0";
    o << d.getMinuto();
    //if (d.getSegundo() < 10)
    //    o << "0";
    //o << d.getSegundo();
    return o;
}