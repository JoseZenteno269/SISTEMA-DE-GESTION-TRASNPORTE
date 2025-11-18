#include<iostream>
#include "PASAJEROS.h"
#include "rlutil.h"
using namespace rlutil;

using namespace std;

void Pasajeros::setnumero_pasaje(int np){numero_pasaje=np; }
void Pasajeros::sethabilitado(bool h){habilitado=h; }

int Pasajeros::getnumero_pasaje(){return numero_pasaje; }
bool Pasajeros::gethabilitado(){return habilitado; }

void Pasajeros::cargar(int np){
    numero_pasaje = np;

    setColor(YELLOW);
    locate(40, 3); cout << "==========================================";
    locate(40, 4); cout << "           REGISTRO DEL PASAJERO          ";
    locate(40, 5); cout << "==========================================";
    setColor(WHITE);

    locate(40, 7); cout << "Numero de pasaje: " << numero_pasaje;

    Personas::cargar();
    habilitado = true;
}

void Pasajeros::mostrar(){
    setColor(YELLOW);
    locate(40, 3);  cout << "==========================================";
    locate(40, 4);  cout << "            INFORMACION DEL PASAJERO       ";
    locate(40, 5);  cout << "==========================================";
    setColor(WHITE);

    locate(40, 7); cout << "Numero de pasaje:       " << numero_pasaje;

    Personas::mostrar(8);


}
