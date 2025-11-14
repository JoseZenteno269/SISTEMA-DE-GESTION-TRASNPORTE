#include<iostream>
#include "funciones.h"
#include "VIAJES.h"
#include<cstring>
#include "ARCHIVO_MICROS.h"
#include "MICROS.h"
#include "ARCHIVO_CHOFERES.h"
#include "CHOFERES.h"
#include "ARCHIVO_DESTINOS.h"
#include "DESTINOS.h"
#include "TIEMPO_ACTUAL.h"
#include "funciones.h"
#include "ARCHIVO_VIAJES.h"

using namespace std;

void Viajes::setidViaje(int idv){idViaje=idv; }
void Viajes::setidMicro(int idm){idMicro=idm; }
void Viajes::setidChofer(int idc){idChofer=idc; }
void Viajes::setidDestino(int idd){idDestino=idd; }
void Viajes::setfecha_Inicio_Viaje(Fechas fiv){fecha_Inicio_Viaje=fiv; }
void Viajes::setfecha_Fin_Viaje(Fechas ffv){fecha_Fin_Viaje=ffv; }
void Viajes::sethora_Inicio_Viaje(Hora hiv){hora_Inicio_Viaje=hiv; }
void Viajes::sethora_Fin_Viaje(Hora hfv){hora_Fin_Viaje=hfv; }
void Viajes::setrealizado(bool r){realizado=r; }

int Viajes::getidViaje(){return idViaje; }
int Viajes::getidMicro(){return idMicro; }
int Viajes::getidChofer(){return idChofer; }
int Viajes::getidDestino(){return idDestino; }
Fechas Viajes::getfecha_Inicio_Viaje(){return fecha_Inicio_Viaje; }
Fechas Viajes::getfecha_Fin_Viaje(){return fecha_Fin_Viaje; }
Hora Viajes::gethora_Inicio_Viaje(){return hora_Inicio_Viaje; }
Hora Viajes::gethora_Fin_Viaje(){return hora_Fin_Viaje; }
bool Viajes::getrealizado(){return realizado; }

void Viajes::cargar(int idv){
    Archivo_micros archivomicro;
    Archivo_choferes archivochofer;
    Destinos destino;
    Archivo_destinos archivodestino;
    Tiempo_Actual actual;
    Fechas presente(actual.getDia(), actual.getMes(), actual.getAnio());

    cout<<"ID de viaje: "<<(idViaje=idv)<<endl;

    while(true){
        Micros micro;
        cout<<"ingrese ID de micro (0 para salir): "; cin>>idMicro;
        if(!validar_numero())continue;
        if(idMicro==0){cout<<"Operación cancelada"<<endl; break;}
        int pos=archivomicro.buscarRegsitro(idMicro);
        if(pos<0){
            cout<<"ERROR, sin registros"<<endl;
            continue;
        }
        micro=archivomicro.leerRegistros(pos);
        if(idMicro==micro.getidMicro())break;
    }

    while(true){
        Choferes chofer;
        cout<<"ingrese Legajo de chofer a designar (0 para salir): "; cin>>idChofer;
        if(!validar_numero())continue;
        if(idChofer==0){cout<<"Operación cancelada"<<endl; break;}
        int pos=archivochofer.buscarRegistro(idChofer);
        if(pos<0){
            cout<<"ERROR, sin registros"<<endl;
            continue;
        }
        chofer=archivochofer.leerRegistros(pos);
        if(idChofer==chofer.getlegajo())break;
    }

    while(true){
        Destinos destino;
        cout<<"ingrese ID de destino (0 para salir): "; cin>>idDestino;
        if(!validar_numero())continue;
        if(idDestino==0){cout<<"Operación cancelada"<<endl; break;}
        int pos=archivodestino.buscarRegistros(idDestino);
        if(pos<0){
            cout<<"ERROR, sin registros"<<endl;
            break;
        }
        destino=archivodestino.leerRegistros(pos);
        if(idDestino==destino.getidDestino())break;
    }

    if(idMicro==0 or idChofer==0 or idDestino==0)return;

    while(true){
        cout<<"ingrese fecha de inicio de viaje: "<<endl;
        fecha_Inicio_Viaje.cargar();
        if(esFechaPosterior(fecha_Inicio_Viaje, presente))break;
        cout<<"ERROR no se puede ingresar una fecha anterior a la actual"<<endl;
    }

    cout<<"ingrese hora de inicio de viaje: "<<endl;
    hora_Inicio_Viaje.cargar();

    fecha_y_hora_fin(destino, archivodestino, fecha_Fin_Viaje, hora_Fin_Viaje, fecha_Inicio_Viaje, hora_Inicio_Viaje, idDestino);

    realizado=true;
}

void Viajes::mostrar(){
    cout<<"--------------------------------------------------"<<endl;
    cout<<"ID de viaje: "<<idViaje<<endl;
    Micros micro;
    Archivo_micros archivomicro;
    int pos1=archivomicro.buscarRegsitro(idMicro);
    micro=archivomicro.leerRegistros(pos1);
    micro.mostrar();
    cout<<"ID de chofer a designar: "<<idChofer<<endl;
    Destinos destino;
    Archivo_destinos archivodestino;
    int pos2=archivodestino.buscarRegistros(idDestino);
    destino=archivodestino.leerRegistros(pos2);
    destino.mostrar();
    cout<<"Fecha de inicio de viaje: "; fecha_Inicio_Viaje.mostrar();
    cout<<"Fecha de fin de viaje: "; fecha_Fin_Viaje.mostrar();
    cout<<"Hora de inicio de viaje: "; hora_Inicio_Viaje.mostrar();
    cout<<"Hora de fin de viaje: "; hora_Fin_Viaje.mostrar();
    cout<<"--------------------------------------------------"<<endl;
}
