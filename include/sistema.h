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
    ListaJugador * jugadores;
    ListaVideoJuego * videojuegos;
    ListaPartida * partidas;
    int cantidadJugadores;
    int cantidadVideojuegos;
    int cantida:wdPartidas;
public:
    Sistema();
    
    /*Funcionalidades solicitadas*/
    void agregarJugador(string,int,string);
    void agregarVideojuego(string,TipoJuego);
    DtJugador** obtenerJugadores(int&);
    DtVideojuego** obtenerVidejuegos(int&);
    DtPartida** obtenerPartidas(string,int&);
    void iniciarPartida(string,string,DtPartida*);

    /*Auxiliares*/
    Videjuego * findVideojuego(std::string nombre);
    Jugador * findJugador(std::string nombre);

};
#endif

