#include<iostream>
#include "ARCHIVO_VIAJES.h"
#include<cstring>
#include "rlutil.h"

using namespace rlutil;
using namespace std;

Archivo_viaje::Archivo_viaje(const char *a){
    strcpy(archivo, a);
    FILE *p=fopen(archivo, "rb"); // intento abrir en modo lectura
    if(p==nullptr){               // si no existe, lo creo vacío
        p=fopen(archivo, "wb");  // crear archivo vacío
    }
    if(p) fclose(p);
}

int Archivo_viaje::contarRegistros(){
    FILE *p=fopen(archivo,"rb");
    if (p==nullptr){
        cout<<"no existe el archivo"<<endl;
        return -1;
    }
    fseek(p,0,2);
    int bytes=ftell(p);
    fclose(p);
    return bytes/sizeof(Viaje);
}
int Archivo_viaje::buscarRegistro(int idv){
    Viaje viaje;
    int contreg=contarRegistros();
    for (int i=0;i<contreg;i++){
        viaje=leerRegistros(i);
        if(viaje.getIdViaje()==idv){
            return i;
        }
    }
    return -2;
}

Viaje Archivo_viaje::leerRegistros(int pos){
    FILE *p=fopen(archivo,"rb");
    Viaje viaje;
    if(p==nullptr){
        viaje.setIdViaje(-3);
        return viaje;
    }
    fseek(p,pos*sizeof viaje,0);
    viaje.setIdViaje(-4);
    fread(&viaje,sizeof viaje,1,p);
    fclose(p);
    return viaje;

}
bool Archivo_viaje::grabarRegistro(Viaje viaje){
    FILE *p=fopen(archivo,"ab");
    if(p==nullptr){
        return false;
    }
bool escribo=fwrite(&viaje,sizeof viaje,1,p);
fclose(p);
return escribo;
}
bool Archivo_viaje::modificarRegistro(Viaje viaje, int pos){
    FILE *p=fopen(archivo,"rb+");
    if(p==nullptr){
        return false;
    }
    fseek(p,pos*sizeof viaje,0 );
    bool escribo=fwrite(&viaje,sizeof viaje,1,p);
    fclose (p);
    return escribo;
}

void Archivo_viaje::listar(){
    Viaje viaje;
    int contreg=contarRegistros();
    for(int i=0;i<contreg;i++){
        viaje=leerRegistros(i);
        if(viaje.getRealizado()){
            viaje.mostrar();
            cout<<endl;
        }
    }
}

void Archivo_viaje::listartabla(){
    Viaje viaje;
    bool mostrar=false;
    int contreg=contarRegistros();

    for(int i=0;i<contreg;i++){
        viaje=leerRegistros(i);
        if(viaje.getRealizado()){
            viaje.listartabla();

        }
    }
}

