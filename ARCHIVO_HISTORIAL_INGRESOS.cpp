#include<iostream>
#include "ARCHIVO_HISTORIAL_INGRESOS.h"
#include<cstring>

using namespace std;

Archivo_historial_usuarios::Archivo_historial_usuarios(const char *ah){strcpy(archivo_historial, ah); }

int Archivo_historial_usuarios::contarRegistros(){
    FILE *p=fopen(archivo_historial, "rb");
    if(p==nullptr){
        cout<<"no se ingreso al archivo"<<endl;
        return -1;
    }
    fseek(p, 0, 2);
    int bytes=ftell(p);
    fclose(p);
    return bytes/sizeof(Historial_ingreso);
}

int Archivo_historial_usuarios::buscarRegistro(int idu){
    Historial_ingreso historial;
    int contreg=contarRegistros();
    for(int i=0; i<contreg; i++){
        historial=leerRegistros(i);
        if(historial.getidusuario()==idu){
            return i;
        }
    }
    return -2;
}

Historial_ingreso Archivo_historial_usuarios::leerRegistros(int pos){
    FILE *p=fopen(archivo_historial, "rb");
    Historial_ingreso historial;
    if(p==nullptr){
        historial.setidusuario(-3);
        return historial;
    }
    fseek(p, pos*sizeof (Historial_ingreso), 0);
    historial.setidusuario(-4);
    fread(&historial, sizeof (Historial_ingreso), 1, p);
    fclose(p);
    return historial;
}

bool Archivo_historial_usuarios::grabarRegistro(Historial_ingreso historial){
    FILE *p=fopen(archivo_historial, "ab");
    if(p==nullptr){
        return false;
    }
    bool escribo=fwrite(&historial, sizeof(Historial_ingreso), 1, p);
    fclose(p);
    return escribo;
}

void Archivo_historial_usuarios::listar(){
    Historial_ingreso historial;
    int contreg=contarRegistros();
    for(int i=0; i<contreg; i++){
        historial=leerRegistros(i);
        historial.mostrar();
        cout<<endl;
    }
}
