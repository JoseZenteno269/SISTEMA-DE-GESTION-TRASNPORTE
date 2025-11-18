#include<iostream>
#include<cstring>
#include "PASAJE.h"
#include "rlutil.h"
using namespace rlutil;
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


void Pasajes::mostrar(){
    setColor(YELLOW);
    locate(40, 3);  cout << "------------------------------------------";
    locate(40, 4);  cout << "            INFORMACION DEL PASAJE        ";
    locate(40, 5);  cout << "------------------------------------------";
    setColor(WHITE);
    locate(40, 7);cout<<"========================================";
    locate(40, 8);cout<<"Numero de Pasaje:       "<<pasaje;
    locate(40, 9);cout<<"ID de viaje:            "<<idviaje;
    locate(40, 11);cout<<"Numero de Butaca:       "<<butaca;
    locate(40, 12);cout<<"Tipo de Butaca:         "<<tipo_butaca;
    locate(40, 13);cout<<"Precio $                "<<precioxkm;
    locate(40, 14);cout<<"Lugar de Destino:       "<<nombre_destino;
    locate(40, 15);cout<<"Provincia de Destino:   "<<provincia_destino;
    locate(40, 17);cout<<"========================================";
}
