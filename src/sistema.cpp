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

    //Hay que crear las categorias que ya vienen en el sistema: generos y plataformas
}

int Sistema::modificarFecha(){
    cout << "Ingrese la fecha del sistema usando el formato dd/mm/yyyy hh:mm ." << endl;
    cout << "Si desea iniciar la partida con la fecha actual del sistema operativo (GNU/Linux) escriba 'ahora'." << endl;
    cout << "Fecha: ";
    string date_input;
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
	    fechaSistema::fecha = DtFechaHora(y,m,d,h,min); 	//fechaSistema(dia, mes, anio, hora, min).
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
int Sistema::altaUsuario(){
    LaFabrica * laFabrica = LaFabrica::getInstance();
    IAltaUsuarioController * IUsuario = laFabrica->getIAltaUsuarioController();

    string mail, pass;
    cout<< "Ingrese los siguientes datos para crear su usuario: "<< endl;
    cout<< "Email: ";
    getline(cin,mail);
    cout<< "Contrasenia: ";
    getline(cin,pass);
    DtUsuario datos(mail, pass);
    IUsuario->ingresarUsuario(datos);
    cout << endl;
    cout<<"Seleccione el tipo de usuario que desea dar de alta:"<< endl;
    cout << " 1. Jugador" << endl;
    cout << " 2. Desarrollador" << endl;
    cout << "(1-2)> ";
    int controlVar = takeInputRange(1,2);
    switch (controlVar) {
	case 1: {
	    string name;
            HandlerUsuario * hc = HandlerUsuario::getInstance(); //Corregir: sistema no habla con handler
	    cout << "Ingrese un nickname para su Jugador: ";
	    getline(cin,name);
	    //while (IUsuario->existeUsuario(name))
            while (hc->existeUsuario(name)){
		reprintln();
		cout << "Ese nickname ya está en uso, por favor ingrese otro: " << endl;
		getline(cin,name);
            }
            IUsuario->ingresarNickname(name);
            string des;
	    cout << "Ingrese una descripcion para su juguador: ";
	    getline(cin,des);
            IUsuario->ingresarDescripcion(des);
	    cout << "Se registrara un jugador con los siguientes datos en el sistema:\n\n";
	    cout << "Email: "<<mail<<endl;
	    cout << "Contrasenia: "<<pass<<endl;
	    cout << "Nickname: "<<name<<endl;
	    cout << "Descripcion: "<<des<<endl<<endl;
            break;
	    }
	case 2: {
	    string emp;
            cout << "Ingrese el nombre de su empresa: ";
	    getline(cin,emp);
            IUsuario->ingresarEmpresa(emp);
	    cout << "Se registrara un jugador con los siguientes datos en el sistema:\n\n";
	    cout << "Email: "<<mail<<endl;
	    cout << "Contrasenia: "<<pass<<endl;
	    cout << "Empresa: "<<emp<<endl<<endl;
	    break;
	    }
    }
    cout << "Desea darlo de alta? (y/n)>";
    if(boolSelect()){
	IUsuario->confirmarDarDeAltaUsuario();	
	cout << "Se ha registrado su usuario exitosamente.\n";
    }
    else
	cout << "Se ha cancelado la operacion Alta Usuario.\n";	
    pkey();
    return 0;
}
int Sistema::iniciarSesion(){
    LaFabrica * f = LaFabrica::getInstance();
    IAltaUsuarioController * h = f->getIAltaUsuarioController();
    string u,p;
    int user_ok = 2;
    cout << "Ingrese los siguientes datos para iniciar sesion.\nSi desea cancelar la operacion presione ENTER dos veces.\n\n\n";
    while(user_ok == 2 || user_ok == 3){
	cout << "Usuario(email): ";
	getline(cin,u);
	cout << "Contrasenia: ";
	getline(cin,p);
	if(u.length()==p.length() && u.length()==0){
	    cout << "Se ha cancelado el inicio de sesion.\n";
	    user_ok = 4;
	    break;
	}
	DtUsuario du(u,p);
	h->ingresarUsuario(du);
	user_ok = h->iniciarSesion();
	if(user_ok == 2){
	    reprintln();
	    reprintln();
	    reprintln();
	    cout << "ERROR: El usuario no existe en el sistema.\n";
	}
	if(user_ok == 3){
	    cout << "ERROR: La contrasenia ingresada no es correcta.\n";
	}    
	if(user_ok == 0 || user_ok == 1){
	    cout << "Inicio de sesion exitoso. Bienvenido " << u << ".\n";
	}
    }
    pkey();
    if
	(user_ok == 0) return 2;
    else if
	(user_ok == 1) return 1;
    else
	return 0;
}

int Sistema::cargarCategoria(){
    LaFabrica * f = LaFabrica::getInstance();
    IVideojuegoController * h = f->getIVideojuegoController();
    string n,d,t;
    TipoCategoria tcat;
    bool conf;
    int fin=0,i=0;
    cls();
    ptitle();
    cout << "El sistema cuenta con las siguientes categorias:\n";
    set<string>* namae = h->obtenerNombreCategorias();
    for(set<string>::iterator it = namae->begin(); it != namae->end(); ++i,++it)
	cout << "\t" << i << ". " << *(it) << "\n";
    cout << "\nIngrese los siguientes datos para agregar una nueva categoria al sistema:\n\n\n";
    while(!fin){
	cout << "Nombre: ";
	getline(cin,n);
	bool nOk=true;
	for(set<string>::iterator it = namae->begin(); it != namae->end() && nOk; it++)
	    if(n==*(it)){
		reprintln();
		reprintln();
		cout << "ERROR: El nombre de la categoria a crear ya existe en el sistema.\n";
		nOk = false;
	    }
	if(!nOk)
	    break;
	cout << "Descripcion: ";
	getline(cin,d);
	cout << "Tipo (Genero/Plataforma/Otro):";
	getline(cin,t);
	cls();
	ptitle();
	if (t=="Genero"||t=="genero"){
	    tcat = TipoCategoria::Genero;
	    t = "Genero";
	}
	if (t=="Plataforma"||t=="plataforma"){
	    tcat = TipoCategoria::Plataforma;
	    t = "Plataforma";
	}
	if (t=="Otro"||t=="otro"){
	    tcat = TipoCategoria::Otro;
	    t = "Otro";
	}
	else{
	    tcat = TipoCategoria::Otro;
	    cout << "Advertencia: El tipo categoria \""<<t<<"\" no existe como tal en el sistema. Se le ha asignado el tipo \"Otro\".\n";   
	    t = "Otro";
	}	
	cout << "\nLa siguiente categoria sera agregada al sistema:\n\n";
	cout << "Nombre: "<<n<<endl;
	cout << "Descripcion: "<<d<<endl;
	cout << "Tipo: "<<t<<endl<<endl;
	cout << "Desea confirmar su creacion? (y/n)>";
	conf = boolSelect();
	if (conf){
	    h->cargarCategoria(DtCategoria(n,d,tcat));
	    h->confirmarAgregarCategoria();		    
	    cout << "Se ha creado una nueva categoria de manera exitosa.\n";
	}
	else
	    cout << "La operacion para agregar una nueva categoria ha sido cancelada.\n";
	fin = 1;
    }
    delete namae;
    pkey();
    return 0;
}

int Sistema::publicarVideojuego(){
    return 0;
}
int Sistema::eliminarVideojuego(){
    return 0;
}

int Sistema::seleccionarEstadistica(){
    return 0;
}

int Sistema::consultarEstadisticas(){
  LaFabrica * laFabrica = LaFabrica::getInstance();
  IVideojuegoController * IVideo = laFabrica->getIVideojuegoController();
  set<string>  * vjDes = IVideo->obtenerNombreVideojuegosDesarrollados();
  string vid;
  cout << "Ingrese el nombre del videojuego al cual quiere consultar sus estadisticas: "<< endl;
  cin >> vid;
  delete vjDes;
  IVideo->obtenerEstadisticas(vid);

    return 0;
}

int Sistema::verInformacionVideojuego(){
    return 0;
}

int Sistema::suscribirseVideojuego(){
   LaFabrica *laFabrica = LaFabrica::getInstance();
   IVideojuegoController *IVid = laFabrica->getIVideojuegoController();
   set<vector<DtVideojuego>> * vj = IVid->obtenerSuscripcionesVideojuegos();
   string vjSus;
   cout << "Ingrese el nombre del videojuego al que se quiere suscribir: "<<endl;
   cin >> vjSus;
   delete vj;
   IVid->seleccionarVideojuego(vjSus);
//   if (!Tiene susc activa){
      cout <<"Seleccione el tipo de suscripcion que desea: "<<endl; 
      cout <<"1 = 1 mes"<< endl;
      cout <<"2 = 3 meses"<< endl;
      cout <<"3 = 1 año"<< endl;
      cout <<"4 = vitalicia"<< endl;
      TipoValido sus;
      int controlVar = takeInputRange(1,4);
         switch (controlVar){
            case 1: {
               sus  = TipoValido::UnMes;
               break;
            }
            case 2: {
               sus = TipoValido::TresMeses;
               break;
            }
            case 3: {
               sus = TipoValido::Anio;
               break;
            }
            case 4: {
               sus = TipoValido::Vitalicia;
               break;
            }
         }
 //        }
      cout <<"Ingrese el metodo de pago"<< endl;
      cout <<"Ingrese 1 si desea pagar con paypal o 2 para usar tarjeta"<<endl;
      TipoPago pago;
      int var = takeInputRange(1,2);
         switch (var){
            case 1: {
               pago  = TipoPago::Paypal;
               break;
            }
            case 2: {
               pago = TipoPago::Tarjeta;
               break;
            }
         }
      IVid->ingresarSuscripcion(sus, pago);
      cout <<"¿Desea confirmar su compra?"<< endl;
      cout <<"Ingrese 1 para confirmar o 0 para cancelar"<<endl;
      int x = takeInputRange(0,1);
            switch (x) {
               case 0:{ 
                   break;
               }
               case 1: {
                  IVid->confirmarSuscripcion();
                  break;
               }
   }
  // else {
     // if (es temporal){ 
         cout <<"¿Desea cancelar la suscricpion? "<<endl;
         cout <<"Ingrese 1 si desea cancelar o 0 si no quiere cancelarla "<<endl;

         int y = takeInputRange(0,1);
            switch (y) {
               case 0: {
                   break;
               }
               case 1: {
                  IVid->cancelarSuscripcion();
                  break;
               }
         }
     // }
  // }   
   return 0;
}

int Sistema::asignarPuntajeVideojuego(){
    int i=0;
    bool nok=false;
    string p;
    int kp;

    LaFabrica * f = LaFabrica::getInstance();
    IVideojuegoController * h = f->getIVideojuegoController();
    cout << "El sistema cuenta con el siguiente catalogo de videojuegos:\n";
    set<DtVideojuego>* namae = h->verVideojuegos();
    for(set<DtVideojuego>::iterator it = namae->begin(); it != namae->end(); i++,it++){
	cout << "\t" << i << ". Nombre: " << it->getNombre() << "\n";
	for(int j=0;j<i/10;j++)
	    cout << " ";
	cout << "Descripcion: " << it->getDescripcion() << "\n";
    }
    cout << "\nIngrese el nombre de la partida que desea puntuar: ";
    while(!nok){
	getline(cin,p);
	for(set<DtVideojuego>::iterator it = namae->begin(); it!=namae->end() && !nok; ++it)
	    if(it->getNombre() == p)
		return true;
	else{
	    clinput();
	    reprintln();
	    cout << "Por favor ingrese una opcion valida: ";
	}
    }	
    cout << "\n Ingrese su puntuacion para el videojuego \""<<p<<"\"(1-5): ";
    kp = takeInputRange(1,5);
    h->puntuar(p,kp);   	
    cout << "Se ha registrado su puntaje exitosamente\n";
    delete namae;
    pkey();
    return 0;
}

int Sistema::iniciarPartida(){
    int idAnterior = -1;
    bool enVivo;
    set<string>* jIngresados = new set<string>;
    LaFabrica* factory = LaFabrica::getInstance();
    IIFPController* interface = factory->getIIFPController();
    interface->iniciarSesion();
    set<string>* vjActivos = interface->obtenerVideojuegosActivos();
    cout << "Iniciar Partida \n \n";
    cout << "Videojuegos con suscripcion activa: \n";
    for (set<string>::iterator it = vjActivos->begin(); it != vjActivos->end(); ++it) {
        cout << *it << "\n";
    }
    cout << "Ingrese el nombre del Videojuego al que quiera iniciar su Partida: ";
    string nombreVj;
    while (true) {
        getline(cin, nombreVj);
        if (vjActivos->find(nombreVj) == vjActivos->end()) {
            reprintln();
            cout << "Porfavor, ingrese un Videojuego valido: ";
        } else {
            break;
        }
    }
    delete vjActivos;
    interface->seleccionarVideojuego(nombreVj);
    cout << "Seleccione un tipo de Partida a iniciar: (1. Individual, 2. Multijugador) \n";
    string tipoPartida;
    while (true) {
        getline(cin, tipoPartida);
        if ((tipoPartida == "1") || (tipoPartida == "2") || (tipoPartida == "Individual") || (tipoPartida == "Multijugador") 
                || (tipoPartida == "individual") || (tipoPartida == "multijugador")) {
            break;
        } else {
            reprintln();
            cout << "Porfavor, ingrese una opcion valida: ";
        }
    }
    if ((tipoPartida == "1") || (tipoPartida == "Individual") || (tipoPartida == "individual")) {
        tipoPartida = "Individual";
        cout << "Su Partida es continuacion de una Partida anterior? (1. Si, 2. No) \n";
        string esCont;
        while (true) {
            getline(cin, esCont);
            if ((esCont == "1") || (esCont == "Si") || (esCont == "si") || (esCont == "2") || (esCont == "No") || (esCont == "no")) {
                break;
            } else {
                reprintln();
                cout << "Porfavor, ingrese una opcion valida: ";
            }
        }
        if ((esCont == "1") || (esCont == "Si") || (esCont == "si")) {
            map<DtFechaHora, DtPartidaIndividual*>* pAnteriores = interface->obtenerHistorialPartidas();
            cout << "Partidas anteriores: \n";
            for (map<DtFechaHora, DtPartidaIndividual*>::iterator it = pAnteriores->begin(); it != pAnteriores->end(); ++it) {
                cout << it->second;
            }
            cout << "Ingrese el Id de la partida a continuar: \n";
            while (true) {
                if (!(cin >> idAnterior)) {
			        clinput();
                    cout << "Porfavor, ingrese un Id correcto: ";
                } else {
                    clinput();
                    bool exId = false;
                    for (map<DtFechaHora, DtPartidaIndividual*>::iterator it = pAnteriores->begin(); it != pAnteriores->end(); ++it) {
                        if (it->second->getId() == idAnterior) {
                            exId = true;
                            break;
                        }
                        cout << it->second;
                    }
                    if (!exId) {
                        reprintln();
                        cout << "Porfavor, ingrese un Id correcto: ";
                    } else {
                        break;
                    }
                }
            }
            for (map<DtFechaHora, DtPartidaIndividual*>::iterator it = pAnteriores->begin(); it != pAnteriores->end(); ++it) {
                delete it->second;
            }
            delete pAnteriores;
            interface->seleccionarContinuacionPartida(idAnterior);
        }
    } else {
        tipoPartida = "Multijugador";
        cout << "Su Partida se transmitira en vivo? (1. Si, 2. No) \n";
        string tEnVivo;
        while (true) {
            getline(cin, tEnVivo);
            if ((tEnVivo == "1") || (tEnVivo == "Si") || (tEnVivo == "si") || (tEnVivo == "2") || (tEnVivo == "No") || (tEnVivo == "no")) {
                if ((tEnVivo == "1") || (tEnVivo == "Si") || (tEnVivo == "si")) {
                    enVivo = true;
                } else {
                    enVivo = false;
                }
                break;
            } else {
                reprintln();
                cout << "Porfavor, ingrese una opcion valida: ";
            }
        }
        interface->setEnVivo(enVivo);
        cout << "Los Jugadores con suscripciones activas actualmente son: \n";
        set<string>* jugadoresSus = interface->obtenerJugadoresSubscriptos();
        for (set<string>::iterator it = jugadoresSus->begin(); it != jugadoresSus->end(); ++it) {
            cout << *it << "\n";
        }
        cout << "Ingrese los nicknames de los jugadores a agregar a la partida. Para finalizar ingrese '0' : \n";
        string nick;
        while (true) {
            getline(cin, nick);
            if (nick != "0") {
                if (jugadoresSus->find(nick) == jugadoresSus->end()) {
                    reprintln();
                    cout << "Porfavor, ingrese un Nickname valido: ";
                } else {
                    jIngresados->insert(nick);
                    interface->aniadirJugadorPartida(nick);
                    break;
                }
            } else {
                break;
            }
        }
        delete jugadoresSus;
    }
    cout << "Los datos ingresados de la partida a Iniciar son: \n";
    cout << "  Videojuego: " << nombreVj << "\n";
    cout << "  Tipo Partida: " << tipoPartida << "\n";
    if (tipoPartida == "Individual") {
        if (idAnterior != -1) {
            cout << "  Id Partida anterior: " << idAnterior << "\n";
        } else {
            cout << "  No es continuacion de otra Partida \n";
        }
    } else {
        if (enVivo) {
            cout << "  La partida se transmite en vivo. \n";
        } else {
            cout << "  La partida no esta siendo transmitida. \n";
        }
        cout << "  Los jugadores unidos son: \n";
        for (set<string>::iterator it = jIngresados->begin(); it != jIngresados->end(); ++it) {
            cout << "    " << *it << "\n";
        }
    }
    delete jIngresados;
    cout << "Confirma el Alta de la Partida? (1. Si, 2. No)";
    string confirmar;
    while (true) {
        getline(cin, confirmar);
        if ((confirmar == "1") || (confirmar == "Si") || (confirmar == "si") || (confirmar == "2") 
                || (confirmar == "No") || (confirmar == "no")) {
            break;
        } else {
            reprintln();
            cout << "Porfavor, ingrese una opcion valida: ";
        }
    }
    if ((confirmar == "1") || (confirmar == "Si") || (confirmar == "si")) {
        interface->confirmarPartida();
        cout << "La partida se ha dado de alta exitosamente. \n";
    }
    interface->clearCache();
    pkey();
    return 0;
}

int Sistema::abandonarPartidaMultijugador(){
    LaFabrica* factory = LaFabrica::getInstance();
    IIFPController* interface = factory->getIIFPController();
    map<DtFechaHora, DtPartidaMultijugador*>* multiActivas = interface->obtenerPartidasMultiActivas();
    cout << "Abandonar Partida Multijugador \n \n";
    cout << "Partidas multijugador activas a las que se unio: \n";
    for (map<DtFechaHora, DtPartidaMultijugador*>::iterator it = multiActivas->begin(); it != multiActivas->end(); ++it) {
        cout << *it->second << "\n";
    }
    cout << "Ingrese la Id de la partida multijugador a abandonar (ingrese '-1' si desea cancelar): \n";
    int id;
    while (true) {
        if (!(cin >> id)) {
		    clinput();
            reprintln();
            cout << "Porfavor, ingrese un Id correcto (ingrese '-1' si desea cancelar): ";
        } else {
            if (id == -1) {
                break;
            }
            clinput();
            bool exId = false;
            for (map<DtFechaHora, DtPartidaMultijugador*>::iterator it = multiActivas->begin(); it != multiActivas->end(); ++it) {
                if (it->second->getId() == id) {
                    exId = true;
                    break;
                }
            }
            if (!exId) {
                reprintln();
                cout << "Porfavor, ingrese un Id correcto (ingrese '-1' si desea cancelar): ";
            } else {
                break;
            }
        }
    }
    for (map<DtFechaHora, DtPartidaMultijugador*>::iterator it = multiActivas->begin(); it != multiActivas->end(); ++it) {
        delete it->second;
    }
    delete multiActivas;
    if (id != -1) {
        interface->confirmarAbandonarPartida(id);
        cout << "Se ha abandonado la partida multijugador (ID: " << id << ") correctamente.";
    } else {
        cout << "Se ha cancelado el abandono de la partida multijugador.";
    }
    interface->clearCache();
    pkey();
    return 0;
}

int Sistema::finalizarPartida(){
    LaFabrica* factory = LaFabrica::getInstance();
    IIFPController* interface = factory->getIIFPController();
    map<DtFechaHora, DtPartida*>* partidasActivas = interface->obtenerPartidasActivas();
    cout << "Finalizar Partida \n \n";
    cout << "Partidas actualmente activas: \n";
    DtPartidaIndividual* pInd;
    DtPartidaMultijugador* pMulti;
    for (map<DtFechaHora, DtPartida*>::iterator it = partidasActivas->begin(); it != partidasActivas->end(); ++it) {
        if ((pInd = dynamic_cast<DtPartidaIndividual*>(it->second))) {
            cout << *pInd << "\n";
        } else {
            pMulti = dynamic_cast<DtPartidaMultijugador*>(it->second);
            cout << *pMulti << "\n";
        }
    }
    cout << "Ingrese la Id de la partida a finalizar (ingrese '-1' si desea cancelar): \n";
    int id;
    while (true) {
        if (!(cin >> id)) {
		    clinput();
            reprintln();
            cout << "Porfavor, ingrese un Id correcto (ingrese '-1' si desea cancelar): ";
        } else {
            clinput();
            bool exId = false;
            for (map<DtFechaHora, DtPartida*>::iterator it = partidasActivas->begin(); it != partidasActivas->end(); ++it) {
                if (it->second->getId() == id) {
                    exId = true;
                    break;
                }
            }
            if (!exId) {
                reprintln();
                cout << "Porfavor, ingrese un Id correcto (ingrese '-1' si desea cancelar): ";
            } else {
                break;
            }
        }
    }
    for (map<DtFechaHora, DtPartida*>::iterator it = partidasActivas->begin(); it != partidasActivas->end(); ++it) {
        delete it->second;
    }
    delete partidasActivas;
    if (id != -1) {
        interface->confirmarAbandonarPartida(id);
        cout << "Se ha finalizado la partida (ID: " << id << ") correctamente.";
    } else {
        cout << "No se ha finalizado la partida.";
    }
    interface->clearCache();
    pkey();
    return 0;
}

string Sistema::getLoggedUserEmail(){
    return "lol";
}

Sistema::~Sistema(){
//Hago las cosas pertinentes para cerrar el sistema... (se libera memoria)
}


