#include <iostream>

void Sistema::agregarJugador(std::string nickname, int edad, std::string contraseña) {
    if(estaJugadorSistema(nickname)) { //supongo que funciona cuando jugadores es NULL
            throw std::invalid_argument("Ya hay un jugador con ese nombre");
    }
    else {
        Jugador * nuevoJugador = new Jugador(nickname,edad,contraseña);
        if(jugadores == NULL) jugadores = nuevoJugador;
        else jugadores.add(nuevoJugador);
    }
}