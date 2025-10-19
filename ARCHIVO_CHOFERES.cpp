#include<iostream>
#include "ARCHIVO_CHOFERES.h"
#include<cstring>

using namespace std;

Archivo_choferes::Archivo_choferes(const char *a){
    strcpy(archivo, a);
    FILE *p = fopen(archivo, "rb"); // intento abrir en modo lectura
    if(p == nullptr){               // si no existe, lo creo vacío
        p = fopen(archivo, "wb");  // crear archivo vacío
    }
    if(p) fclose(p);
}

int Archivo_choferes::contarRegistros(){
    FILE *p=fopen(archivo, "rb");
    if(p==nullptr){
        cout<<"no existe el archivo"<<endl;
        return -1;
    }
    fseek(p,0,2);
    int bytes=ftell(p);
    fclose(p);
    return bytes/sizeof(Choferes);
}

int Archivo_choferes::buscarRegistro(int leg){
    Choferes chofer;
    int contreg=contarRegistros();
    for(int i=0; i<contreg; i++){
        chofer=leerRegistros(i);
        if(chofer.getlegajo()==leg){
            return i;
        }
    }
    return -2;
}

Choferes Archivo_choferes::leerRegistros(int pos){
    FILE *p=fopen(archivo, "rb");
    Choferes chofer;
    if(p==nullptr){
        chofer.setlegajo(-3);
        return chofer;
    }
    fseek(p, pos*sizeof chofer, 0);
    chofer.setlegajo(-4);
    fread(&chofer, sizeof chofer, 1, p);
    fclose(p);
    return chofer;
}

bool Archivo_choferes::grabarRegistro(Choferes chofer){
    FILE *p=fopen(archivo, "ab");
    if(p==nullptr){
        return false;
    }
    bool escribo=fwrite(&chofer, sizeof chofer, 1, p);
    fclose(p);
    return escribo;
}

bool Archivo_choferes::modificarRegistro(Choferes chofer, int pos){
    FILE *p=fopen(archivo, "rb+");
    if(p==nullptr){
        return false;
    }
    fseek(p, pos*sizeof chofer, 0);
    bool escribo=fwrite(&chofer, sizeof chofer, 1, p);
    fclose(p);
    return escribo;
}

void Archivo_choferes::listar(){
    Choferes chofer;
    int contreg=contarRegistros();
    for(int i=0; i<contreg; i++){
        chofer=leerRegistros(i);
        if(chofer.getestado()){
            chofer.mostrar();
            cout<<endl;
        }
    }
}
