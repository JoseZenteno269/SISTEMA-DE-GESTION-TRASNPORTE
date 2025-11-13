#include<iostream>
#include "ARCHIVO_VIAJES.h"
#include"funciones.h"
#include<cstring>

using namespace std;

Archivo_viajes::Archivo_viajes(const char *a){
    strcpy(archivo, a);
    FILE *p=fopen(archivo, "rb"); // intento abrir en modo lectura
    if(p==nullptr){               // si no existe, lo creo vacío
        p=fopen(archivo, "wb");  // crear archivo vacío
    }
    if(p) fclose(p);
}

int Archivo_viajes::contarRegistros(){
    FILE *p=fopen(archivo,"rb");
    if (p==nullptr){
        cout<<"no existe el archivo"<<endl;
        return -1;
    }
    fseek(p,0,2);
    int bytes=ftell(p);
    fclose(p);
    return bytes/sizeof(Viajes);
}
int Archivo_viajes::buscarRegistro(int idv){
    Viajes viaje;
    int contreg=contarRegistros();
    for (int i=0;i<contreg;i++){
        viaje=leerRegistros(i);
        if(viaje.getidViaje()==idv){
            return i;
        }
    }
    return -2;
}

Viajes Archivo_viajes::leerRegistros(int pos){
    FILE *p=fopen(archivo,"rb");
    Viajes viaje;
    if(p==nullptr){
        viaje.setidViaje(-3);
        return viaje;
    }
    fseek(p,pos*sizeof viaje,0);
    viaje.setidViaje(-4);
    fread(&viaje,sizeof viaje,1,p);
    fclose(p);
    return viaje;

}
bool Archivo_viajes::grabarRegistro(Viajes viaje){
    FILE *p=fopen(archivo,"ab");
    if(p==nullptr){
        return false;
    }
bool escribo=fwrite(&viaje,sizeof viaje,1,p);
fclose(p);
return escribo;
}
bool Archivo_viajes::modificarRegistro(Viajes viaje, int pos){
    FILE *p=fopen(archivo,"rb+");
    if(p==nullptr){
        return false;
    }
    fseek(p,pos*sizeof viaje,0 );
    bool escribo=fwrite(&viaje,sizeof viaje,1,p);
    fclose (p);
    return escribo;
}

void Archivo_viajes::listar(){
    Viajes viaje;
    int contreg=contarRegistros();
    for(int i=0;i<contreg;i++){
        viaje=leerRegistros(i);
        if(viaje.getrealizado()){
            viaje.mostrar();
            cout<<endl;
        }
    }
}
void Archivo_viajes::listar_Disponibles(){
    Viajes viaje;
    int contreg=contarRegistros();

    Fechas actual;
    Tiempo_Actual tiempo;
    actual.setanio(tiempo.getAnio());
    actual.setmes(tiempo.getMes());
    actual.setdia(tiempo.getDia());

    for(int i=0;i<contreg;i++){
        viaje=leerRegistros(i);
        if(viaje.getrealizado() && esFechaPosterior(viaje.getfecha_Inicio_Viaje(), actual)){
            viaje.mostrar();
            cout<<endl;
        }
    }
}
