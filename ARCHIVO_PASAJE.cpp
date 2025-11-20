#include<iostream>
#include<cstring>
#include "ARCHIVO_PASAJE.h"
#include "rlutil.h"


using namespace rlutil;
using namespace std;

Archivo_pasajes::Archivo_pasajes(const char *a){
    strcpy(archivo, a);
    FILE *p = fopen(archivo, "rb"); // intento abrir en modo lectura
    if(p == nullptr){               // si no existe, lo creo vacío
        p = fopen(archivo, "wb");  // crear archivo vacío
    }
    if(p) fclose(p);
}

int Archivo_pasajes::contarRegistros(){
    FILE *p=fopen(archivo, "rb");
    if(p==nullptr){
        cout<<"no se ingreso al archivo"<<endl;
        return -1;
    }
    fseek(p, 0, 2);
    int bytes=ftell(p);
    fclose(p);
    return bytes/sizeof(Pasajes);
}

int Archivo_pasajes::buscarRegistro(int pasj){
    Pasajes pasaje;
    int contreg=contarRegistros();
    for(int i=0; i<contreg; i++){
        pasaje=leerRegistros(i);
        if(pasaje.getpasaje()==pasj){
            return i;
        }
    }
    return -2;
}

Pasajes Archivo_pasajes::leerRegistros(int pos){
    FILE *p=fopen(archivo, "rb");
    Pasajes pasaje;
    if(p==nullptr){
        pasaje.setpasaje(-3);
        return pasaje;
    }
    fseek(p, pos*sizeof (Pasajes), 0);
    pasaje.setpasaje(-4);
    fread(&pasaje, sizeof (Pasajes), 1, p);
    fclose(p);
    return pasaje;
}

bool Archivo_pasajes::grabarRegistro(Pasajes pasaje){
    FILE *p=fopen(archivo, "ab");
    if(p==nullptr){
        return false;
    }
    bool escribo=fwrite(&pasaje, sizeof (Pasajes), 1, p);
    fclose(p);
    return escribo;
}

void Archivo_pasajes::listar(){
    Pasajes pasaje;
    int contreg=contarRegistros();
    for(int i=0; i<contreg; i++){
        pasaje=leerRegistros(i);
        pasaje.mostrar();
        anykey();
        cls();
        cout<<endl;
    }
}
