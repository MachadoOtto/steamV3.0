/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class implementation 
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "../include/dtDesarrollador.h"
using std::string;

DtDesarrollador::DtDesarrollador(string emp,string email, string cont):
    DtUsuario(email,cont){
    empresa = emp;
}

string DtDesarrollador::getEmpresa(){
    return empresa;
}


    
