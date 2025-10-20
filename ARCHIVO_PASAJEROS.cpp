#include<iostream>
#include<cstring>
#include "ARCHIVO_PASAJEROS.h"

using namespace std;

Archivo_pasajeros::Archivo_pasajeros(const char *a){
    strcpy(archivo, a);
    FILE *p = fopen(archivo, "rb"); // intento abrir en modo lectura
    if(p == nullptr){               // si no existe, lo creo vacío
        p = fopen(archivo, "wb");  // crear archivo vacío
    }
    if(p) fclose(p);
}

int Archivo_pasajeros::contarRegistros(){
    FILE *p=fopen(archivo, "rb");
    if(p==nullptr){
        cout<<"no exite el erchivo"<<endl;
        return -1;
    }
    fseek(p,0,2);
    int bytes=ftell(p);
    fclose(p);
    return bytes/sizeof(Pasajeros);
}

int Archivo_pasajeros::buscarRegistro(int num_p){
    Pasajeros pasajero;
    int contreg=contarRegistros();
    for(int i=0; i<contreg; i++){
        pasajero=leerRegistros(i);
        if(pasajero.getnumero_pasaje()==num_p){
            return i;
        }
    }
    return -2;
}

Pasajeros Archivo_pasajeros::leerRegistros(int pos){
    FILE *p=fopen(archivo, "rb");
    Pasajeros pasajero;
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

bool Archivo_pasajeros::grabarRegistro(Pasajeros pasajero){
    FILE *p=fopen(archivo, "ab");
    if(p==nullptr){
        return false;
    }
    bool escribo=fwrite(&pasajero, sizeof pasajero, 1, p);
    fclose(p);
    return escribo;
}

bool Archivo_pasajeros::modificarRegistro(Pasajeros pasajero, int pos){
    FILE *p=fopen(archivo, "rb+");
    if(p==nullptr){
        return false;
    }
    fseek(p, pos*sizeof pasajero, 0);
    bool escribo=fwrite(&pasajero, sizeof pasajero, 1, p);
    fclose(p);
    return escribo;
}

void Archivo_pasajeros::listar(){
    Pasajeros pasajero;
    int contreg=contarRegistros();
    for(int i=0; i<contreg; i++){
        pasajero=leerRegistros(i);
        if(pasajero.gethabilitado()){
            pasajero.mostrar();
            cout<<endl;
        }
    }
}
