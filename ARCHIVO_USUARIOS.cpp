#include<iostream>
#include "ARCHIVO_USUARIOS.h"
#include<cstring>

using namespace std;

Archivo_usuario::Archivo_usuario(const char *a){
    strcpy(archivo, a);
    FILE *p = fopen(archivo, "rb"); // intento abrir en modo lectura
    if(p == nullptr){               // si no existe, lo creo vacío
        p = fopen(archivo, "wb");  // crear archivo vacío
    }
    if(p) fclose(p);
}

int Archivo_usuario::contarRegistros(){
    FILE *p=fopen(archivo, "rb");
    if(p==nullptr){
        cout<<"no exite el erchivo"<<endl;
        return -1;
    }
    fseek(p,0,2);
    int bytes=ftell(p);
    fclose(p);
    return bytes/sizeof(Usuario);
}

int Archivo_usuario::buscarRegistro(int idu){
    Usuario u;
    int contreg=contarRegistros();
    for(int i=0; i<contreg; i++){
        u=leerRegistros(i);
        if(u.getidUsuario()==idu){
            return i;
        }
    }
    return -2;
}

Usuario Archivo_usuario::leerRegistros(int pos){
    FILE *p=fopen(archivo, "rb");
    Usuario u;
    if(p==nullptr){
        u.setidUsuario(-3);
        return u;
    }
    fseek(p, pos*sizeof u, 0);
    u.setidUsuario(-4);
    fread(&u, sizeof u, 1, p);
    fclose(p);
    return u;
}

bool Archivo_usuario::grabarRegistro(Usuario u){
    FILE *p=fopen(archivo, "ab");
    if(p==nullptr){
        return false;
    }
    bool escribo=fwrite(&u, sizeof u, 1, p);
    fclose(p);
    return escribo;
}

bool Archivo_usuario::modificarRegistro(Usuario u, int pos){
    FILE *p=fopen(archivo, "rb+");
    if(p==nullptr){
        return false;
    }
    fseek(p, pos*sizeof u, 0);
    bool escribo=fwrite(&u, sizeof u, 1, p);
    fclose(p);
    return escribo;
}

void Archivo_usuario::listar(){
    Usuario u;
    int contreg=contarRegistros();
    for(int i=0; i<contreg; i++){
        u=leerRegistros(i);
        if(u.getestado()){
            u.mostrar();
            cout<<endl;
        }
    }
}

