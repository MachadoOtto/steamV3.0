#include <iostream>

void Sistema::agregarJugador(std::string nickname, int edad, std::string contraseña) {
    if(estaJugadorSistema(nickname)) {
        throw std::invalid_argument("Ya hay un jugador con ese nombre");
    }
    else {
        Jugador * nuevoJugador = new Jugador(nickname,edad,contraseña);
        jugadores.add(nuevoJugador);
    }
}