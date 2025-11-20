#include<iostream>
#include "PASAJEROS.h"
#include "rlutil.h"
using namespace rlutil;

using namespace std;

void Pasajero::setnumero_pasaje(int np){numero_pasaje=np; }
void Pasajero::sethabilitado(bool h){habilitado=h; }

int Pasajero::getnumero_pasaje(){return numero_pasaje; }
bool Pasajero::gethabilitado(){return habilitado; }

void Pasajero::cargar(int np){
    numero_pasaje = np;

    setColor(YELLOW);
    locate(40, 3); cout << "==========================================";
    locate(40, 4); cout << "           REGISTRO DEL PASAJERO          ";
    locate(40, 5); cout << "==========================================";
    setColor(WHITE);

    locate(40, 7); cout << "Numero de pasaje: " << numero_pasaje;

    Persona::cargar();
    habilitado = true;
}

void Pasajero::mostrar(){
    setColor(YELLOW);
    locate(40, 3);  cout << "==========================================";
    locate(40, 4);  cout << "            INFORMACION DEL PASAJERO       ";
    locate(40, 5);  cout << "==========================================";
    setColor(WHITE);

    locate(40, 7); cout << "Numero de pasaje:       " << numero_pasaje;

    Persona::mostrar(8);


}
