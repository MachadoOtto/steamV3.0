/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Integrantes:
 *      Alexis Baladon (5.574.612-4) - alexis.baladon@fing.edu.uy
 *      Guillermo Toyos (5.139.879-9) - guillermo.toyos@fing.edu.uy
 *      Jorge Machado (4.876.616-9) - jorge.machado.ottonelli@fing.edu.uy
 *      Juan Jose Mangado (5.535.227-0) - juan.mangado@fing.edu.uy
 *      Mathias Ramilo (5.665.788-5) - mathias.ramilo@fing.edu.uy
 */

#include <../include/partidaIndividual.h>

PartidaIndividual::PartidaIndividual(DtPartidaIndividual datos) : Partida(DtPartida dpartida(datos.getIdentificador(), datos.getFechaHora(),
        datos.getDuracion(), datos.getActiva())) { 
    partidaAnterior = NULL;
}

PartidaIndividual* PartidaIndividual::create(datos, punteros*) {
    PartidaIndividual* nuevo = new PartidaIndividual(datos)
    nuevo->apunto = punteros;
    return nuevo;
}

void PartidaIndividual::setPartidaAnterior(PartidaIndividual* pAnt) {
    partidaAnterior = pAnt;
}

PartidaIndividual* PartidaIndividual::getPartidaAnterior() { return partidaAnterior; }

virtual DtPartida PartidaIndividual::obtenerDatosPartida() {
    DtPartida datosP(identificador, fecha, duracion, activa);
    return datosP;
}

virtual void PartidaIndividual::asignarHoraFinalizacion(DtFechaHora fechaFinal) {
    duracion = fecha.diffHoras(fechaFinal);
}

virtual void PartidaIndividual::finalizarPartida(DtFechaHora horaFinal) {
    this.setActiva(false);
    this.asignarHoraFinalizacion(horafinal);
}

virtual void PartidaIndividual::eliminarAssoc() {
    host.remove(this);
}

PartidaIndividual::~PartidaIndividual() { }