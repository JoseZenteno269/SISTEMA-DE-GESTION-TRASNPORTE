#include<iostream>
#include<cstring>
#include "PASAJE.h"

using namespace std;

void Pasajes::setpasaje(int pasj){pasaje=pasj;}
void Pasajes::setidviaje(int idv){idviaje=idv; }
void Pasajes::setbutaca(int but){butaca=but; }
void Pasajes::setprecioxkm(int pxkm){precioxkm=pxkm; }
void Pasajes::settipo_butaca(const char* tb){strcpy(tipo_butaca, tb); }
void Pasajes::setnombre_destino(const char *nd){strcpy(nombre_destino, nd); }
void Pasajes::setprovincia_destino(const char * pd){strcpy(provincia_destino, pd); }
void Pasajes::setdatos(Viajes d){ datos=d; }

int Pasajes::getpasaje(){return pasaje; }
int Pasajes::getidviaje(){return idviaje; }
int Pasajes::getbutaca(){return butaca; }
int Pasajes::getprecioxkm(){return precioxkm; }
const char *Pasajes::gettipo_butaca(){return tipo_butaca; }
const char *Pasajes::getnombre_destino(){return nombre_destino; }
const char *Pasajes::getprovincia_destino(){return provincia_destino; }
Viajes Pasajes::getdatos(){return datos; }

void Pasajes::mostrar(){
    cout<<"========================================"<<endl;
    cout<<"Numero de Pasaje: "<<pasaje<<endl;
    cout<<"ID de viaje: "<<idviaje<<endl;
    cout<<"Numero de Butaca: "<<butaca<<endl;
    cout<<"Tipo de Butaca: "<<tipo_butaca<<endl;
    cout<<"Precio $"<<precioxkm<<endl;
    cout<<"Lugar de Destino: "<<nombre_destino<<endl;
    cout<<"Provincia de Destino: "<<provincia_destino<<endl;
    cout<<"========================================"<<endl;
}
