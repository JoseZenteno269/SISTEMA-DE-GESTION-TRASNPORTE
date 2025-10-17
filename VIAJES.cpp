#include<iostream>
#include "VIAJES.h"
#include<cstring>
#include "ARCHIVO_MICROS.h"
#include "ARCHIVO_CHOFERES.h"
#include "ARCHIVO_DESTINOS.h"

using namespace std;

void Viajes::setidViaje(int idv){idViaje=idv; }
void Viajes::setidMicro(int idm){idMicro=idm; }
void Viajes::setidChofer(int idc){idChofer=idc; }
void Viajes::setidDestino(int idd){idDestino=idd; }
void Viajes::setfecha_Inicio_Viaje(Fechas fiv){fecha_Inicio_Viaje=fiv; }
void Viajes::setfecha_Fin_Viaje(Fechas ffv){fecha_Fin_Viaje=ffv; }
void Viajes::setrealizado(bool r){realizado=r; }

int Viajes::getidViaje(){return idViaje; }
int Viajes::getidMicro(){return idMicro; }
int Viajes::getidChofer(){return idChofer; }
int Viajes::getidDestino(){return idDestino; }
Fechas Viajes::getfecha_Inicio_Viaje(){return fecha_Inicio_Viaje; }
Fechas Viajes::getfecha_Fin_Viaje(){return fecha_Fin_Viaje; }
bool Viajes::getrealizado(){return realizado; }

void Viajes::cargar(){

}
void Viajes::mostrar(){

}
