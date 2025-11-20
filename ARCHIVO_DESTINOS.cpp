#include<iostream>
#include "ARCHIVO_DESTINOS.h"
#include<cstring>

using namespace std;

Archivo_destino::Archivo_destino (const char *a){
    strcpy(archivo, a);
    FILE *p = fopen(archivo, "rb"); // intento abrir en modo lectura
    if(p == nullptr){               // si no existe, lo creo vacío
        p = fopen(archivo, "wb");  // crear archivo vacío
    }
    if(p) fclose(p);
}

int Archivo_destino::contarRegistros(){
    FILE *p=fopen(archivo,"rb");
    if(p==nullptr){
        cout<<"no existe el archivo"<<endl;
        return -1;
    }
    fseek(p,0,2);
    int bytes=ftell(p);
    fclose(p);
    return bytes/sizeof(Destino);
}

int Archivo_destino::buscarRegistros(int idd){
    Destino destino;
    int contreg=contarRegistros();
    for(int i=0; i<contreg; i++){
        destino=leerRegistros(i);
        if(destino.getidDestino()==idd){
            return i;
        }
    }
    return -2;
}

Destino Archivo_destino::leerRegistros(int pos){
    FILE *p=fopen(archivo,"rb");
    Destino destino;
    if(p==nullptr){
        destino.setidDestino(-3);
        return destino;
    }
    fseek(p,pos*sizeof destino,0);
    destino.setidDestino(-4);
    fread(&destino,sizeof destino,1,p);
    fclose(p);
    return destino;
}

bool Archivo_destino::grabarRegistro(Destino destino){
    FILE *p=fopen(archivo,"ab");
    if(p==nullptr){
        return false;
    }
    bool escribo=fwrite(&destino, sizeof destino,1,p);
    fclose(p);
    return escribo;
}

bool Archivo_destino::modificarRegistro(Destino destino ,int pos){
    FILE *p=fopen(archivo,"rb+");
    if(p==nullptr){
        return false;
    }
    fseek (p,pos*sizeof destino,0);
    bool escribo=fwrite(&destino, sizeof destino,1,p);
    fclose(p);
    return escribo;
}

void Archivo_destino::listar(){
    Destino destino;
    int contreg=contarRegistros();
    for(int i=0;i<contreg;i++){
        destino=leerRegistros(i);
        if(destino.gethabilitado()){
            destino.mostrar();
            cout<<endl;
        }
    }
}
