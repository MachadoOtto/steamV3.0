/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 0 - Modulo de clase
 * Autores (por nombre):
 * 	Alexis Ramilo
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef SISTEMA
#define SISTEMA
class Sistema{
private:
    ListaJugador Jugadores;
    ListaVideoJuego Videojuego;
    ListaPartida Partidas;
public:
    Sistema();

    void agregarJugador(string,int,string);
    void agregarVideojuego(string,TipoJuego);
    DtJugador** obtenerJugadores(int&);
    DtVideojuego** obtenerVidejuegos(int&);
    DtPartida** obtenerPartidas(string,int&);
    void iniciarPartida(string,string,DtPartida*);
};
#endif

