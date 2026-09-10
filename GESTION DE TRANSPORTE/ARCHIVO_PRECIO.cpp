#include<iostream>
#include<cstring>
#include "ARCHIVO_PRECIO.h"

using namespace std;

Archivo_Precio::Archivo_Precio(const char *a){
    strcpy(archivo, a);
    FILE *p = fopen(archivo, "rb"); // intento abrir en modo lectura
    if(p == nullptr){               // si no existe, lo creo vacío
        p = fopen(archivo, "wb");  // crear archivo vacío
    }
    if(p) fclose(p);
}

Precio Archivo_Precio::leerRegistros(){
    FILE *p=fopen(archivo, "rb");
    Precio precio;
    if(p==nullptr){
        precio.setPrecio(-1);
        return precio;
    }
    fseek(p, 0*sizeof precio, 0);
    precio.setPrecio(-2);
    fread(&precio, sizeof precio, 1, p);
    fclose(p);
    return precio;
}

bool Archivo_Precio::grabarRegistro(Precio precio){
    FILE *p=fopen(archivo, "wb");
    if(p==nullptr){
        return false;
    }
    bool escribo=fwrite(&precio, sizeof precio, 1, p);
    fclose(p);
    return escribo;
}

void Archivo_Precio::listar(){
    FILE *p=fopen(archivo, "rb");
    if(p==nullptr) {
        cout<<"No se pudo abrir el archivo."<<endl;
        return;
    }

    Precio precio;
    while(fread(&precio, sizeof precio, 1, p)==1){
        precio.mostrar();
    }
    fclose(p);
}
