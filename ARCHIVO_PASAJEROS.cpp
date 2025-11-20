#include<iostream>
#include<cstring>
#include "ARCHIVO_PASAJEROS.h"

using namespace std;

Archivo_pasajero::Archivo_pasajero(const char *a){
    strcpy(archivo, a);
    FILE *p = fopen(archivo, "rb"); // intento abrir en modo lectura
    if(p == nullptr){               // si no existe, lo creo vacío
        p = fopen(archivo, "wb");  // crear archivo vacío
    }
    if(p) fclose(p);
}

int Archivo_pasajero::contarRegistros(){
    FILE *p=fopen(archivo, "rb");
    if(p==nullptr){
        cout<<"no exite el erchivo"<<endl;
        return -1;
    }
    fseek(p,0,2);
    int bytes=ftell(p);
    fclose(p);
    return bytes/sizeof(Pasajero);
}

int Archivo_pasajero::buscarRegistro(int num_p){
    Pasajero pasajero;
    int contreg=contarRegistros();
    for(int i=0; i<contreg; i++){
        pasajero=leerRegistros(i);
        if(pasajero.getnumero_pasaje()==num_p){
            return i;
        }
    }
    return -2;
}

Pasajero Archivo_pasajero::leerRegistros(int pos){
    FILE *p=fopen(archivo, "rb");
    Pasajero pasajero;
    if(p==nullptr){
        pasajero.setnumero_pasaje(-3);
        return pasajero;
    }
    fseek(p, pos*sizeof pasajero, 0);
    pasajero.setnumero_pasaje(-4);
    fread(&pasajero, sizeof pasajero, 1, p);
    fclose(p);
    return pasajero;
}

bool Archivo_pasajero::grabarRegistro(Pasajero pasajero){
    FILE *p=fopen(archivo, "ab");
    if(p==nullptr){
        return false;
    }
    bool escribo=fwrite(&pasajero, sizeof pasajero, 1, p);
    fclose(p);
    return escribo;
}

bool Archivo_pasajero::modificarRegistro(Pasajero pasajero, int pos){
    FILE *p=fopen(archivo, "rb+");
    if(p==nullptr){
        return false;
    }
    fseek(p, pos*sizeof pasajero, 0);
    bool escribo=fwrite(&pasajero, sizeof pasajero, 1, p);
    fclose(p);
    return escribo;
}

void Archivo_pasajero::listar(){
    Pasajero pasajero;
    int contreg=contarRegistros();
    for(int i=0; i<contreg; i++){
        pasajero=leerRegistros(i);
        if(pasajero.gethabilitado()){
            pasajero.mostrar();
            cout<<endl;
        }
    }
}
