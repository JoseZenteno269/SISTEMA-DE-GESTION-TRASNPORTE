#include<iostream>
#include "ARCHIVO_USUARIOS.h"
#include<cstring>

using namespace std;

Archivo_usuarios::Archivo_usuarios(const char *a){strcpy(archivo,a);}

int Archivo_usuarios::contarRegistros(){
    FILE *p=fopen(archivo, "rb");
    if(p==nullptr){
        cout<<"no exite el erchivo"<<endl;
        return -1;
    }
    fseek(p,0,2);
    int bytes=ftell(p);
    fclose(p);
    return bytes/sizeof (Usuarios);
}

int Archivo_usuarios::buscarRegistro(int idu){
    Usuarios u;
    int contreg=contarRegistros();
    for(int i=0; i<contreg; i++){
        u=leerRegistros(i);
        if(u.getidUsuario()==idu){
            return i;
        }
    }
    return -2;
}

Usuarios Archivo_usuarios::leerRegistros(int pos){
    FILE *p=fopen(archivo, "rb");
    Usuarios u;
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

bool Archivo_usuarios::grabarRegistro(Usuarios u){
    FILE *p=fopen(archivo, "ab");
    if(p==nullptr){
        return false;
    }
    bool escribo=fwrite(&u, sizeof u, 1, p);
    fclose(p);
    return escribo;
}

bool Archivo_usuarios::modificarRegistro(Usuarios u, int pos){
    FILE *p=fopen(archivo, "rb+");
    if(p==nullptr){
        return false;
    }
    fseek(p, pos*sizeof u, 0);
    bool escribo=fwrite(&u, sizeof u, 1, p);
    fclose(p);
    return escribo;
}

void Archivo_usuarios::listar(){
    Usuarios u;
    int contreg=contarRegistros();
    for(int i=0; i<contreg; i++){
        u=leerRegistros(i);
        if(u.getestado()){
            u.mostrar();
            cout<<endl;
        }
    }
}

