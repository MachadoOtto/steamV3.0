#include "../include/usuario.h"
#include "../include/dtUsuario.h"

#include <string>

Usuario::Usuario(DtUsuario du) {
    email = du.email();
    contrasenia = du.contrasenia();
}