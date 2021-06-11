/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Integrantes:
 *      Alexis Baladon (5.574.612-4) - alexis.baladon@fing.edu.uy
 *      Guillermo Toyos (5.139.879-9) - guillermo.toyos@fing.edu.uy
 *      Jorge Machado (4.876.616-9) - jorge.machado.ottonelli@fing.edu.uy
 *      Juan Jose Mangado (5.535.227-0) - juan.mangado@fing.edu.uy
 *      Mathias Ramilo (5.665.788-5) - mathias.ramilo@fing.edu.uy
 */

#include <../include/partidaIndividual.h>

PartidaIndividual::PartidaIndividual(DtPartidaIndividual datos) : Partida(DtPartida(datos.getId(), datos.getFecha(),
        datos.getDuracion(), datos.esActiva())) { 
    partidaAnterior = NULL;
}

void PartidaIndividual::setPartidaAnterior(PartidaIndividual* pAnt) {
    partidaAnterior = pAnt;
}

PartidaIndividual* PartidaIndividual::getPartidaAnterior() { return partidaAnterior; }

DtPartida* PartidaIndividual::obtenerDatosPartida() {
    DtPartidaIndividual* datosP = new DtPartidaIndividual(this->getId(), this->getDtFechaHora(), this->getDuracion(), this->esActiva(), this->getPartidaAnterior()->getId());
    return datosP;
}

void PartidaIndividual::asignarHoraFinalizacion() {
    this->setDuracion(this->getDtFechaHora().diffHoras(fechaSistema::fecha));
}

void PartidaIndividual::eliminarAssoc() {
    //this->getHost()->remove(this) revisar esto. partida no tendria que hablar con jugador... generaria una dependencia circular. Se tendria que hacer de otra manera esto
}

PartidaIndividual::~PartidaIndividual() { }
