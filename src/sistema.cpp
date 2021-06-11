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
   cout<< "Ingrese su mail y contraseña: "<< endl;
   cin >> mail;
   cin >> pass;
   DtUsuario datos(mail, pass);
   IUsuario->ingresarUsuario(datos);

   cout<<"Seleccione que tipo de usuario desea iniciar"<< endl;
   cout << " 1. Jugador" << endl;
   cout << " 2. Desarrollador" << endl;

   int controlVar = takeInputRange(1,2);
      switch (controlVar) {
	     case 1: {
	        string name;
            cin >> name;
            HandlerUsuario * hc = HandlerUsuario::getInstance();
            while (hc->existeUsuario(name)){
               cout << "Ese nickname ya está en uso, por favor ingrese otro. " << endl;
               cin >> name;
            }
            IUsuario->ingresarNickname(name);
            string des;
            IUsuario->ingresarDescripcion(des);
            break;
	    }
	     case 2: {
            string emp;
            cout << "Ingrese el nombre de su empresa: " << endl;
            cin >> emp;
            IUsuario->ingresarEmpresa(emp);
	        break;
	     }
   }
   IUsuario->confirmarDarDeAltaUsuario();	
   return 0;
}
int Sistema::iniciarSesion(){
    LaFabrica * f = LaFabrica::getInstance();
    IAltaUsuarioController * h = f->getIAltaUsuarioController();
    string u,p;
    int user_ok = 1;
    cout << "Ingrese los siguientes datos para iniciar sesion.\nSi desea cancelar la operacion presione ENTER dos veces.\n\n\n";
    while(user_ok){
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
    for(set<string>::iterator it = namae->begin(); it != namae->end(); it++)
	cout << "\t" << i << ". " << *(it) << "\n";
    delete namae;
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
    return 0;
}

int Sistema::iniciarPartida(){
    return 0;
}

int Sistema::abandonarPartidaMultijugador(){
    return 0;
}

int Sistema::finalizarPartida(){
    return 0;
}

string Sistema::getLoggedUserEmail(){
    return "lol";
}

Sistema::~Sistema(){
//Hago las cosas pertinentes para cerrar el sistema... (se libera memoria)
}


