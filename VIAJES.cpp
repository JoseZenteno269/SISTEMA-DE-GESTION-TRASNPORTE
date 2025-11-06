#include<iostream>
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
    cout << "ID de viaje: " << (idViaje = idv) << endl;

    while(true){
        Destinos destino;
        Archivo_destinos archivo;
        bool existe = false;

        cout << "Ingrese ID de destino: ";
        cin >> idDestino;

        int contreg = archivo.contarRegistros();
        for(int i = 0; i < contreg; i++){
            destino = archivo.leerRegistros(i);
            if(idDestino == destino.getidDestino()){
                existe = true;
                break;
            }
        }

        if(existe) break;
        else cout << "ID de destino no existe. Ingrese nuevamente.\n";
    }

    Fechas actual;
    Tiempo_Actual tiempo;
    actual.setanio(tiempo.getAnio());
    actual.setmes(tiempo.getMes());
    actual.setdia(tiempo.getDia());

    bool fechaInciOK = false;
    while(!fechaInciOK){
        cout << "Ingrese fecha de inicio de viaje: " << endl;
        fecha_Inicio_Viaje.cargar();
        if(esFechaPosterior(fecha_Inicio_Viaje, actual)){
            fechaInciOK = true;
            cout << "Fecha válida.\n";
        } else {
            cout << "ERROR: NO SE PERMITEN VIAJES EN EL TIEMPO. Intente de nuevo.\n";
        }
    }

    bool fechaFinOK = false;
    while(!fechaFinOK){
        cout << "Ingrese fecha de fin de viaje: " << endl;
        fecha_Fin_Viaje.cargar();
        if(esFechaPosterior(fecha_Fin_Viaje, fecha_Inicio_Viaje)){
            fechaFinOK = true;
            cout << "Fecha válida.\n";
        } else {
            cout << "ERROR: La fecha de fin debe ser posterior a la de inicio.\n";
        }
    }

    while(true){
        Micros micro;
        Archivo_micros archivo;
        bool existe = false;

        cout << "Ingrese ID de micro: ";
        cin >> idMicro;

        int contreg = archivo.contarRegistros();
        for(int i = 0; i < contreg; i++){
            micro = archivo.leerRegistros(i);
            if(idMicro == micro.getidMicro()){
                existe = true;
                break;
            }
        }

        if(!existe){
            cout << "ID de micro no existe. Ingrese nuevamente.\n";
        } else {
            Archivo_viajes archViajes;
            int n = archViajes.contarRegistros();
            bool disponible = true;

            for(int i = 0; i < n; i++){
                Viajes vExistente = archViajes.leerRegistros(i);
                if(vExistente.getidMicro() == idMicro){
                    Fechas inicioExistente = vExistente.getfecha_Inicio_Viaje();
                    Fechas finExistente = vExistente.getfecha_Fin_Viaje();
                    if(!(esFechaPosterior(fecha_Inicio_Viaje, finExistente) ||
                         esFechaPosterior(inicioExistente, fecha_Fin_Viaje))){
                        disponible = false;
                        break;
                    }
                }
            }

            if(disponible) break;
            else cout << "ERROR: El micro ya tiene un viaje en esas fechas. Intente otro.\n";
        }
    }

    while(true){
        Choferes chofer;
        Archivo_choferes archivo;
        bool existe = false;

        cout << "Ingrese Legajo de chofer a designar: ";
        cin >> idChofer;

        int contreg = archivo.contarRegistros();
        for(int i = 0; i < contreg; i++){
            chofer = archivo.leerRegistros(i);
            if(idChofer == chofer.getlegajo()){
                existe = true;
                break;
            }
        }

        if(!existe){
            cout << "Legajo de chofer no existe. Ingrese nuevamente.\n";
        } else {
            Archivo_viajes archViajes;
            int n = archViajes.contarRegistros();
            bool disponible = true;

            for(int i = 0; i < n; i++){
                Viajes vExistente = archViajes.leerRegistros(i);
                if(vExistente.getidChofer() == idChofer){
                    Fechas inicioExistente = vExistente.getfecha_Inicio_Viaje();
                    Fechas finExistente = vExistente.getfecha_Fin_Viaje();
                    if(!(esFechaPosterior(fecha_Inicio_Viaje, finExistente) ||
                         esFechaPosterior(inicioExistente, fecha_Fin_Viaje))){
                        disponible = false;
                        break;
                    }
                }
            }

            if(disponible) break;
            else cout << "ERROR: El chofer ya tiene un viaje en esas fechas. Intente otro.\n";
        }
    }

    cout << "Ingrese hora de inicio de viaje: " << endl;
    hora_Inicio_Viaje.cargar();
    cout << "Ingrese hora de fin de viaje: " << endl;
    hora_Fin_Viaje.cargar();

    realizado = true;
    cout << "Viaje cargado correctamente.\n";
}

void Viajes::mostrar(){
    cout<<"--------------------------------------------------"<<endl;
    cout<<"ID de viaje: "<<idViaje<<endl;
    Micros micro;
    Archivo_micros archivo1;
    int pos1=archivo1.buscarRegsitro(idMicro);
    micro=archivo1.leerRegistros(pos1);
    micro.mostrar();
    cout<<"ID de chofer a designar: "<<idChofer<<endl;
    Destinos destino;
    Archivo_destinos archivo2;
    int pos2=archivo2.buscarRegistros(idDestino);
    destino=archivo2.leerRegistros(pos2);
    destino.mostrar();
    cout<<"Fecha de inicio de viaje: "; fecha_Inicio_Viaje.mostrar();
    cout<<"Fecha de fin de viaje: "; fecha_Fin_Viaje.mostrar();
    cout<<"Hora de inicio de viaje: "; hora_Inicio_Viaje.mostrar();
    cout<<"Hora de fin de viaje: "; hora_Fin_Viaje.mostrar();
    cout<<"--------------------------------------------------"<<endl;
}
