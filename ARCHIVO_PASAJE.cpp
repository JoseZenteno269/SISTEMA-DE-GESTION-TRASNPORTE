#include<iostream>
#include<cstring>
#include "ARCHIVO_PASAJE.h"
#include "rlutil.h"


using namespace rlutil;
using namespace std;

Archivo_pasaje::Archivo_pasaje(const char *a){
    strcpy(archivo, a);
    FILE *p = fopen(archivo, "rb"); // intento abrir en modo lectura
    if(p == nullptr){               // si no existe, lo creo vacío
        p = fopen(archivo, "wb");  // crear archivo vacío
    }
    if(p) fclose(p);
}

int Archivo_pasaje::contarRegistros(){
    FILE *p=fopen(archivo, "rb");
    if(p==nullptr){
        cout<<"no se ingreso al archivo"<<endl;
        return -1;
    }
    fseek(p, 0, 2);
    int bytes=ftell(p);
    fclose(p);
    return bytes/sizeof(Pasaje);
}

int Archivo_pasaje::buscarRegistro(int pasj){
    Pasaje pasaje;
    int contreg=contarRegistros();
    for(int i=0; i<contreg; i++){
        pasaje=leerRegistros(i);
        if(pasaje.getpasaje()==pasj){
            return i;
        }
    }
    return -2;
}

Pasaje Archivo_pasaje::leerRegistros(int pos){
    FILE *p=fopen(archivo, "rb");
    Pasaje pasaje;
    if(p==nullptr){
        pasaje.setpasaje(-3);
        return pasaje;
    }
    fseek(p, pos*sizeof (Pasaje), 0);
    pasaje.setpasaje(-4);
    fread(&pasaje, sizeof (Pasaje), 1, p);
    fclose(p);
    return pasaje;
}

bool Archivo_pasaje::grabarRegistro(Pasaje pasaje){
    FILE *p=fopen(archivo, "ab");
    if(p==nullptr){
        return false;
    }
    bool escribo=fwrite(&pasaje, sizeof (Pasaje), 1, p);
    fclose(p);
    return escribo;
}

void Archivo_pasaje::listar(){
    Pasaje pasaje;
    int contreg=contarRegistros();
    for(int i=0; i<contreg; i++){
        pasaje=leerRegistros(i);
        pasaje.mostrar();
        anykey();
        cls();
        cout<<endl;
    }
}
