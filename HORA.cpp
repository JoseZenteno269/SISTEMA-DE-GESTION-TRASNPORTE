#include<iostream>
#include "HORA.h"

using namespace std;


bool Hora::validar(int h, int m){
    return (h>=0 and h<24 and m>=0 and m<60);
}

Hora::Hora(){
    time_t t=time(nullptr);
    tm* ahora=localtime(&t);

    hora=ahora->tm_hour;
    minuto=ahora->tm_min;
}

Hora::Hora(int h, int m){
    if(validar(h,m)){
        hora=h;
        minuto=m;
    }else{
        hora=0;
        minuto=0;
    }
}

void Hora::sethora(int h){
    if(h>=0 and h<24) hora=h;
}

void Hora::setminuto(int m){
    if(m>=0 and m<60) minuto=m;
}

void Hora::settiempo(int h, int m){
    if(validar(h,m)){
        hora=h;
        minuto=m;
    }
}

int Hora::gethora(){return hora; }
int Hora::getminuto(){return minuto; }

void Hora::cargar(){
    int h, m;
    do{
        cout<<"Ingrese hora (0-23): ";
        cin>>h;
        cout<<"Ingrese minutos (0-59): ";
        cin>>m;

        if(!validar(h, m))
            cout<<"Hora o minutos inválidos, ingrese nuevamente\n";
    } while(!validar(h,m));

    hora=h;
    minuto=m;
}

void Hora::mostrar(){
    cout<<(hora<10 ? "0" : "")<<hora<<":"<<(minuto < 10 ? "0" : "")<<minuto<<endl;
}


