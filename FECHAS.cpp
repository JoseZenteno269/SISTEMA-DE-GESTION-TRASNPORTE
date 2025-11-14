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
        cout<<"Año: "; cin>>anio;
        if(validar_numero() and (anio>1900 and anio<2100))break;
    }

    while(true){
        cout<<"Mes: "; cin>>mes;
        if(validar_numero() and (mes>=1 and mes<=12))break;
    }

    int diasMes=diasEnMes(mes, anio);

    while(true){
        cout<<"Día: "; cin>>dia;
        if(validar_numero() and (dia>=1 and dia<=diasMes))break;
    }

}

void Fechas::mostrar(){
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}
