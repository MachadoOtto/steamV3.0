/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef VideojueGoController
#define VideojueGoController

#include <string>
#include <vector>

#include "handlerCatalogo.h"
#include "handlerEstadistica.h"
#include "handlerCategoria.h"
#include "handlerUsuario.h"

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
    vector<string> *obtenerNombreVideojuegosDesarrollados();
    vector<string> *obtenerNombreVideojuegosInactivos();
    vector<vector<DtVideojuego>> *obtenerSuscripcionesVideojuegos();
    vector<DtCategoria> *obtenerCategoriasGenero();
    vector<DtCategoria> *obtenerCategoriasPlataforma();
    vector<DtCategoria> *obtenerCategoriasOtro();
    vector<DtEstadistica> *obtenerEstadisticas(string);
    void ingresarDatosVideojuego(DtVideojuego);
    void ingresarSuscripcion(TipoSuscripcion,TipoPago);
    void seleccionarVideojuego(string);
    void seleccionarGenero(string);
    void seleccionarPlataforma(string);
    void seleccionarCategoriaOtro(string);
    void confirmarPublicacion();
    void confirmarSuscripcion();
    void confirmarEliminarVideojuego();
    void cancelarSuscripcion();
    void clearCache();
    
    void setLoggedUser(Usuario *);
    //setDatos // Equivalente a ingresarDatosvideojuego  
    
    static VideojuegoController * getInstance();
    ~VideojuegoController();
};

#endif
