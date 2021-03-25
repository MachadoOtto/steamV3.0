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
//    DtFechaHora(int=-1, int=-1, int=-1, int=-1, int=-1); //Prueba: Generar un constructor sin parametros!?
    DtFechaHora(int, int, int, int, int); //Prueba: Generar un constructor sin parametros!?
    DtFechaHora(const DtFechaHora &);
    int getDia();
    int getMes();
    int getAnio();
    int getHora();
    int getMinuto();
    
    DtFechaHora & operator=(DtFechaHora&);
};
#endif

