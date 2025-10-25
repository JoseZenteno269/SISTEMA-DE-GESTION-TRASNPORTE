#include<iostream>
#include<cstring>
#include "ARCHIVO_PROVINCIAS.h"

using namespace std;

Archivo_provincias::Archivo_provincias (const char *a){
    strcpy(archivo, a);
    FILE *p = fopen(archivo, "rb"); // intento abrir en modo lectura
    if(p == nullptr){               // si no existe, lo creo vacío
        p = fopen(archivo, "wb");  // crear archivo vacío
    }
    if(p) fclose(p);
}

int Archivo_provincias::contarRegistros(){
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

int Archivo_provincias::buscarRegistros(int cp){
    Provincia provincia;
    int contreg=contarRegistros();
    for(int i=0;i<contreg;i++){
        provincia=leerRegistros(i);
        if(provincia.getcodigo_provincias()==cp){
            return i;
        }
    }
}

Provincia Archivo_provincias::leerRegistros(int pos){
    FILE *p=fopen(archivo,"rb");
    Provincia provincia;
    if(p==nullptr){
        provincia.setcodigo_provincias(-3);
        return provincia;
    }
    fseek(p,pos*sizeof provincia,0);
    provincia.setcodigo_provincias(-4);
    fread(&provincia,sizeof provincia,1,p);
    fclose(p);
    return provincia;
}

bool Archivo_provincias::grabarRegistro(Provincia provincia){
    FILE *p=fopen(archivo,"ab");
    if(p==nullptr){
        return false;
    }
    bool escribo=fwrite(&provincia, sizeof provincia,1,p);
    fclose(p);
    return escribo;
}

bool Archivo_provincias::modificarRegistro(Provincia provincia ,int pos){
    FILE *p=fopen(archivo,"rb");
    if(p==nullptr){
        return false;
    }
    fseek (p,pos*sizeof provincia,0);
    bool escribo=fwrite(&provincia, sizeof provincia,1,p);
    fclose(p);
    return escribo;
}

void Archivo_provincias::listar(){
    Provincia provincia;
    int contreg=contarRegistros();
    for(int i=0;i<contreg;i++){
        provincia=leerRegistros(i);
        provincia.mostrar();
        cout<<endl;
    }
}
