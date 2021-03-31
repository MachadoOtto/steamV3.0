# Laboratorio Programacion IV - INCO/FING/UDELAR
# Laboratorio 0 - Makefile 
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

MODULOS = dtFechaHora dtJugador dtPartida dtPartidaIndividual dtPartidaMultijugador dtVideojuego listaJugador listaPartida listaVideojuego partidaIndividual partidaMultijugador jugador partida sistema videojuego
CONST_MODULES = tipoJuego constraints

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
	tar -cvzf 06_lab0.tar.gz *
	$(info Archivo a entregar: 06_lab0.tar.gz )

