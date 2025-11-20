#include<iostream>
#include "HORA.h"
#include "funciones.h"
#include "rlutil.h"
using namespace rlutil;

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

        while(true){
            setColor(CYAN);
            locate(40,11); cout << "Ingrese hora (0-23): ";
            setColor(WHITE);
            locate(40,12); cin >> hora;

            if(!validar_numero()){
                LimpiarLineas(11,15,40);
                setColor(RED);
                locate(40,13); cout << "Valor invalido. Intente nuevamente.";
                setColor(WHITE);
                continue;
            }else break;

            //LimpiarLineas(11,15,40);

        }

        while(true){
            setColor(CYAN);
            locate(40,14); cout << "Ingrese minutos (0-59): ";
            setColor(WHITE);
            locate(40,15); cin >> minuto;

            if(!validar_numero()){
                LimpiarLineas(14,18,40);
                setColor(RED);
                locate(40,17); cout << "Valor invalido. Intente nuevamente.";
                setColor(WHITE);
                continue;
            }else break;
        }

        if(!validar(hora, minuto)){
            setColor(RED);
            locate(40,17); cout << "Hora o minutos invalidos.";
            setColor(WHITE);
            anykey();
            LimpiarLineas(11,18,40);
        }
        else break;
    }
}

void Hora::cargar_viaje(){

    while(true){

        while(true){
            setColor(CYAN);
            locate(40,11); cout << "Ingrese hora (0-95): ";
            setColor(WHITE);
            locate(40,12); cin >> hora;

            if(validar_numero()){
                LimpiarLineas(11,15,40);
                break;
            }

            setColor(RED);
            locate(40,13); cout << "Valor invalido. Intente nuevamente.";
            setColor(WHITE);
            anykey();
            LimpiarLineas(11,15,40);
        }

        while(true){
            setColor(CYAN);
            locate(40,14); cout << "Ingrese minutos (0-59): ";
            setColor(WHITE);
            locate(40,15); cin >> minuto;

            if(validar_numero()){
                break;
            }

            setColor(RED);
            locate(40,17); cout << "Valor invalido. Intente nuevamente.";
            setColor(WHITE);
            anykey();
            LimpiarLineas(14,18,40);
        }

        if(!validar_viaje(hora, minuto)){
            setColor(RED);
            locate(40,17); cout << "Hora o minutos invalidos.";
            setColor(WHITE);
            anykey();
            LimpiarLineas(11,18,40);
        }
        else break;
    }
}


void Hora::mostrarEn(int X, int Y){
    setColor(WHITE);
    locate(X, Y); cout << (hora < 10 ? "0" : "") << hora << ":" << (minuto < 10 ? "0" : "") << minuto;
    setColor(WHITE);
}

void Hora::mostrar(int col, int fila){
    setColor(WHITE);

    locate(col + 20, fila);
    cout<<(hora<10 ? "0" : "")<<hora<<":"<<(minuto<10 ? "0" : "")<<minuto<<endl;
}
