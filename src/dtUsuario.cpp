/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class implementation 
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "../include/dtUsuario.h"

DtUsuario::DtUsuario(string m,string cont){
    email = m;
    contrasenia = cont;
}

string DtUsuario::getEmail(){
    return email;
}

string DtUsuario::getContrasenia(){
    return contrasenia;
}

    
