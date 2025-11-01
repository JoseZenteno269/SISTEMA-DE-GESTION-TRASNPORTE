#include<iostream>
#include "FECHAS.h"
#include "rlutil.h"

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
    int D, M, A;
    int diasMes[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    cout<<"Año: ";
    cin>>A;
    while(A<1900 or A>2100 or cin.fail()){
        cin.clear();
        cin.ignore(1000, '\n');
        cout<<"ingrese nuevamente el Año: ";
        cin>>A;
    }
    anio=A;

    if((anio%4==0 && anio%100!=0) || (anio%400==0)){
        diasMes[1]=29;
    }

    cout<<"Mes: ";
    cin>>M;
    while(M<1 or M>12 or cin.fail()){
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"ingrese nuevamebte el Mes: ";
        cin>>M;
    }
    mes=M;

    cout<<"Día: ";
    cin>>D;
    while(D<1 or D>diasMes[mes-1] or cin.fail()){
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"ingrese nuevamente el Día: ";
        cin>>D;
    }
    dia=D;
}
void Fechas::mostrar(){
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}
