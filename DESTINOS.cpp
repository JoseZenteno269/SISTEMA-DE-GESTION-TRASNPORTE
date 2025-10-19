#include<iostream>
#include "DESTINOS.h"
#include "funciones.h"
#include<cstring>

using namespace std;

void Destinos::setidDestino(int idd){idDestino=idd; }
void Destinos::setnombre_destino(const char *nd){strcpy(nombre_destino, nd); }
void Destinos::setprovincia(const char *p){strcpy(provincia, p);}
void Destinos::setdistanciaKm(float dkm){distanciaKm=dkm; }
void Destinos::sethabilitado(bool h){habilitado=h; }

int Destinos::getidDestino(){return idDestino; }
const char *Destinos::getnombre_destino(){return nombre_destino; }
const char *Destinos::getprovincia(){return provincia; }
float Destinos::getdistanciaKm(){return distanciaKm; }
bool Destinos::gethabilitado(){return habilitado; }

void Destinos::cargar(int idd){
    cout<<"ID de distancia: "<<(idDestino=idd)<<endl;
    cout<<"ingrese lugar de destino: "; cargarCadena(nombre_destino, 39);
    cout<<"ingrese provincia de destino: "; cargarCadena(provincia, 39);
    cout<<"ingrese distancia en KM: "; cin>>distanciaKm;
    habilitado=true;
}
void Destinos::mostrar(){
    cout<<"ID de destino: "<<idDestino<<endl;
    cout<<"Lugar de destino: "<<nombre_destino<<endl;
    cout<<"Provincia de destino: "<<provincia<<endl;
    cout<<"Distancia: "<<distanciaKm<<endl;
}
