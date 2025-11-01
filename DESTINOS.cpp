#include<iostream>
#include "DESTINOS.h"
#include "funciones.h"
#include<cstring>

using namespace std;

void Destinos::setidDestino(int idd){idDestino=idd; }
void Destinos::setnombre_provincia(const char *p){strcpy(nombre_provincia, p); }
void Destinos::setnombre_destino(const char *nd){strcpy(nombre_destino, nd); }
void Destinos::setdistanciaKm(float dkm){distanciaKm=dkm; }
void Destinos::setduracion(Hora hd){duracion=hd; }
void Destinos::sethabilitado(bool h){habilitado=h; }

int Destinos::getidDestino(){return idDestino; }
const char*Destinos::getnombre_provincia(){return nombre_provincia; }
const char *Destinos::getnombre_destino(){return nombre_destino; }
float Destinos::getdistanciaKm(){return distanciaKm; }
Hora Destinos::getduracion(){return duracion; }
bool Destinos::gethabilitado(){return habilitado; }

void Destinos::cargar(int idd){
    cout<<"ID de distancia: "<<(idDestino=idd)<<endl;
    while(true){
        int bandera=false;
        cout<<"ingrese nombre de provincia: "; cargarCadena(nombre_provincia, 39);
        for(int i=0; i<23; i++){
            const char *nombre=funcion_provincias(i);
            if(strcmp(nombre, nombre_provincia)==0)bandera=true;
        }
        if(bandera)break;
    }
    cout<<"ingrese lugar de destino: "; cargarCadena(nombre_destino, 39);
    cout<<"ingrese hora de duracion de viaje: "<<endl;
    duracion.cargar();
    cout<<"ingrese distancia en KM: "; cin>>distanciaKm;
    habilitado=true;
}
void Destinos::mostrar(){
    cout<<"ID de destino: "<<idDestino<<endl;
    cout<<"nombre provincia: "<<nombre_provincia<<endl;
    cout<<"Lugar de destino: "<<nombre_destino<<endl;
    cout<<"Duracion del viaje: "; duracion.mostrar();
    cout<<"Distancia: "<<distanciaKm<<endl;
}
