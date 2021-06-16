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
    //Hay que inicializar las estadisticas
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
	    fechaSistema::fecha = DtFechaHora(y,m,d,h,min); 	//fechaSistema(anio, mes, dia, hora, min).
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
    LaFabrica * lf = LaFabrica::getInstance();
    IAltaUsuarioController * iu = lf->getIAltaUsuarioController();
    IVideojuegoController * iv = lf->getIVideojuegoController();
    IIFPController * iifp = lf->getIIFPController();
    DtUsuario datos("","");

    //DESARROLLADORES 
    datos=DtUsuario("ironhide@mail.com","123");
    iu->ingresarUsuario(datos);
    iu->ingresarEmpresa("Ironhide Game Studio");
    iu->confirmarDarDeAltaUsuario();

    datos=DtUsuario("epic@mail.com","123");
    iu->ingresarUsuario(datos);
    iu->ingresarEmpresa("EpicGames");
    iu->confirmarDarDeAltaUsuario();
 
    datos=DtUsuario("mojang@mail.com","123");
    iu->ingresarUsuario(datos);
    iu->ingresarEmpresa("Mojang Studios");
    iu->confirmarDarDeAltaUsuario();
 
    datos=DtUsuario("ea@mail.com","123");
    iu->ingresarUsuario(datos);
    iu->ingresarEmpresa("EA Sports");
    iu->confirmarDarDeAltaUsuario();

    //JUGADORES
    datos=DtUsuario("gamer@mail.com","123");
    iu->ingresarUsuario(datos);
    iu->ingresarNickname("gamer");
    iu->ingresarDescripcion("Usuario gamer, muy gamer.");
    iu->confirmarDarDeAltaUsuario();

    datos=DtUsuario("ari@mail.com","123");
    iu->ingresarUsuario(datos);
    iu->ingresarNickname("ari");
    iu->ingresarDescripcion("I am ari uwu");
    iu->confirmarDarDeAltaUsuario();

    datos=DtUsuario("ibai@mail.com","123");
    iu->ingresarUsuario(datos);
    iu->ingresarNickname("ibai");
    iu->ingresarDescripcion("wtf is ibai");
    iu->confirmarDarDeAltaUsuario();

    datos=DtUsuario("camila@mail.com","123");
    iu->ingresarUsuario(datos);
    iu->ingresarNickname("camila");
    iu->ingresarDescripcion("XxxCamilaxxX");
    iu->confirmarDarDeAltaUsuario();

    //CATEGORIAS
    TipoCategoria tcat;
    tcat = TipoCategoria::Plataforma;
    iv->cargarCategoria(DtCategoria("PC","PC Mastercace",tcat)); 
    iv->confirmarAgregarCategoria();

    iv->cargarCategoria(DtCategoria("PS4","Gr4t console m8",tcat)); 
    iv->confirmarAgregarCategoria();

    iv->cargarCategoria(DtCategoria("Xbox One","cringe",tcat)); 
    iv->confirmarAgregarCategoria();

    tcat = TipoCategoria::Genero;
    iv->cargarCategoria(DtCategoria("Deporte","balls",tcat)); 
    iv->confirmarAgregarCategoria();

    iv->cargarCategoria(DtCategoria("Supervivencia","Juegos tipo maincra",tcat)); 
    iv->confirmarAgregarCategoria();

    iv->cargarCategoria(DtCategoria("Estrategia","inb4 400 APM",tcat)); 
    iv->confirmarAgregarCategoria();

    tcat= TipoCategoria::Otro;
    iv->cargarCategoria(DtCategoria("Teen","Su contenido esta dirigido a jovenes de 13 anos en adelante",tcat)); 
    iv->confirmarAgregarCategoria();

    iv->cargarCategoria(DtCategoria("E","Su contenido esta dirigido a todo publico",tcat)); 
    iv->confirmarAgregarCategoria();

    //VIDEOJUEGOS
    iv->clearCache();
    
	iu->ingresarUsuario(DtUsuario("ironhide@mail.com","123"));
	iu->iniciarSesion();
    iv->ingresarDatosVideojuego(DtVideojuego("KingdomRush", "Rush B manito!", 1, 2, 7, 14));
    iv->seleccionarPlataforma("PC");
    iv->seleccionarPlataforma("PS4");
    iv->seleccionarGenero("Estrategia");
    iv->seleccionarCategoriaOtro("E");
    iv->confirmarPublicacion();
    
    iu->ingresarUsuario(DtUsuario("epic@mail.com","123"));
	iu->iniciarSesion();
    iv->ingresarDatosVideojuego(DtVideojuego("Fortnite", "El Free Fire de los noobs", 3, 8, 30, 60));
    iv->seleccionarPlataforma("PC");
    iv->seleccionarPlataforma("PS4");
    iv->seleccionarPlataforma("Xbox One");
    iv->seleccionarGenero("Supervivencia");
    iv->seleccionarCategoriaOtro("Teen");
    iv->confirmarPublicacion();

    iu->ingresarUsuario(DtUsuario("mojang@mail.com","123"));
	iu->iniciarSesion();
    iv->ingresarDatosVideojuego(DtVideojuego("Minecraft", "Creeper goes BRRR", 2, 5, 20, 40));
    iv->seleccionarPlataforma("PC");
    iv->seleccionarGenero("Supervivencia");
    iv->seleccionarCategoriaOtro("E");
    iv->confirmarPublicacion();

    iu->ingresarUsuario(DtUsuario("ea@mail.com","123"));
	iu->iniciarSesion();
    iv->ingresarDatosVideojuego(DtVideojuego("FIFA 21", "Hoy no puedo, tengo futbol VEINTIUNO", 3, 8, 28, 50));
    iv->seleccionarPlataforma("PC");
    iv->seleccionarPlataforma("PS4");
    iv->seleccionarPlataforma("Xbox One");
    iv->seleccionarGenero("Deporte");
    iv->seleccionarCategoriaOtro("E");
    iv->confirmarPublicacion();

    //SUSCRIPCIONES A VIDEOJUEGOS

    fechaSistema::fecha = DtFechaHora(2021,6,1,9,0); // DtFechaHora(anio, mes, dia, hora, min).
    iu->ingresarUsuario(DtUsuario("gamer@mail.com","123"));
    iu->iniciarSesion();
    iv->seleccionarVideojuego("KingdomRush");
    iv->ingresarSuscripcion(TipoValido::TresMeses, TipoPago::Paypal);
    iv->confirmarSuscripcion();

    fechaSistema::fecha = DtFechaHora(2021,6,2,11,0); // DtFechaHora(anio, mes, dia, hora, min).
    iu->ingresarUsuario(DtUsuario("gamer@mail.com","123"));
    iu->iniciarSesion();
    iv->seleccionarVideojuego("Fortnite");
    iv->ingresarSuscripcion(TipoValido::TresMeses, TipoPago::Tarjeta);
    iv->confirmarSuscripcion();

    fechaSistema::fecha = DtFechaHora(2021,6,4,9,0); // DtFechaHora(anio, mes, dia, hora, min).
    iu->ingresarUsuario(DtUsuario("ari@mail.com","123"));
    iu->iniciarSesion();
    iv->seleccionarVideojuego("Fortnite");
    iv->ingresarSuscripcion(TipoValido::UnMes, TipoPago::Paypal);
    iv->confirmarSuscripcion();

    fechaSistema::fecha = DtFechaHora(2021,6,11,9,0); // DtFechaHora(anio, mes, dia, hora, min).
    iu->ingresarUsuario(DtUsuario("ari@mail.com","123"));
    iu->iniciarSesion();
    iv->seleccionarVideojuego("Minecraft");
    iv->ingresarSuscripcion(TipoValido::Anio, TipoPago::Tarjeta);
    iv->confirmarSuscripcion();
    
    fechaSistema::fecha = DtFechaHora(2021,6,3,7,0); // DtFechaHora(anio, mes, dia, hora, min).
    iu->ingresarUsuario(DtUsuario("ibai@mail.com","123"));
    iu->iniciarSesion();
    iv->seleccionarVideojuego("Fortnite");
    iv->ingresarSuscripcion(TipoValido::UnMes, TipoPago::Tarjeta);
    iv->confirmarSuscripcion();

    fechaSistema::fecha = DtFechaHora(2020,12,21,15,0); // DtFechaHora(anio, mes, dia, hora, min).
    iu->ingresarUsuario(DtUsuario("ibai@mail.com","123"));
    iu->iniciarSesion();
    iv->seleccionarVideojuego("Fortnite");
    iv->ingresarSuscripcion(TipoValido::Vitalicia, TipoPago::Tarjeta);
    iv->confirmarSuscripcion();

    //PUNTAJES A VIDEOJUEGOS
    /*
    iu->ingresarUsuario(DtUsuario("gamer@mail.com","123"));
    iu->iniciarSesion();
    iv->puntuar("KingdomRush",4);
    iv->clearCache();

    iu->ingresarUsuario(DtUsuario("gamer@mail.com","123"));
    iu->iniciarSesion();
    iv->puntuar("Fortnite",5);
    iv->clearCache();

    iu->ingresarUsuario(DtUsuario("ari@mail.com","123"));
    iu->iniciarSesion();
    iv->puntuar("Fornite",5);
    iv->clearCache();

    iu->ingresarUsuario(DtUsuario("ari@mail.com","123"));
    iu->iniciarSesion();
    iv->puntuar("Minecraft",3);
    iv->clearCache();
    */

    //PARTIDAS INDIVIDUALES

    fechaSistema::fecha = DtFechaHora(2021,6,2,9,0); // DtFechaHora(anio, mes, dia, hora, min).
    iu->ingresarUsuario(DtUsuario("gamer@mail.com","123"));
    iu->iniciarSesion();
    iifp->iniciarSesion();
    iifp->seleccionarVideojuego("KingdomRush");
    iifp->setTipo(true); // true == individual ; false == multijugador.
    iifp->confirmarPartida();
    iifp->clearCache();
    fechaSistema::fecha = DtFechaHora(2021,6,2,10,0);
    iu->ingresarUsuario(DtUsuario("gamer@mail.com","123"));
    iu->iniciarSesion();
    iifp->iniciarSesion();
    iifp->confirmarFinalizarPartida(iifp->getIdSisActual());
    iifp->clearCache();

    fechaSistema::fecha = DtFechaHora(2021,6,3,15,0); // DtFechaHora(anio, mes, dia, hora, min).
    iu->ingresarUsuario(DtUsuario("gamer@mail.com","123"));
    iu->iniciarSesion();
    iifp->iniciarSesion();
    iifp->seleccionarVideojuego("KingdomRush");
    iifp->setTipo(true); // true == individual ; false == multijugador.
    iifp->seleccionarContinuacionPartida(iifp->getIdSisActual());
    iifp->confirmarPartida();
    iifp->clearCache();
    fechaSistema::fecha = DtFechaHora(2021,6,3,16,0);
    iu->ingresarUsuario(DtUsuario("gamer@mail.com","123"));
    iu->iniciarSesion();
    iifp->iniciarSesion();
    iifp->confirmarFinalizarPartida(iifp->getIdSisActual());
    iifp->clearCache();

    fechaSistema::fecha = DtFechaHora(2021,6,12,16,0); // DtFechaHora(anio, mes, dia, hora, min).
    iu->ingresarUsuario(DtUsuario("ari@mail.com","123"));
    iu->iniciarSesion();
    iifp->iniciarSesion();
    iifp->seleccionarVideojuego("Minecraft");
    iifp->setTipo(true); // true == individual ; false == multijugador.
    iifp->confirmarPartida();
    iifp->clearCache();

    //PARTIDAS MULTIJUGADOR

    fechaSistema::fecha = DtFechaHora(2021,6,5,17,0); // DtFechaHora(anio, mes, dia, hora, min).
    iu->ingresarUsuario(DtUsuario("gamer@mail.com","123"));
    iu->iniciarSesion();
    iifp->iniciarSesion();
    iifp->seleccionarVideojuego("Fortnite");
    iifp->setTipo(false); // true == individual ; false == multijugador.
    iifp->setEnVivo(true);
    iifp->aniadirJugadorPartida("ari");
    iifp->aniadirJugadorPartida("ibai");
    iifp->confirmarPartida();
    iifp->clearCache();

    fechaSistema::fecha = DtFechaHora(2021,6,5,17,0); // DtFechaHora(anio, mes, dia, hora, min).
    iu->ingresarUsuario(DtUsuario("gamer@mail.com","123"));
    iu->iniciarSesion();
    iifp->iniciarSesion();
    iifp->seleccionarVideojuego("Fortnite");
    iifp->setTipo(false); // true == individual ; false == multijugador.
    iifp->setEnVivo(true);
    iifp->aniadirJugadorPartida("ari");
    iifp->aniadirJugadorPartida("ibai");
    iifp->confirmarPartida();
    iifp->clearCache();

    fechaSistema::fecha = DtFechaHora(2021,6,12,20,0); // DtFechaHora(anio, mes, dia, hora, min).
    iu->ingresarUsuario(DtUsuario("ari@mail.com","123"));
    iu->iniciarSesion();
    iifp->iniciarSesion();
    iifp->seleccionarVideojuego("Minecraft");
    iifp->setTipo(false); // true == individual ; false == multijugador.
    iifp->setEnVivo(false);
    iifp->aniadirJugadorPartida("ibai");
    iifp->confirmarPartida();
    iifp->clearCache();

    //ABANDONA PARTIDA MULTIJUGADOR
    
    fechaSistema::fecha = DtFechaHora(2021,6,5,18,0); // DtFechaHora(anio, mes, dia, hora, min).
    iu->ingresarUsuario(DtUsuario("ari@mail.com","123"));
    iu->iniciarSesion();
    iifp->iniciarSesion();
    iifp->confirmarAbandonarPartida(iifp->getIdSisActual()-2);
    iifp->clearCache();

    fechaSistema::fecha = DtFechaHora(2021,6,6,17,30); // DtFechaHora(anio, mes, dia, hora, min).
    iu->ingresarUsuario(DtUsuario("ari@mail.com","123"));
    iu->iniciarSesion();
    iifp->iniciarSesion();
    iifp->confirmarAbandonarPartida(iifp->getIdSisActual()-1);
    iifp->clearCache();

    //FINALIZAR PARTIDA MULTI

    fechaSistema::fecha = DtFechaHora(2021,6,5,19,0);
    iu->ingresarUsuario(DtUsuario("gamer@mail.com","123"));
    iu->iniciarSesion();
    iifp->iniciarSesion();
    iifp->confirmarFinalizarPartida(iifp->getIdSisActual() - 2);
    iifp->clearCache();

    fechaSistema::fecha = DtFechaHora(2021,6,6,19,0);
    iu->ingresarUsuario(DtUsuario("gamer@mail.com","123"));
    iu->iniciarSesion();
    iifp->iniciarSesion();
    iifp->confirmarFinalizarPartida(iifp->getIdSisActual() - 1);
    iifp->clearCache();
    
    //Aqui se realizan la secuencia de operaciones para generar el estado predefinido del sistema
    //solicitado
    cout << "Se han cargado todos los datos de prueba exitosamente.\n";
    pkey();
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
    IUsuario->clearCache();
    pkey();
    return 0;
}

int Sistema::iniciarSesion(){
    LaFabrica * f = LaFabrica::getInstance();
    IAltaUsuarioController * h = f->getIAltaUsuarioController();
    string u,p;
    int user_ok = 2;
    if (h->hayUsuarios()) {
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
		reprintln();
		reprintln();
		reprintln();
                cout << "ERROR: La contrasenia ingresada no es correcta.\n";
            }    
            if(user_ok == 0 || user_ok == 1){
                cout << "Inicio de sesion exitoso. Bienvenido " << u << ".\n";
            }
        }
    } else {
        cout << "ERROR: No hay usuarios registrados en el sistema.\n";
    }
    pkey();
    h->clearCache();
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
    cout << "\nEl sistema cuenta con las siguientes categorias:\n";
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
	cout << endl << endl;
	if (t=="Genero"||t=="genero"){
	    tcat = TipoCategoria::Genero;
	    t = "Genero";
	}
	else if (t=="Plataforma"||t=="plataforma"){
	    tcat = TipoCategoria::Plataforma;
	    t = "Plataforma";
	}
	else if (t=="Otro"||t=="otro"){
	    tcat = TipoCategoria::Otro;
	    t = "Otro";
	}
	else{
	    tcat = TipoCategoria::Otro;
	    cout << "Advertencia: El tipo categoria \""<<t<<"\" no existe como tal en el sistema. Se le ha asignado el tipo \"Otro\".\n";   
	    t = "Otro";
	}	
	cout << "La siguiente categoria sera agregada al sistema:\n\n";
	cout << "Nombre: "<<n<<endl;
	cout << "Descripcion: "<<d<<endl;
	cout << "Tipo: "<<t<<endl<<endl;
	cout << "Desea confirmar su creacion? (y/n) ";
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
    LaFabrica* factory = LaFabrica::getInstance();
    IVideojuegoController* interface = factory->getIVideojuegoController();
    if (interface->hayCategorias()) {
        string nombreVj;
        string descripcion;
        set<string>* catAgregadas = new set<string>; 
        cout << "Ingrese los siguientes datos del videojuego a publicar:\n";
        cout << "Nombre: ";
        while (true) {
            getline(cin, nombreVj);
            if (interface->existeVideojuego(nombreVj)) {
                reprintln();
                cout << "Este nombre ya esta registrado en el sistema, porfavor ingrese otro: ";
            } else {
                break;
            }
        }
        cout << "Descripcion: ";
        getline(cin, descripcion);
        cout << "Ingrese los precios de las suscripciones:\n";
        cout << "Mensual: ";
        float mensual;
        while (true) {
            if (!(cin >> mensual)) {
            clinput();
            reprintln();
                cout << "Porfavor, ingrese un precio razonable: ";
            } else {
                break;
            }
        }
        clinput();
        float trimestral;
        cout << "Trimestral: ";
        while (true) {
            if (!(cin >> trimestral)) {
            clinput();
                reprintln();
                cout << "Porfavor, ingrese un precio correcto: ";
            } else {
                break;
            }
        }
        clinput();
        float anual;
        cout << "Anual: ";
        while (true) {
            if (!(cin >> anual)) {
            clinput();
                reprintln();
                cout << "Porfavor, ingrese un precio interpretable: ";
            } else {
                break;
            }
        }
        clinput();
        float vitalicia;
        cout << "Vitalicia: ";
        while (true) {
            if (!(cin >> vitalicia)) {
            clinput();
                reprintln();
                cout << "Porfavor, ingrese un precio distinguible: ";
            } else {
                break;
            }
        }
        clinput();
        DtVideojuego nuevoVj(nombreVj, descripcion, mensual, trimestral, anual, vitalicia);
        interface->ingresarDatosVideojuego(nuevoVj);
        string catAgregar;    
        bool exCat = false;
        set<DtCategoria>* generos = interface->obtenerCategoriasGenero();
        cout << "\nGeneros presentes en el sistema: \n\n";
        for (set<DtCategoria>::iterator it = generos->begin(); it != generos->end(); ++it) {
            cout << *it << "\n";
        }
        cout << "Ingrese un genero a agregar (Debe seleccionar al menos uno): ";
        getline(cin, catAgregar);
        int cc=0;
        while ( (cc == 0) || (catAgregar != "")) {
        exCat=false;
            for (set<DtCategoria>::iterator it = generos->begin(); it != generos->end() && exCat==false; ++it) {
                if (catAgregar == it->getNombre()) 
                    exCat = true;
            }
            if(exCat){
                interface->seleccionarGenero(catAgregar);
                catAgregadas->insert(catAgregar);
            cc++;
            cout << "Ingrese un nuevo genero (Presione ENTER si no desea agregar mas): ";
            } else {
            reprintln();
                cout << "Por favor ingrese un genero perteneciente a la lista: ";
            }
            getline(cin, catAgregar);
        }
        delete generos;
        set<DtCategoria>* plataformas = interface->obtenerCategoriasPlataforma();
        cout << "\nPlataformas presentes en el sistema: \n\n";
        for (set<DtCategoria>::iterator it = plataformas->begin(); it != plataformas->end(); ++it) {
            cout << *it << "\n";
        }
        cout << "Ingrese una plataforma a agregar (debe seleccionar al menos una): ";
        getline(cin, catAgregar);
        cc = 0;
        while ( cc == 0 || (catAgregar != "")) {
        exCat=false;
            for (set<DtCategoria>::iterator it = plataformas->begin(); it != plataformas->end(); ++it) {
                if (catAgregar == it->getNombre()) {
                    exCat = true;
                    break;
                }
            }
            if (exCat) {
                interface->seleccionarPlataforma(catAgregar);
                catAgregadas->insert(catAgregar);
            cc++;
            cout << "Ingrese una nueva plataforma (Presione ENTER si no desea agregar mas): ";
            } else {
            reprintln();
                cout << "Por favor ingrese una plataforma perteneciente a la lista: ";
            }
            getline(cin, catAgregar);
        }
        delete plataformas;
        set<DtCategoria>* categorias = interface->obtenerCategoriasOtro();
        cout << "Categorias presentes en el sistema: \n";
        for (set<DtCategoria>::iterator it = categorias->begin(); it != categorias->end(); ++it) {
            cout << *it << "\n";
        }
        cout << "Ingrese una categoria (Presione ENTER si no desea agregar mas): ";
        getline(cin, catAgregar);
        while (catAgregar != "") {
        exCat = false;
            for (set<DtCategoria>::iterator it = categorias->begin(); it != categorias->end(); ++it) {
                if (catAgregar == it->getNombre()) {
                    exCat = true;
                    break;
                }
            }
            if (exCat) {
                interface->seleccionarCategoriaOtro(catAgregar);
                catAgregadas->insert(catAgregar);
            cout << "Ingrese una nueva categoria (Presione ENTER si no desea agregar mas): ";
            } else {
            reprintln();
                cout << "Por favor ingrese una categoria perteneciente a la lista: ";
            }
            getline(cin, catAgregar);
        }
        delete categorias;
        cls();
        ptitle();
        cout << "\n\nLos datos ingresados del videojuego a publicar son: \n\n";
        cout << nuevoVj << "\n";
        cout << "Los generos, plataformas y demas categorias ingresadas son: \n";
        for (set<string>::iterator it = catAgregadas->begin(); it != catAgregadas->end(); ++it) {
            cout << "\t" << *it << ".\n";
        }
        delete catAgregadas;
        cout << "\nConfirma la publicacion del videojuego? (1. Si, 2. No)";
        string confirmar;
        while (true) {
            getline(cin, confirmar);
            reprintln();
            if ((confirmar == "1") || (confirmar == "Si") || (confirmar == "si") || (confirmar == "2") 
                    || (confirmar == "No") || (confirmar == "no") || (confirmar == "yes") || (confirmar == "y") || (confirmar == "n")) {
                break;
            } else {
                cout << "Porfavor, ingrese una opcion valida: ";
            }
        }
        if ((confirmar == "1") || (confirmar == "Si") || (confirmar == "si") || (confirmar == "yes") || (confirmar == "y")){
            interface->confirmarPublicacion();
            cout << "El videojuego se ha publicado en el sistema de manera exitosa. \n";
        } else {
            cout << "Se ha cancelado la operacion de publicar videojuego.\n";
        }
        interface->clearCache();
    } else {
        cout << "ERROR: No existen plataformas y/o generos registrados en el sistema.\n";
    }
    pkey();
    return 0;
}

int Sistema::eliminarVideojuego(){
    LaFabrica* laFabrica = LaFabrica::getInstance();
	IVideojuegoController* iVideojuego = laFabrica->getIVideojuegoController();
	set<string>* vjInactivos = iVideojuego->obtenerNombreVideojuegosInactivos();
    if (!(vjInactivos->empty())) {
        cout << "Videojuegos publicados:\n";
        for (set<string>::iterator it = vjInactivos->begin(); it != vjInactivos->end(); it++) {
            cout << "\t" << *it << "\n";
        }
        string vjEliminar;
        cout << endl << "Ingrese el nombre del videojuego a eliminar: ";
        bool existeVj = false;
        while(!existeVj){
            getline(cin,vjEliminar);
            for(set<string>::iterator it = vjInactivos->begin(); ((it!=vjInactivos->end()) && (!existeVj)); ++it) {
                if(*it == vjEliminar)
                    existeVj = true;
                else {
                    reprintln();
                    cout << "\nPor favor ingrese un videojuego listado: ";
                }
            }
        }
        cout << "\nConfirma la eliminacion del videojuego? (1. Si, 2. No)";
        iVideojuego->seleccionarVideojuego(vjEliminar);
        string confirmar;
        while (true) {
            getline(cin, confirmar);
            reprintln();
            if ((confirmar == "1") || (confirmar == "Si") || (confirmar == "si") || (confirmar == "2") 
                    || (confirmar == "No") || (confirmar == "no") || (confirmar == "yes") || (confirmar == "y") || (confirmar == "n")) {
                break;
            } else {
                cout << "Porfavor, ingrese una opcion valida: ";
            }
        }
        if ((confirmar == "1") || (confirmar == "Si") || (confirmar == "si") || (confirmar == "yes") || (confirmar == "y")){
            iVideojuego->confirmarEliminarVideojuego();
            cout << "El videojuego '" << vjEliminar << "' se ha eliminado del sistema de manera exitosa. \n";
        } else {
            cout << "Se ha cancelado la operacion de eliminar videojuego.\n";
        }
        iVideojuego->clearCache();
    } else {
        cout << "ERROR: No hay videojuegos disponibles para borrar o aun presentan partidas activas.\n";
    }
    delete vjInactivos;
    pkey();
    return 0;
}

int Sistema::seleccionarEstadistica(){
    //Listar nombre y descripcion de cada estadistica presente en el sistema
    HandlerEstadistica * hEstadistica = HandlerEstadistica::getInstance();
    map<string,Estadistica*>* estadisticas = hEstadistica->getEstadistica();
    for (map<string,Estadistica*>::iterator it = estadisticas->begin(); it != estadisticas->end(); ++it) {
        cout << "Nombre: " << it->second->getNombre() << endl;
        cout << "Descripcion: " << it->second->getDescripcion() << endl << endl;
    }
    //Desarrollador ingresa los nombres de las que esta interesado
    HandlerUsuario * hUsuario = HandlerUsuario::getInstance();
    Usuario * user = hUsuario->getLoggedUser();
    Desarrollador * des = dynamic_cast<Desarrollador*>(user);
    cout << "Ingrese los nombres de las estadisticas que quiere (0. Para no seleccionar ninguna) : " << endl << endl;
    bool loopControl = 1;
    int i = 1;
    while (loopControl != 0) {
        string nombreEstadistica;
        cout << "Nombre estadistica "<< i <<": ";
        cin >> nombreEstadistica;
        cout << endl;
        if (hEstadistica->findEstadistica(nombreEstadistica) != NULL) {
            des->add(hEstadistica->findEstadistica(nombreEstadistica));
            i++;
        } else {
            cout << "ERROR: Ingrese un nombre de estadistica valido porfavor" << endl << endl; 
        }
        cout << "Desea seleccionar otra estadistica? (1.Si/0.No): ";
        cin >> loopControl;
        cout << endl;
    }
    //Entre las estadísticas que estarán disponibles se encuentra una para obtener la cantidad total de horas jugadas de un videojuego, y otra para obtener la cantidad total de   jugadores que se han suscrito a cierto videojuego.
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
    LaFabrica* factory = LaFabrica::getInstance();
    IVideojuegoController* interface = factory->getIVideojuegoController();
	set<DtVideojuego>* videojuegosSistema = interface->verVideojuegos();
    cout << "El sistema cuenta con el siguiente catalogo de videojuegos:\n";
	for (set<DtVideojuego>::iterator it = videojuegosSistema->begin(); it != videojuegosSistema->end(); it++) {
		cout << "\t" << it->getNombre() << endl;
	}
    cout << "\nIngrese el nombre del videojuego al que desea ver su informacion: ";
    bool existeVj = false;
    string nombreVj;
    while(!existeVj){
	    getline(cin,nombreVj);
	    for(set<DtVideojuego>::iterator it = videojuegosSistema->begin(); ((it!=videojuegosSistema->end()) && (!existeVj)); ++it) {
	        if(it->getNombre() == nombreVj)
		        existeVj = true;
	        else {
	            reprintln();
	            cout << "Por favor ingrese una opcion valida: ";
            }
        }
    }
    delete videojuegosSistema;
    interface->seleccionarVideojuego(nombreVj);
    cls();
    ptitle();
    cout << "\n\nInformacion del videojuego " << nombreVj << "\n";
    interface->obtenerInfoVideojuego();
    interface->clearCache();
    pkey();
    return 0;
}

int Sistema::suscribirseVideojuego(){
    LaFabrica *laFabrica = LaFabrica::getInstance();
    IVideojuegoController *IVid = laFabrica->getIVideojuegoController();
    vector<set<DtVideojuego>> * vj = IVid->obtenerSuscripcionesVideojuegos();
    cout << "Seleccione el juego al que desea contratar una suscripcion o, teniendo una suscripcion activa, desea desuscribirse.\n\n";
    if((*vj)[0].size() == 0)
	cout << "Usted no cuenta con ninguna suscripion activa de ningun videojuego.\n";
    else
	cout << "Usted tiene suscripciones activas de los siguientes videojuegos:\n";
    int i = 1;
    for(set<DtVideojuego>::iterator it = (*vj)[0].begin(); it != (*vj)[0].end(); ++it,++i){
	cout << i << ". " << it->getNombre() << endl;
	cout << it->getDtPrecios();
	TipoValido tipo = IVid->getSuscripcion(it->getNombre()).getTipo();
	cout << "Periodo de suscripcion: ";
	if (tipo == TipoValido::UnMes)
	    cout << "Un mes.\n";
	if (tipo == TipoValido::TresMeses)
	    cout << "Tres meses.\n";
	if (tipo == TipoValido::Anio)
	    cout << "Un anio.\n";
	if (tipo == TipoValido::Vitalicia)
	    cout << "Vitalicia.\n";
	cout << "Fecha de compra: " << IVid->getSuscripcion(it->getNombre()).getFecha() << endl;
	cout << endl;
    }
    if((*vj)[1].size() == 0)
	cout << "No hay ningun videojuego al que pueda suscribirse en este momento.\n";
    else
	cout << "Usted no tiene suscripciones activas para los siguientes videojuegos:\n";
    i = 1;
    for(set<DtVideojuego>::iterator it = (*vj)[1].begin(); it != (*vj)[1].end(); ++it,++i){
	cout << i << ". " << it->getNombre() << endl;
        cout << it->getDtPrecios();
    }

    cout << "\nIngrese el nombre del videojuego (presione ENTER para salir): ";
    string vjSus;
    int vjSel = 0; 
    while(!vjSel){
	getline(cin,vjSus);
	if(vjSus == ""){
	    cout << "Se ha cancelado la operacion Suscribirse a videojuego.\n";
	    delete vj;
	    pkey();
	    return 0;
	}
	for(set<DtVideojuego>::iterator it = (*vj)[0].begin(); it != (*vj)[0].end() && !vjSel; ++it)
	    if(it->getNombre() == vjSus){
		if(IVid->getSuscripcion(it->getNombre()).getTipo() == TipoValido::Vitalicia)
		    vjSel=3;
		else
		    vjSel = 1;
	    }
	for(set<DtVideojuego>::iterator it = (*vj)[1].begin(); it != (*vj)[1].end() && !vjSel; ++it)
	    if(it->getNombre() == vjSus)
		vjSel = 2;
	if(!vjSel){
	    reprintln();
	    cout << "Por favor ingrese un videojuego valido: ";
	}
	if(vjSel==3){
	    reprintln();
	    cout << "Error: Usted cuenta con una suscripccion vitalicia para el videojuego seleccionado, por lo que no es posible desuscribirse.\n";
	    delete vj;
	    pkey();
	    return 0;
	}
    } 
    IVid->seleccionarVideojuego(vjSus);
    delete vj;

    if(vjSel==2){ //Suscripcion inactiva
	cout <<"\nTipos de suscripcion disponibles: "<<endl; 
	cout <<"1. 1 mes"<< endl;
	cout <<"2. 3 meses"<< endl;
	cout <<"3. 1 año"<< endl;
	cout <<"4. vitalicia"<< endl;
	cout <<"Por favor seleccione el tipo de suscripcion que desea adquirir: "; 
	TipoValido sus;
	int ts = takeInputRange(1,4);
	if(ts==1)
	    sus = TipoValido::UnMes;
	if(ts==2)
	    sus = TipoValido::TresMeses;
	if(ts==3)
	    sus = TipoValido::Anio;
	if(ts==4)
	    sus = TipoValido::Vitalicia;

	cout <<"Metodos de pago disponibles: "<< endl;
	cout << "1. PayPal\n";
	cout << "2. Tarjeta\n";
	cout <<"Por favor seleccione un metodo de pago: ";
	TipoPago pago;
	int var = takeInputRange(1,2);
	if(var==1)
	    pago = TipoPago::Paypal;
	if(var==2)
	    pago = TipoPago::Tarjeta;
	IVid->ingresarSuscripcion(sus, pago);
	DtSuscripcion info(fechaSistema::fecha,pago,sus,TipoEstado::Activa);
	cout << "Detalles de compra: \n";
	cout << "Videojuego: " << vjSus << endl;
	cout << info;
	reprintln();
	cout << " \n";
	cout <<"Desea confirmar su compra (y/n)? ";
	bool f = boolSelect();
	if(f){
	    IVid->confirmarSuscripcion();
	    cout << "Se ha realizado la compra exitosamente. Gracias por utilizar STEAM v3.0\n";
	}
	else
	    cout << "Se ha cancelado la compra.\n";
    }
    else{ //Suscripcion Activa temporal
	DtSuscripcion old = IVid->getSuscripcion(vjSus);
	cout << "\nInformacion suscripcion del videojuego " << vjSus <<":\n";
	cout << old;
	cout <<"¿Desea cancelar su suscricpion (y/n) ? ";
	bool f = boolSelect();
	if(f){
	    IVid->cancelarSuscripcion();
	    cout << "Se ha cancelado su suscripcion exitosamente.\n";
	}
	else
	    cout << "Se ha cancelado la operacion para desuscribrise.\n";
    }
    pkey();
    return 0;
}

int Sistema::asignarPuntajeVideojuego(){
    int i=0;
    bool nok=false;
    string p;
    int kp;

    LaFabrica * f = LaFabrica::getInstance();
    IVideojuegoController * h = f->getIVideojuegoController();
    cout << "El sistema cuenta con el siguiente catalogo de videojuegos:\n\n";
    set<DtVideojuego>* namae = h->verVideojuegos();
    for(set<DtVideojuego>::iterator it = namae->begin(); it != namae->end(); i++,it++){
	cout << i << ". Nombre: " << it->getNombre() << "\n";
	for(int j=0;j<i/10;j++)
	    cout << " ";
	cout << "\tDescripcion: " << it->getDescripcion() << "\n\n"; 
    }
    cout << "Ingrese el nombre del videojuego que desea puntuar: ";
    while(!nok){
	    getline(cin,p);
	    for(set<DtVideojuego>::iterator it = namae->begin(); it!=namae->end() && !nok; ++it)
	        if(it->getNombre() == p)
		        nok = true;
	    if(!nok){
	        reprintln();
	        cout << "Por favor ingrese una opcion valida: ";
        }
    }	
    cout << "Ingrese su puntuacion para el videojuego \""<<p<<"\" (1-5): ";
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
    string confirmar = "2";
    set<string>* jIngresados = new set<string>;
    LaFabrica* factory = LaFabrica::getInstance();
    IIFPController* interface = factory->getIIFPController();
    interface->iniciarSesion();
    set<string>* vjActivos = interface->obtenerVideojuegosActivos();
    if (!(vjActivos->empty())) {
        cout << "Videojuegos con suscripcion activa: \n";
        for (set<string>::iterator it = vjActivos->begin(); it != vjActivos->end(); ++it) {
            cout << "\t" << *it << "\n";
        }
        cout << "\nIngrese el nombre de un videojuego de la lista: ";
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
        interface->seleccionarVideojuego(nombreVj);
        cout << "Tipo de Partida a iniciar (1. Individual, 2. Multijugador): ";
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
            interface->setTipo(true);
            cout << "Su Partida es continuacion de una Partida anterior? (1. Si, 2. No): ";
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
                vector<DtPartidaIndividual*>* pAnteriores = interface->obtenerHistorialPartidas();
                if (!(pAnteriores->empty())) {
                    cout << "Partidas anteriores: \n";
                    for (vector<DtPartidaIndividual*>::iterator it = pAnteriores->begin(); it != pAnteriores->end(); ++it) {
                        cout << *(*it);
                    }
                    cout << "Ingrese el Id de la partida a continuar: \n";
                    while (true) {
                        if (!(cin >> idAnterior)) {
                            clinput();
                            cout << "Porfavor, ingrese un Id correcto: ";
                        } else {
                            clinput();
                            bool exId = false;
                            for (vector<DtPartidaIndividual*>::iterator it = pAnteriores->begin(); it != pAnteriores->end(); ++it) {
                                if ((*it)->getId() == idAnterior) {
                                    exId = true;
                                    break;
                                }
                                cout << *(*it);
                            }
                            if (!exId) {
                                reprintln();
                                cout << "Porfavor, ingrese un Id correcto: ";
                            } else {
                                break;
                            }
                        }
                    }
                    interface->seleccionarContinuacionPartida(idAnterior);
                    for (vector<DtPartidaIndividual*>::iterator it = pAnteriores->begin(); it != pAnteriores->end(); ++it) {
                        delete *it;
                    }
                } else {
                    cout << "\nERROR: Usted no tiene partidas finalizadas. Su partida no sera continuacion de otra.\n";
                }
                delete pAnteriores;
            }
        } else {
            tipoPartida = "Multijugador";
            interface->setTipo(false);
            cout << "Su Partida se transmitira en vivo? (1. Si, 2. No): ";
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
            set<string>* jugadoresSus = interface->obtenerJugadoresSubscriptos();
            if (!(jugadoresSus->empty())) {
                cout << "Los Jugadores con suscripciones activas actualmente son: \n";
                for (set<string>::iterator it = jugadoresSus->begin(); it != jugadoresSus->end(); ++it) {
                    cout << "\t" << *it << "\n";
                }
                cout << "\nIngrese los nicknames de los jugadores que se unen a su partida. Para finalizar presione ENTER: ";
                string nick;
                getline(cin, nick);
                while (nick != "") {
                    if (jugadoresSus->find(nick) == jugadoresSus->end()) {
                        reprintln();
                        cout << "Porfavor, ingrese un nickname valido. Presione ENTER para finalizar: ";
                    } else {
                        jIngresados->insert(nick);
                        interface->aniadirJugadorPartida(nick);
                        cout << "Jugador unido con exito. Ingrese otro o presione ENTER para finalizar: ";
                    }
                    getline(cin, nick);
                }
            } else {
                cout << "\nERROR: No hay jugadores que puedan unirse en el sistema. La partida se iniciara sin jugadores unidos.\n";
            }
            delete jugadoresSus;
        }
        cout << "\nLos datos ingresados de la partida a Iniciar son: \n";
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
            if (!(jIngresados->empty())) {
                cout << "  Los jugadores unidos son: \n";
                for (set<string>::iterator it = jIngresados->begin(); it != jIngresados->end(); ++it) {
                    cout << "    " << *it << "\n";
                }
            } else {
                cout << "  No hay jugadores unidos.\n";
            }
        }
        cout << "\n Confirma el Alta de la Partida? (1. Si, 2. No): ";
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
    } else {
        cout << "\nERROR: Usted no presenta una suscripcion activa a ningun videojuego.";
    }
    delete jIngresados;
    delete vjActivos;
    if ((confirmar == "1") || (confirmar == "Si") || (confirmar == "si")) {
        interface->confirmarPartida();
        cout << "\nLa partida se ha dado de alta exitosamente. \n";
    } else {
        cout << "\nSe ha cancelado el inicio de partida.\n";
    }
    interface->clearCache();
    pkey();
    return 0;
}

int Sistema::abandonarPartidaMultijugador(){
    LaFabrica* factory = LaFabrica::getInstance();
    IIFPController* interface = factory->getIIFPController();
    interface->iniciarSesion();
    map<int, string>* multiActivas = interface->obtenerPartidasMultiActivas();
    int id = -1;
    if (!(multiActivas->empty())) {
        cout << "Partidas multijugador unido: \n\n";
        for (map<int, string>::iterator it = multiActivas->begin(); it != multiActivas->end(); ++it) {
            cout << it->second << "\n";
        }
        cout << "Ingrese la Id de la partida multijugador a abandonar (ingrese '-1' si desea cancelar): \n";
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
                if (multiActivas->find(id) == multiActivas->end()) {
                    reprintln();
                    cout << "Porfavor, ingrese un Id correcto (ingrese '-1' si desea cancelar): ";
                } else {
                    break;
                }
            }
        }
    } else {
        cout << "\nERROR: Usted no esta unido a ninguna partida.";
    }
    delete multiActivas;
    if (id != -1) {
        interface->confirmarAbandonarPartida(id);
        cout << "\nSe ha abandonado la partida multijugador (ID: " << id << ") correctamente.\n";
    } else {
        cout << "\nSe ha cancelado el abandono de la partida multijugador.\n";
    }
    interface->clearCache();
    pkey();
    return 0;
}

int Sistema::finalizarPartida(){
    LaFabrica* factory = LaFabrica::getInstance();
    IIFPController* interface = factory->getIIFPController();
    interface->iniciarSesion();
    map<int, std::string>* partidasActivas = interface->obtenerPartidasActivas();
    if (!(partidasActivas->empty())) {
        cout << "Partidas actualmente activas: \n";
        for (map<int, std::string>::iterator it = partidasActivas->begin(); it != partidasActivas->end(); ++it) {
            cout << it->second;
        }
        cout << "\nIngrese la Id de la partida a finalizar (ingrese '-1' si desea cancelar): ";
        int id;
        while (true) {
            if (!(cin >> id)) {
                clinput();
                reprintln();
                cout << "Porfavor, ingrese un Id correcto (ingrese '-1' si desea cancelar): ";
            } else {
                clinput();
                if ((partidasActivas->find(id) == partidasActivas->end())) {
                    reprintln();
                    cout << "Porfavor, ingrese un Id correcto (ingrese '-1' si desea cancelar): ";
                } else {
                    break;
                }
            }
        }
        if (id != -1) {
            interface->confirmarFinalizarPartida(id);
            cout << "Se ha finalizado la partida (ID: " << id << ") correctamente.";
        } else {
            cout << "No se ha finalizado la partida.";
        }
    } else {
        cout << "\nERROR: Usted no tiene partidas activas.\n";
    }
    delete partidasActivas;
    interface->clearCache();
    pkey();
    return 0;
}

string Sistema::getLoggedUserEmail(){
    LaFabrica * laFabrica = LaFabrica::getInstance();
    IAltaUsuarioController * IUsuario = laFabrica->getIAltaUsuarioController();
    return IUsuario->getLoggedName();
}

Sistema::~Sistema(){
//Hago las cosas pertinentes para cerrar el sistema... (se libera memoria)
}
