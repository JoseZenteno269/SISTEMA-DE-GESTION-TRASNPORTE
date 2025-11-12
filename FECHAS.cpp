#include<iostream>
#include "FECHAS.h"
#include "rlutil.h"
#include "funciones.h"

using namespace std;
using namespace rlutil;

Fechas::Fechas(int d, int m, int a){
    dia=d;
    mes=m;
    anio=a;
}

void Fechas::setdia(int d){dia=d; }
void Fechas::setmes(int m){mes=m; }
void Fechas::setanio(int a){anio=a; }

int Fechas::getdia(){return dia; }
int Fechas::getmes(){return mes; }
int Fechas::getanio(){return anio; }

void Fechas::cargar(){

    while(true){
        cout<<"Año: ";
        cin>>anio;
        if(anio<1900 or anio>2100 or cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }else break;
    }

    while(true){
        cout<<"Mes: ";
        cin>>mes;
        if(mes<1 or mes>12 or cin.fail()){
            cin.clear();
            cin.ignore(1000,'\n');
            continue;
        }else break;
    }

    int diasMes=diasEnMes(mes, anio);

    while(true){
        cout<<"Día: ";
        cin>>dia;
        if(dia<1 or dia>diasMes or cin.fail()){
            cin.clear();
            cin.ignore(1000,'\n');
            continue;
        }else break;
    }

}

void Fechas::mostrar(){
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}
