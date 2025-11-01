#include<iostream>
#include "MICROS.h"
#include<cstring>
#include "funciones.h"

using namespace std;


void Micros::setidMicro(int idm){idMicro=idm; }
void Micros::setmarca(const char *mrc){strcpy(marca, mrc); }
void Micros::settipo(const char *t){strcpy(tipo, t); }
void Micros::setcapacidad(int c){capacidad=c; }
void Micros::settipoButaca(const char *tb){strcpy(tipoButaca,tb); }
void Micros::setpatente(const char *p){strcpy(patente,p); }
void Micros::setdisponible(bool disp){disponible=disp; }

int Micros::getidMicro(){return idMicro; }
const char *Micros::getmarca(){return marca; }
const char *Micros::gettipo(){return tipo; }
int Micros::getcapacidad(){return capacidad; }
const char *Micros::gettipoButaca(){return tipoButaca; }
const char *Micros::getpatente(){return patente; }
bool Micros::getdisponible(){return disponible; }

void Micros::capacidadportipo(){
    if (strcmp(tipoButaca,"comun")==0) capacidad=60;
    else if(strcmp(tipoButaca,"cama")==0)capacidad=30;
    else if(strcmp(tipoButaca,"semi-cama")==0)capacidad=40;
}

//bool validarPatente(const char *patente){
//    if(strlen(patente)!=7)return false;
//
//    for(int i=0; i<2; i++) if(patente[i]<'A' or patente[i]>'Z') return false;
//
//    for(int i=2; i<5; i++) if(patente[i]<'0' or patente[i]>'9') return false;
//
//    for(int i=5; i<7; i++) if(patente[i]<'A' or patente[i]>'Z') return false;
//
//    return true;
//}

void Micros::cargar(int idm){
    bool butacaOk=false;
    bool marcaOk=false;
    bool tipoOK=false;
    bool patenteOK=false;

    cout<<"El ID de Micro: "<<(idMicro=idm)<<endl;

    while(!marcaOk){
        cout<<"ingrese marca del micro: "; cargarCadena(marca, 29);
        for(int i=0; marca[i]; i++) marca[i]=tolower(marca[i]);

        if (strcmp(marca,"volvo")==0 or strcmp(marca,"scania")==0 or strcmp(marca,"mercedes-benz")==0) marcaOk=true;
        else cout<<"MARCA INVALIDA, MARCAS DISPONIBLES SCANIA, VOLVO, Mercedes-Benz"<<endl;
    }

    while(!tipoOK){
        cout<<"ingrese  tipo del micro: "; cargarCadena(tipo, 29);
        for(int i=0; tipo[i]; i++) tipo[i]=tolower(tipo[i]);

        if(strcmp(tipo,"simple-piso")==0 or strcmp(tipo,"doble-piso")==0) tipoOK = true;
        else cout<<"TIPO INVALIDO, TIPOS DISPONIBLES simple-piso doble-piso"<<endl;
    }

    while(!butacaOk){
        cout<<"ingrese tipo de butaca: "; cargarCadena(tipoButaca, 29);
        for(int i=0; tipoButaca[i]; i++) tipoButaca[i]=tolower(tipoButaca[i]);

        if (strcmp(tipoButaca,"comun")==0 or strcmp(tipoButaca,"cama")==0 or strcmp(tipoButaca,"semi-cama")==0) butacaOk=true;
        else cout<<"BUTACA INVALIDO, BUTACAS DISPONIBLES comun, cama, semi-cama"<<endl;
    }

    while(!patenteOK){
        cout<<"ingrese la patente del micro (formato AA111AA): "; cargarCadena(patente, 9);
        for(int i=0; patente[i]; i++) patente[i]=toupper(patente[i]);

        patenteOK=validarPatente(patente);
        if(!patenteOK) cout << "Patente inválida, intente nuevamente.\n";
    }

    capacidadportipo();
    disponible=true;
}


void Micros::mostrar(){
    cout<<"ID de Micro: "<<idMicro<<endl;
    cout<<"Marca del micro: "<<marca<<endl;
    cout<<"Tipo del micro: "<<tipo<<endl;
    cout<<"Capacidad: "<<capacidad<<endl;
    cout<<"Tipo de Butaca: "<<tipoButaca<<endl;
    cout<<"Patente: "<<patente<<endl;
}
