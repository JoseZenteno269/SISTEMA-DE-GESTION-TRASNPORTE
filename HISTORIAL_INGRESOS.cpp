#include<iostream>
#include<cstring>
#include "HISTORIAL_INGRESOS.h"

using namespace std;

void Historial_ingreso::setidusuario(int idu){idusuario=idu;}
void Historial_ingreso::setingreso_sesion(Fechas is){ingreso_sesion=is; }
void Historial_ingreso::setinicio(Hora i){inicio=i; }
void Historial_ingreso::setnombre_usuario(const char *nu){strcpy(nombre_usuario,nu); }

int Historial_ingreso::getidusuario(){return idusuario; }
Fechas Historial_ingreso::getingreso_sesion(){return ingreso_sesion; }
Hora Historial_ingreso::getinicio(){return inicio; }
const char *Historial_ingreso::getnombre_usuario(){return nombre_usuario; }

void Historial_ingreso::mostrar(){
    cout<<"=============================="<<endl;
    cout<<"ID de usuario: "<<idusuario<<endl;
    cout<<"Nombre: "<<nombre_usuario<<endl;
    cout<<"Fecha:"<<endl;
    ingreso_sesion.mostrar();
    cout<<"Hora de ingreso: ";
    inicio.mostrar();
    cout<<"=============================="<<endl;
}
