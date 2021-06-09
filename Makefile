# Laboratorio Programacion IV - INCO/FING/UDELAR
# Laboratorio 4 - Makefile 
# Autores (por nombre):
# 	Alexis Baladon 
#  	Guillermo Toyos
#  	Jorge Machado
#  	Juan Jose Mangado
#  	Mathias Ramilo
# 

all: main
.PHONY: all clean_bin entrega

#directorios
HDIR = include
CPPDIR = src
ODIR = obj

#compilador
CC = g++
CCFLAGS = -Wall -Werror -I$(HDIR) -g
#luego agregar altaUsuarioController
MODULOS = altaUsuarioController desarrollador sistema partida categoria dtCategoria dtDesarrollador dtFechaHora dtJugador dtPartida dtPartidaIndividual dtPartidaMultijugador dtPrecios dtUsuario dtVideojuego estadistica estadisticaTotalHorasJugadas estadisticaTotalJugadoresSuscriptos genero handlerCatalogo handlerCategoria handlerEstadistica handlerUsuario jugadorMulti jugador laFabrica menuUtilities partida partidaIndividual partidaMultijugador plataforma sistema suscripcion iFPController suscripcionTemporal suscripcionVitalicia usuario videojuego videojuegoController#Add more here
CONST_MODULES = tipoPlataforma tipoPago tipoCategoria iAltaUsuarioController iIFPController iVideojuegoController tipoCategoria tipoEstado tipoGenero tipoPago tipoValido fechaSistema#Add more here

#lista de archivos
HS = $(MODULOS:%=$(HDIR)/%.h)
CPPS = $(MODULOS:%=$(CPPDIR)/%.cpp)
OS = $(MODULOS:%=$(ODIR)/%.o)
CONST_HS = $(CONST_MODULES:%=$(HDIR)/%.h)

MAIN=main
EJECUTABLE=main

$(ODIR)/$(MAIN).o: $(MAIN).cpp | objfolder
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/%.o: $(CPPDIR)/%.cpp $(HDIR)/%.h $(CONST_HS) | objfolder
	$(CC) $(CCFLAGS) -c $< -o $@

$(EJECUTABLE): $(ODIR)/$(MAIN).o $(OS)
	$(CC) $(CCFLAGS) $^ -o $@
	$(info ***Compilacion exitosa***)
	$(info Archivo ejecutable generado: $(EJECUTABLE))

objfolder:
	mkdir -p $(ODIR) 

clean_bin:
	rm -f $(EJECUTABLE) $(ODIR)/$(MAIN).o $(OS)
	rmdir $(ODIR)

entrega: $(EJECUTABLE)
	tar -cvzf 06_lab4.tar.gz *
	$(info Archivo a entregar: 06_lab0.tar.gz )

