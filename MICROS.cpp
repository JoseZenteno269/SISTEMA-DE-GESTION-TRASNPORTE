#include<iostream>
#include "MICROS.h"
#include<cstring>
#include "funciones.h"
#include "rlutil.h"
using namespace rlutil;

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

void Micros::cargar(int idm){
    system("cls");

    setColor(GREEN);
    locate(40, 3);  cout<<"------------------------------------------";
    locate(40, 4);  cout<<"          REGISTRO DE NUEVO MICRO        ";
    locate(40, 5);  cout<<"------------------------------------------";
    setColor(WHITE);

    locate(40, 7);
    cout<<"El ID de Micro: "<<(idMicro=idm);

    while(true){
        setColor(CYAN);
        locate(40, 9);  cout<<"Ingrese marca (Volvo / Scania / Mercedes-Benz):                ";
        setColor(WHITE);

        locate(40, 10);
        cargarCadena(marca, 29);

        for(int i=0; marca[i]; i++) marca[i]=tolower(marca[i]);

        if(strcmp(marca, "volvo")==0 or strcmp(marca, "scania")==0 or strcmp(marca, "mercedes-benz")==0){
            LimpiarLineas(9, 15, 40);
            break;
        }

        setColor(RED);
        locate(40, 12);
        cout << "Marca inválida. Intente nuevamente.";
        setColor(WHITE);
        anykey();
        LimpiarLineas(9, 15, 40);
    }

    while(true){
        setColor(CYAN);
        locate(40, 9);  cout << "Ingrese tipo del micro (simple-piso / doble-piso):             ";
        setColor(WHITE);

        locate(40, 10);
        cargarCadena(tipo, 29);

        for(int i=0; tipo[i]; i++) tipo[i]=tolower(tipo[i]);

        if(strcmp(tipo, "simple-piso")==0 or strcmp(tipo, "doble-piso")==0){
            LimpiarLineas(9, 15, 40);
            break;
        }

        setColor(RED);
        locate(40, 12);
        cout<<"Tipo inválido. Intente nuevamente.";
        setColor(WHITE);

        anykey();
        LimpiarLineas(9, 15, 40);
    }

    while(true){
        setColor(CYAN);
        locate(40, 9);  cout<<"Ingrese butaca (comun / cama / semi-cama):                     ";
        setColor(WHITE);

        locate(40, 10);
        cargarCadena(tipoButaca, 29);

        for(int i=0; tipoButaca[i]; i++) tipoButaca[i]=tolower(tipoButaca[i]);

        if(strcmp(tipoButaca, "comun")==0 or strcmp(tipoButaca, "cama")==0 or strcmp(tipoButaca, "semi-cama")==0){
            LimpiarLineas(9, 15, 40);
            break;
        }

        setColor(RED);
        locate(40, 12);
        cout << "Butaca inválida. Intente nuevamente.";
        setColor(WHITE);
        anykey();
        LimpiarLineas(9, 15, 40);
    }

    while(true){
        setColor(CYAN);
        locate(40, 9);  cout<<"Ingrese patente (AA111AA):                                     ";
        setColor(WHITE);

        locate(40, 10);
        cargarCadena(patente, 9);

        for(int i=0; patente[i]; i++) patente[i]=toupper(patente[i]);

        if(validarPatente(patente)){
            if(existePatente(patente, idMicro)){
                setColor(RED);
                LimpiarLineas(9, 15, 40);
                locate(40, 12);
                cout << "ERROR: La patente ya existe. Intente con otra.";
                setColor(WHITE);
            } else {
                break;
            }
        }else{
            setColor(RED);
            locate(40, 12);
            cout << "Patente inválida. Intente nuevamente.";
            setColor(WHITE);

        }

//        if(validarPatente(patente)){
//            LimpiarLineas(9, 15, 40);
//            break;
//        }

//        setColor(RED);
//        locate(40, 12);
//        cout << "Patente inválida. Intente nuevamente.";
//        setColor(WHITE);
//        anykey();
//        LimpiarLineas(9, 15, 40);
    }

    capacidadportipo();
    disponible=true;

    system("cls");
}

void Micros::mostrar(int X, int Y){
    setColor(YELLOW);
    locate(X, Y);     cout << "------------------------------------------";
    locate(X, Y + 1); cout << "              INFORMACION DEL MICRO        ";
    locate(X, Y + 2); cout << "------------------------------------------";
    setColor(WHITE);

    locate(X, Y + 4); cout << "ID de Micro:           " << idMicro;
    locate(X, Y + 5); cout << "Marca:                 " << marca;
    locate(X, Y + 6); cout << "Tipo:                  " << tipo;
    locate(X, Y + 7); cout << "Capacidad:             " << capacidad;
    locate(X, Y + 8); cout << "Tipo de Butaca:        " << tipoButaca;
    locate(X, Y + 9); cout << "Patente:               " << patente;

    setColor(YELLOW);
    locate(X, Y + 11); cout << "------------------------------------------";
    setColor(WHITE);

    anykey();
    LimpiarLineas(Y, Y + 11, X);
}

