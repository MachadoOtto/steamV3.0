/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef iVideoJueGoController
#define iVideoJueGoController

#include <string>
#include <vector>

using std::vector;
using std::string;

class DtVideojuego;
class DtCategoria;
class DtEstadistica;
enum class TipoSuscripcion;
enum class TipoPago;

class IVideojuegoController{
public:
    virtual vector<string> *obtenerNombreVideojuegosDesarrollados()=0;
    virtual vector<string> *obtenerNombreVideojuegosInactivos()=0;
    virtual vector<vector<DtVideojuego>> *obtenerSuscripcionesVideojuegos()=0;
    virtual vector<DtCategoria> *obtenerCategoriasGenero()=0;
    virtual vector<DtCategoria> *obtenerCategoriasPlataforma()=0;
    virtual vector<DtCategoria> *obtenerCategoriasOtros()=0;
    virtual vector<DtEstadistica> *obtenerEstadisticas(string)=0;
    virtual void ingresarDatosVideojuego(DtVideojuego)=0;
    virtual void ingresarSuscripcion(TipoSuscripcion, TipoPago)=0;
    virtual void seleccionarVideojuego(string)=0;
    virtual void seleccionarGenero(string)=0;
    virtual void seleccionarPlataforma(string)=0;
    virtual void seleccionarCategoriaOtro(string)=0;
    virtual void confirmarPublicacion()=0;
    virtual void confirmarSuscripcion()=0;
    virtual void confirmarEliminarVideojuego()=0;
    virtual void cancelarSuscripcion()=0;
    virtual void clearCache();

    virtual ~IVideojuegoController();
};

#endif
