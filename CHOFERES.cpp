#include<iostream>
#include "CHOFERES.h"
#include "funciones.h"
#include<cstring>

using namespace std;


void Choferes::setlegajo(int l){legajo=l; }
void Choferes::setestado(bool e){estado=e; }
void Choferes::setfecha_de_ingreso(Fechas f){fecha_de_ingreso=f; }

int Choferes::getlegajo(){return legajo; }
bool Choferes::getestado(){return estado; }
Fechas Choferes::getfecha_de_ingreso(){return fecha_de_ingreso; }

void Choferes::cargar(){
    cout<<"ingrese N° de legajo: "; cin>>legajo;
    Personas::cargar();
    fecha_de_ingreso.cargar();
    estado=true;

}
void Choferes::mostrar(){
    cout<<"N° de legajo: "<<legajo<<endl;
    Personas::mostrar();
    fecha_de_ingreso.mostrar();
}
