#include<iostream>
#include "PASAJEROS.h"

using namespace std;

void Pasajeros::setnumero_pasaje(int np){numero_pasaje=np; }
void Pasajeros::sethabilitado(bool h){habilitado=h; }

int Pasajeros::getnumero_pasaje(){return numero_pasaje; }
bool Pasajeros::gethabilitado(){return habilitado; }

void Pasajeros::cargar(int np){
    cout<<"Numero de pasaje: "<<(numero_pasaje=np)<<endl;
    Personas::cargar();
    habilitado=true;
}
void Pasajeros::mostrar(){
    cout<<"Numero de pasaje: "<<numero_pasaje<<endl;
    Personas::mostrar();
}
