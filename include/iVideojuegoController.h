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
#include "dtSuscripcion.h"

using std::vector;
using std::string;

class DtVideojuego;
class DtCategoria;
class DtEstadistica;
enum class TipoValido;
enum class TipoPago;

class IVideojuegoController{
public:
    virtual set<string> *obtenerNombreVideojuegosDesarrollados()=0;
    virtual set<string> *obtenerNombreVideojuegosInactivos()=0;
    virtual vector<set<DtVideojuego>> *obtenerSuscripcionesVideojuegos()=0;
    virtual set<DtCategoria> *obtenerCategoriasGenero()=0;
    virtual set<DtCategoria> *obtenerCategoriasPlataforma()=0;
    virtual set<DtCategoria> *obtenerCategoriasOtro()=0;
    virtual set<DtEstadistica> *obtenerEstadisticas(string)=0;
    virtual void ingresarDatosVideojuego(DtVideojuego)=0;
    virtual void ingresarSuscripcion(TipoValido, TipoPago)=0;
    virtual void seleccionarVideojuego(string)=0;
    virtual void seleccionarGenero(string)=0;
    virtual void seleccionarPlataforma(string)=0;
    virtual void seleccionarCategoriaOtro(string)=0;
    virtual void confirmarPublicacion()=0;
    virtual void confirmarSuscripcion()=0;
    virtual void confirmarEliminarVideojuego()=0;
    virtual void cancelarSuscripcion()=0;
    virtual void clearCache()=0;

    //Caso de uso PublicarVideojuego:
    virtual bool existeVideojuego(string)=0;
    virtual bool hayCategorias()=0;

    //Caso de uso AgregarCategoria:
    virtual set<string> *obtenerNombreCategorias()=0;
    virtual int cargarCategoria(DtCategoria)=0;
    virtual void confirmarAgregarCategoria()=0;

    //Caso de uso VerInformacionVideojuego:
    virtual void obtenerInfoVideojuego() = 0;

    //Caso de uso PuntuarVideojuego
    virtual set<DtVideojuego>* verVideojuegos()=0;
    virtual int puntuar(string,int)=0;

    //Caso de uso SuscribirseVideojuego
    virtual DtSuscripcion getSuscripcion(string)=0;
 
    //Caso de uso seleccionarEstadisticas
    virtual set<DtEstadistica> * obtenerEstadisticas()=0;
    virtual set<DtEstadistica> * obtenerEstadisticasInv()=0;
    virtual void cargarEstadisticas(set<string>)=0;

    virtual ~IVideojuegoController(){}
};

#endif
