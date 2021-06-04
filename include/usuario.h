#ifndef USUARIO
#define USUARIO

#include "dtUsuario.h"

#include <string>

class Usuario {
    private:
        std::string email;
        std::string contrasenia;
    public:
        Usuario(DtUsuario);
};

#endif
