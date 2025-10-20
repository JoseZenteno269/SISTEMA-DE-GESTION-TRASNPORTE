#include<iostream>
#include "MICROS.h"
#include<cstring>
#include "funciones.h"

using namespace std;


void Micros::setidMicro(int idm){idMicro=idm; }
void Micros::setmarca(const char *mrc){strcpy(marca, mrc); }
void Micros::settipo(const char *t){strcpy(tipo, t); }
void Micros::setcapacidad(int c){capacidad=c; }
void Micros::settipoButaca(const char *tb){strcpy(tipoButaca,tb); }
void Micros::setnumero_butaca(int nb){numero_butaca=nb; }
void Micros::setdisponible(bool disp){disponible=disp; }

int Micros::getidMicro(){return idMicro; }
const char *Micros::getmarca(){return marca; }
const char *Micros::gettipo(){return tipo; }
int Micros::getcapacidad(){return capacidad; }
const char *Micros::gettipoButaca(){return tipoButaca; }
int Micros::getnumero_butaca(){return numero_butaca; }
bool Micros::getdisponible(){return disponible; }

void Micros::cargar(int idm){
    cout<<"El ID de Micro: "<<(idMicro=idm)<<endl;
    cout<<"ingrese marca del micro: "; cargarCadena(marca, 29);
    cout<<"ingrese tipo del micro: "; cargarCadena(tipo, 29);
    cout<<"ingrese capacidad: "; cin>>capacidad;
    cout<<"ingrese tipo de butaca: "; cargarCadena(tipoButaca, 29);
    cout<<"ingrese numero de buatca: "; cin>>numero_butaca;
    disponible=true;
}

void Micros::mostrar(){
    cout<<"ID de Micro: "<<idMicro<<endl;
    cout<<"Marca del micro: "<<marca<<endl;
    cout<<"Tipo del micro: "<<tipo<<endl;
    cout<<"Capacidad: "<<capacidad<<endl;
    cout<<"Tipo de Butaca: "<<tipoButaca<<endl;
    cout<<"Numero de Butaca: "<<numero_butaca<<endl;
}
