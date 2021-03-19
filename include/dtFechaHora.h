/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Ramilo
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef DT_FECHAHORA
#define DT_FECHAHORA

class DtFechaHora {
private:
    int dia, mes, anio, hora, minuto;
public:
    DtFechaHora(int, int, int, int, int);
    int getDia();
    int getMes();
    int getAnio();
    int getHora();
    int getMinuto();
};
#endif

