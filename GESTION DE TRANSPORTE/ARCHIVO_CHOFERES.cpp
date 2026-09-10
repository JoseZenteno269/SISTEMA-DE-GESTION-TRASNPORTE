#include<iostream>
#include "ARCHIVO_CHOFERES.h"
#include<cstring>

using namespace std;

Archivo_chofer::Archivo_chofer(const char *a){
    strcpy(archivo, a);
    FILE *p = fopen(archivo, "rb"); // intento abrir en modo lectura
    if(p == nullptr){               // si no existe, lo creo vacío
        p = fopen(archivo, "wb");  // crear archivo vacío
    }
    if(p) fclose(p);
}

int Archivo_chofer::contarRegistros(){
    FILE *p=fopen(archivo, "rb");
    if(p==nullptr){
        cout<<"no existe el archivo"<<endl;
        return -1;
    }
    fseek(p,0,2);
    int bytes=ftell(p);
    fclose(p);
    return bytes/sizeof(Chofer);
}

int Archivo_chofer::buscarRegistro(int leg){
    Chofer chofer;
    int contreg=contarRegistros();
    for(int i=0; i<contreg; i++){
        chofer=leerRegistros(i);
        if(chofer.getLegajo()==leg){
            return i;
        }
    }
    return -2;
}

Chofer Archivo_chofer::leerRegistros(int pos){
    FILE *p=fopen(archivo, "rb");
    Chofer chofer;
    if(p==nullptr){
        chofer.setLegajo(-3);
        return chofer;
    }
    fseek(p, pos*sizeof chofer, 0);
    chofer.setLegajo(-4);
    fread(&chofer, sizeof chofer, 1, p);
    fclose(p);
    return chofer;
}

bool Archivo_chofer::grabarRegistro(Chofer chofer){
    FILE *p=fopen(archivo, "ab");
    if(p==nullptr){
        return false;
    }
    bool escribo=fwrite(&chofer, sizeof chofer, 1, p);
    fclose(p);
    return escribo;
}

bool Archivo_chofer::modificarRegistro(Chofer chofer, int pos){
    FILE *p=fopen(archivo, "rb+");
    if(p==nullptr){
        return false;
    }
    fseek(p, pos*sizeof chofer, 0);
    bool escribo=fwrite(&chofer, sizeof chofer, 1, p);
    fclose(p);
    return escribo;
}

void Archivo_chofer::listar(){
    Chofer chofer;
    int contreg=contarRegistros();
    for(int i=0; i<contreg; i++){
        chofer=leerRegistros(i);
        if(chofer.getEstado()){
            chofer.mostrar();
            cout<<endl;
        }
    }
}
