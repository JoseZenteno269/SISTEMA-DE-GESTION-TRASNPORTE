#include<iostream>
#include "DESTINOS.h"
#include "funciones.h"
#include<cstring>

using namespace std;

void Destinos::setidDestino(int idd){idDestino=idd; }
void Destinos::setcodigo_provincia(const char *cp){strcpy(codigo_provincia, cp); }
void Destinos::setnombre_destino(const char *nd){strcpy(nombre_destino, nd); }
void Destinos::setdistanciaKm(float dkm){distanciaKm=dkm; }
void Destinos::setduracion(Hora hd){duracion=hd; }
void Destinos::sethabilitado(bool h){habilitado=h; }

int Destinos::getidDestino(){return idDestino; }
const char*Destinos::getcodigo_provincia(){return codigo_provincia; }
const char *Destinos::getnombre_destino(){return nombre_destino; }
float Destinos::getdistanciaKm(){return distanciaKm; }
Hora Destinos::getduracion(){return duracion; }
bool Destinos::gethabilitado(){return habilitado; }

void Destinos::cargar(int idd){
    cout<<"ID de distancia: "<<(idDestino=idd)<<endl;
    cout<<"ingrese Codigo de provincia: "; cargarCadena(codigo_provincia, 4);
    cout<<"ingrese lugar de destino: "; cargarCadena(nombre_destino, 39);
    cout<<"ingrese hora de duracion de viaje: "<<endl;
    duracion.cargar();
    cout<<"ingrese distancia en KM: "; cin>>distanciaKm;
    habilitado=true;
}
void Destinos::mostrar(){
    cout<<"ID de destino: "<<idDestino<<endl;
    cout<<"Codigo provincia: "<<codigo_provincia<<endl;
    cout<<"Lugar de destino: "<<nombre_destino<<endl;
    cout<<"Duracion del viaje: "; duracion.mostrar();
    cout<<"Distancia: "<<distanciaKm<<endl;
}
