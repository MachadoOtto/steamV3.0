/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class implementation 
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "../include/dtJugador.h"
using std::string;

DtJugador::DtJugador(string nick,string desc,string email, string cont):
    DtUsuario(email,cont){
    nickname = nick;
    descripcion = desc;
}

string DtJugador::getNickname(){
    return nickname;
}


string DtJugador::getDescripcion(){
    return descripcion;	
}

    
