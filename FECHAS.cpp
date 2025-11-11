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

int Fechas::getdia() const { return dia; }
int Fechas::getmes() const { return mes; }
int Fechas::getanio() const { return anio; }

void Fechas::cargar(){

    int diasMes[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    while(true){
        cout<<"Año: ";
        cin>>anio;
        if(anio<1900 or anio>2100 or cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }else break;
    }

    if(esBisiesto(anio)){
        diasMes[1]=29;
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

    while(true){
        cout<<"Día: ";
        cin>>dia;
        if(dia<1 or dia>diasMes[mes-1] or cin.fail()){
            cin.clear();
            cin.ignore(1000,'\n');
            continue;
        }else break;
    }

}

void Fechas::mostrar(){
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}
