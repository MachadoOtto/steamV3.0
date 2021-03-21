#include <iostream>

void Sistema::agregarJugador(std::string nickname, int edad, std::string contraseña) {
    if(estaJugadorSistema(nickname)) {
        throw std::invalid_argument("Ya hay un jugador con ese nombre");
    }
    else {
        jugadores.(nickname,edad,contraseña); //FALTA AGREGAR A LA LISTA
    }
}