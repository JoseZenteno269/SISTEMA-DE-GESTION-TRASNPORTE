#include<iostream>
#include "HORA.h"

using namespace std;


bool Hora::validar(int h, int m){
    return (h>=0 and h<24 and m>=0 and m<60);
}

bool Hora::validar_viaje(int h, int m){
    return (h>=0 and h<96 and m>=0 and m<60);
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

void Hora::sethora_viaje(int h){
    if(h>=0 and h<96) hora=h;
}

void Hora::setminuto_viaje(int m){
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
    while(true){
        cout<<"Ingrese hora (0-23): "; cin>>hora;
        cout<<"Ingrese minutos (0-59): "; cin>>minuto;

        if(!validar(hora, minuto))cout<<"Hora o minutos inválidos, ingrese nuevamente\n";
        else break;
    }
}

void Hora::cargar_viaje(){
    while(true){
        cout<<"Ingrese hora (0-95): "; cin>>hora;
        cout<<"Ingrese minutos (0-59): "; cin>>minuto;

        if(!validar_viaje(hora, minuto))cout<<"Hora o minutos inválidos, ingrese nuevamente\n";
        else break;
    }
}

void Hora::mostrar(){
    cout<<(hora<10 ? "0" : "")<<hora<<":"<<(minuto<10 ? "0" : "")<<minuto<<endl;
}


