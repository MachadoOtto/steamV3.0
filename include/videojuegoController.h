/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef VideojuegoController
#define VideojuegoController

#include <string>
#include <vector>

#include "handlerCatalogo.h"
#include "handlerEstadistica.h"
#include "handlerCategoria.h"
#include "handlerUsuario.h"
#include "IVideojuegoController"

#include "usuario.h"
#include "jugador.h"
#include "desarrollador.h"
#include "videojuego.h"
#include "categoria.h"

using std::vector;
using std::string;

class DtVideojuego;
class DtCategoria;
class DtEstadistica;
enum class TipoSuscripcion;
enum class TipoPago;

class VideojuegoController: public IVideojuegoController{
private:
    DtVideojuego * datos;
    TipoPago tPago;
    TipoSuscripcion tSus; //SUS!?
    Usuario * loggedUser; //Player OR Dev. depening on usecase under execution.
    Videojuego * videoCache;
    vector<Categoria*> * categoriaCache;

    VideojuegoController();
public:
    virtual vector<string> *obtenerNombreVideojuegosDesarrollados();
    virtual vector<string> *obtenerNombreVideojuegosInactivos();
    virtual vector<vector<DtVideojuego>> *obtenerSuscripcionesVideojuegos();
    virtual vector<DtCategoria> *obtenerCategoriasGenero();
    virtual vector<DtCategoria> *obtenerCategoriasPlataforma();
    virtual vector<DtCategoria> *obtenerCategoriasOtro();
    virtual vector<DtEstadistica> *obtenerEstadisticas(string);
    virtual void ingresarDatosVideojuego(DtVideojuego);
    virtual void ingresarSuscripcion(TipoSuscripcion,TipoPago);
    virtual void seleccionarVideojuego(string);
    virtual void seleccionarGenero(string);
    virtual void seleccionarPlataforma(string);
    virtual void seleccionarCategoriaOtro(string);
    virtual void confirmarPublicacion();
    virtual void confirmarSuscripcion();
    virtual void confirmarEliminarVideojuego();
    virtual void cancelarSuscripcion();
    virtual void clearCache();
    
    void setLoggedUser(Usuario *);
    //setDatos // Equivalente a ingresarDatosvideojuego  
    
    static VideojuegoController * getInstance();
    ~videojuegoController();
};

#endif
