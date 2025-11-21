#include<iostream>
#include<cstring>
#include "ARCHIVO_PROVINCIAS.h"

using namespace std;

Archivo_provincia::Archivo_provincia (const char *a){
    strcpy(archivo, a);
    FILE *p = fopen(archivo, "rb"); // intento abrir en modo lectura
    if(p == nullptr){               // si no existe, lo creo vacío
        p = fopen(archivo, "wb");  // crear archivo vacío
    }
    if(p) fclose(p);
}

int Archivo_provincia::contarRegistros(){
    FILE *p=fopen(archivo,"rb");
    if(p==nullptr){
        cout<<"no existe el archivo"<<endl;
        return -1;
    }
    fseek(p,0,2);
    int bytes=ftell(p);
    fclose(p);
    return bytes/sizeof(Provincia);
}

int Archivo_provincia::buscarRegistros(int cp){
    Provincia provincia;
    int contreg=contarRegistros();
    for(int i=0;i<contreg;i++){
        provincia=leerRegistros(i);
        if(provincia.getIdprovincia()==cp){
            return i;
        }
    }
}

Provincia Archivo_provincia::leerRegistros(int pos){
    FILE *p=fopen(archivo,"rb");
    Provincia provincia;
    if(p==nullptr){
        provincia.setIdprovincia(-3);
        return provincia;
    }
    fseek(p,pos*sizeof provincia,0);
    provincia.setIdprovincia(-4);
    fread(&provincia,sizeof provincia,1,p);
    fclose(p);
    return provincia;
}

bool Archivo_provincia::grabarRegistro(Provincia provincia){
    FILE *p=fopen(archivo,"ab");
    if(p==nullptr){
        return false;
    }
    bool escribo=fwrite(&provincia, sizeof provincia,1,p);
    fclose(p);
    return escribo;
}

bool Archivo_provincia::modificarRegistro(Provincia provincia ,int pos){
    FILE *p=fopen(archivo,"rb+");
    if(p==nullptr){
        return false;
    }
    fseek (p,pos*sizeof provincia,0);
    bool escribo=fwrite(&provincia, sizeof provincia,1,p);
    fclose(p);
    return escribo;
}

void Archivo_provincia::listar(){
    Provincia provincia;
    int contreg=contarRegistros();
    for(int i=0;i<contreg;i++){
        provincia=leerRegistros(i);
        provincia.mostrar();
        cout<<endl;
    }
}
