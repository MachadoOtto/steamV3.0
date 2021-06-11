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
#include "iVideojuegoController.h"
#include "usuario.h"
#include "jugador.h"
#include "desarrollador.h"
#include "videojuego.h"
#include "categoria.h"
#include "dtCategoria.h"

using std::vector;
using std::string;

class DtVideojuego;
class DtCategoria;
class DtEstadistica;
enum class TipoSuscripcion;
enum class TipoPago;

class VideojuegoController: public IVideojuegoController{
private:
    DtVideojuego datos;
    DtCategoria catData;
    TipoPago tPago;
    TipoValido tSus; //SUS!?
    Usuario * loggedUser; //Player OR Dev. depening on usecase under execution.
    Videojuego * videoCache;
    set<Categoria*> * categoriaCache;

    VideojuegoController();
public:
    set<string> *obtenerNombreVideojuegosDesarrollados();
    set<string> *obtenerNombreVideojuegosInactivos();
    set<vector<DtVideojuego>> *obtenerSuscripcionesVideojuegos();
    set<DtCategoria> *obtenerCategoriasGenero();
    set<DtCategoria> *obtenerCategoriasPlataforma();
    set<DtCategoria> *obtenerCategoriasOtro();
    set<DtEstadistica> *obtenerEstadisticas(string);
    void ingresarDatosVideojuego(DtVideojuego);
    void ingresarSuscripcion(TipoValido,TipoPago);
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
    
    //Caso de uso AgregarCategoria:
    set<string>* obtenerNombreCategorias();
    int cargarCategoria(DtCategoria);
    void confirmarAgregarCategoria();

    //Caso de uso PuntuarVideojuego
    set<DtVideojuego>* verVideojuegos();
    void puntuar(string,int);

    static VideojuegoController * getInstance();
    ~VideojuegoController();
};

#endif
