/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class implementation 
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "../include/sistema.h"

using namespace menuUtilities;
using namespace std;

Sistema::Sistema(){
//Hago las cosas pertinentes para iniciar el sistema...
}

int Sistema::modificarFecha(){
    cout << "Ingrese la fecha del sistema usando el formato dd/mm/yyyy hh:mm ." << endl;
    cout << "Si desea iniciar la partida con la fecha actual del sistema operativo (GNU/Linux) escriba 'ahora'." << endl;
    cout << "Fecha: ";

    int d,m,y,h,min;
    bool fecha_check=false;
    while(!fecha_check){
	try{
	    getline(cin,date_input);
	    if (date_input == "ahora") {
		time_t now = time(0);
		tm* time = localtime(&now);
		d = time->tm_mday;
		m = time->tm_mon + 1; 		// tm_mon devuelve el mes donde enero es igual a 0 (por lo tanto se suma uno).
		y = time->tm_year + 1900; 	// tm_year devuelve los anios despues de 1900 (por lo tanto hay que sumarlos).
		h = time->tm_hour;
		min = time->tm_min;
	    }
	    else{
		if (sscanf(date_input.c_str(),"%d/%d/%d %d:%d",&d,&m,&y,&h,&min) != 5)
		    throw invalid_argument("");
	    }
	    fechaSistema::fecha = DtFechaHora(d,m,y,h,min); 	//fechaSistema(dia, mes, anio, hora, min).
	    fecha_check=true;
	}
	catch(invalid_argument &e){
	    reprintln();
	    cout << "Por favor ingrese una fecha valida: ";
	}
    }
    cout << "Se registro exitosamente la nueva fecha del sistema." << endl;
    pkey();
    return 0;
}

int Sistema::cargarDatosPrueba(){
    //Aqui se realizan la secuencia de operaciones para generar el estado predefinido del sistema
    //solicitado
    
    return 0;
}

Sistema::~Sistema(){
//Hago las cosas pertinentes para cerrar el sistema... (se libera memoria)
}


