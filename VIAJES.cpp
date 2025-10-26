#include<iostream>
#include "VIAJES.h"
#include<cstring>
#include "ARCHIVO_MICROS.h"
#include "MICROS.h"
#include "ARCHIVO_CHOFERES.h"
#include "CHOFERES.h"
#include "ARCHIVO_DESTINOS.h"
#include "DESTINOS.h"

using namespace std;

void Viajes::setidViaje(int idv){idViaje=idv; }
void Viajes::setidMicro(int idm){idMicro=idm; }
void Viajes::setidChofer(int idc){idChofer=idc; }
void Viajes::setidDestino(int idd){idDestino=idd; }
void Viajes::setprecio(int p){precio=p; }
void Viajes::setfecha_Inicio_Viaje(Fechas fiv){fecha_Inicio_Viaje=fiv; }
void Viajes::setfecha_Fin_Viaje(Fechas ffv){fecha_Fin_Viaje=ffv; }
void Viajes::sethora_Inicio_Viaje(Hora hiv){hora_Inicio_Viaje=hiv; }
void Viajes::sethora_Fin_Viaje(Hora hfv){hora_Fin_Viaje=hfv; }
void Viajes::setrealizado(bool r){realizado=r; }

int Viajes::getidViaje(){return idViaje; }
int Viajes::getidMicro(){return idMicro; }
int Viajes::getidChofer(){return idChofer; }
int Viajes::getidDestino(){return idDestino; }
int Viajes::getprecio(){return precio; }
Fechas Viajes::getfecha_Inicio_Viaje(){return fecha_Inicio_Viaje; }
Fechas Viajes::getfecha_Fin_Viaje(){return fecha_Fin_Viaje; }
Hora Viajes::gethora_Inicio_Viaje(){return hora_Inicio_Viaje; }
Hora Viajes::gethora_Fin_Viaje(){return hora_Fin_Viaje; }
bool Viajes::getrealizado(){return realizado; }

void Viajes::cargar(int idv){
    cout<<"ID de viaje: "<<(idViaje=idv)<<endl;

    while(true){
        Micros micro;
        Archivo_micros archivo;
        bool seguir=false;
        cout<<"ingrese ID de micro: "; cin>>idMicro;
        int contreg=archivo.contarRegistros();
        for(int i=0; i<contreg; i++){
            micro=archivo.leerRegistros(i);
            if(idMicro==micro.getidMicro()){
                seguir=true;
                break;
            }
        }
        if(seguir)break; else cout<<"ingresar nuevamente el ID de micro"<<endl;
    }

    while(true){
        Choferes chofer;
        Archivo_choferes archivo;
        bool seguir=false;
        cout<<"ingrese Legajo de chofer a designar: "; cin>>idChofer;
        int contreg=archivo.contarRegistros();
        for(int i=0; i<contreg; i++){
            chofer=archivo.leerRegistros(i);
            if(idChofer==chofer.getlegajo()){
                seguir=true;
                break;
            }
        }
        if(seguir)break; else cout<<"ingresar nuevamente el Legajo del chofer"<<endl;
    }

    while(true){
        Destinos destino;
        Archivo_destinos archivo;
        bool seguir=false;
        cout<<"ingrese ID de destino: "; cin>>idDestino;
        int contreg=archivo.contarRegistros();
        for(int i=0; i<contreg; i++){
            destino=archivo.leerRegistros(i);
            if(idDestino==destino.getidDestino()){
                seguir=true;
                break;
            }
        }
        if(seguir)break; else cout<<"ingresar nuevamente el ID de destino"<<endl;
    }

    cout<<"ingrese fecha de inicio de viaje: "<<endl;
    fecha_Inicio_Viaje.cargar();
    cout<<"ingrese fecha de fin de viaje: "<<endl;
    fecha_Fin_Viaje.cargar();
    cout<<"ingrese hora de inicio de viaje: "<<endl;
    hora_Inicio_Viaje.cargar();
    cout<<"ingrese hora de fin de viaje: "<<endl;
    hora_Fin_Viaje.cargar();
    realizado=true;
}
void Viajes::mostrar(){
    cout<<"##################################################"<<endl;
    cout<<"ID de viaje: "<<idViaje<<endl;
    cout<<"ID de micro: "<<idMicro<<endl;
    cout<<"ID de chofer a designar: "<<idChofer<<endl;
    cout<<"ID de destino: "<<idDestino<<endl;
    cout<<"Fecha de inicio de viaje: "; fecha_Inicio_Viaje.mostrar();
    cout<<"Fecha de fin de viaje: "; fecha_Fin_Viaje.mostrar();
    cout<<"Hora de inicio de viaje: "; hora_Inicio_Viaje.mostrar();
    cout<<"Hora de fin de viaje: "; hora_Fin_Viaje.mostrar();
    cout<<"##################################################"<<endl;
}
