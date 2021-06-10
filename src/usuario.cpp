/* Laboratorio Programacion IV - INCO/FING/UDELAR 
 * Integrantes:
 *      Alexis Baladon (5.574.612-4) - alexis.baladon@fing.edu.uy
 *      Guillermo Toyos (5.139.879-9) - guillermo.toyos@fing.edu.uy
 *      Jorge Machado (4.876.616-9) - jorge.machado.ottonelli@fing.edu.uy
 *      Juan Jose Mangado (5.535.227-0) - juan.mangado@fing.edu.uy
 *      Mathias Ramilo (5.665.788-5) - mathias.ramilo@fing.edu.uy
 */

#include "../include/usuario.h"
#include "../include/dtUsuario.h"

#include <string>

Usuario::Usuario(DtUsuario du) {
    email = du.getEmail();
    contrasenia = du.getContrasenia();
}
Usuario::Usuario(string nam, string pass){
    email = nam;
    contrasenia = pass;
}
std::string Usuario::getEmail(){
    return email;
}
std::string Usuario::getContrasenia(){
    return contrasenia;
}
