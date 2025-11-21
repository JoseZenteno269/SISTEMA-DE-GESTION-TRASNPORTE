#include<iostream>
#include "ARCHIVO_HISTORIAL_INGRESOS.h"
#include<cstring>

using namespace std;

Archivo_historial_usuario::Archivo_historial_usuario(const char *ah){strcpy(archivo_historial, ah); }

int Archivo_historial_usuario::contarRegistros(){
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

int Archivo_historial_usuario::buscarRegistro(int idu){
    Historial_ingreso historial;
    int contreg=contarRegistros();
    for(int i=0; i<contreg; i++){
        historial=leerRegistros(i);
        if(historial.getIdusuario()==idu){
            return i;
        }
    }
    return -2;
}

Historial_ingreso Archivo_historial_usuario::leerRegistros(int pos){
    FILE *p=fopen(archivo_historial, "rb");
    Historial_ingreso historial;
    if(p==nullptr){
        historial.setIdusuario(-3);
        return historial;
    }
    fseek(p, pos*sizeof (Historial_ingreso), 0);
    historial.setIdusuario(-4);
    fread(&historial, sizeof (Historial_ingreso), 1, p);
    fclose(p);
    return historial;
}

bool Archivo_historial_usuario::grabarRegistro(Historial_ingreso historial){
    FILE *p=fopen(archivo_historial, "ab");
    if(p==nullptr){
        return false;
    }
    bool escribo=fwrite(&historial, sizeof(Historial_ingreso), 1, p);
    fclose(p);
    return escribo;
}

void Archivo_historial_usuario::listar(){
    Historial_ingreso historial;
    int contreg=contarRegistros();
    for(int i=0; i<contreg; i++){
        historial=leerRegistros(i);
        historial.mostrar();
        cout<<endl;
    }
}
