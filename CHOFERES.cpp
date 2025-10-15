#include<iostream>
#include "CHOFERES.h"
#include "funciones.h"
#include<cstring>

using namespace std;


void Choferes::setlegajo(int l){legajo=l; }
void Choferes::setidMicro(int idm){idMicro=idm; }
void Choferes::setestado(bool e){estado=e; }
void Choferes::setfecha_de_ingreso(Fechas f){fecha_de_ingreso=f; }

int Choferes::getlegajo(){return legajo; }
int Choferes::getidMicro(){return idMicro; }
bool Choferes::getestado(){return estado; }
Fechas Choferes::getfecha_de_ingreso(){return fecha_de_ingreso; }

void Choferes::cargar(){
    cout<<"ingrese N° de legajo: "; cin>>legajo;
    cout<<"ingrese ID de micro asignado: "; cin>>idMicro;
    Personas::cargar();
    fecha_de_ingreso.cargar();
    estado=true;

}
void Choferes::mostrar(){
    cout<<"N° de legajo: "<<legajo<<endl;
    cout<<"ID de micro: "<<idMicro<<endl;
    Personas::mostrar();
    fecha_de_ingreso.mostrar();
}
