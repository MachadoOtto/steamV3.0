#include "include/sistema.h"
#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
    Sistema sys;
    sys.agregarJugador("roberto",40,"lol");
    int c= 0;
    DtJugador ** d = sys.obtenerJugadores(c);
    for(int i=0; i<c;i++){
	cout << "Nombre: " << d[i]->getNickname() << '\n';	
    }
    cout << "totJugadores: " << c << '\n';
    return 0;
}
