#include<iostream>
#include "ARCHIVO_MICROS.h"
#include<cstring>

using namespace std;

Archivo_micros::Archivo_micros(const char *a){strcpy(archivo,a); }

int Archivo_micros::contarRegistros(){
    FILE *p=fopen(archivo,"rb");
    if (p==nullptr){
        cout<<"no existe el archivo"<<endl;
        return -1;
    }
    fseek(p,0,2);
    int bytes=ftell(p);
    fclose(p);
    return bytes/sizeof(Micros);
}
int Archivo_micros::buscarRegsitro(int idm){
    Micros micro;
    int contreg=contarRegistros();
    for (int i=0;i<contreg;i++){
        micro=leerRegistros(i);
        if(micro.getidMicro()==idm){
            return i;
        }
    }
    return -2;
}

Micros Archivo_micros::leerRegistros(int pos){
    FILE *p=fopen(archivo,"rb");
    Micros micro;
    if(p==nullptr){
        micro.setidMicro(-3);
        return micro;
    }
    fseek(p,pos*sizeof micro,0);
    micro.setidMicro(-4);
    fread(&micro,sizeof micro,1,p);
    fclose(p);
    return micro;

}
bool Archivo_micros::grabarRegistro(Micros micro){
    FILE *p=fopen(archivo,"ab");
    if(p==nullptr){
        return false;
    }
bool escribo=fwrite(&micro,sizeof micro,1,p);
fclose(p);
return escribo;
}
bool Archivo_micros::modificarRegistro(Micros micro, int pos){
    FILE *p=fopen(archivo,"rb+");
    if(p==nullptr){
        return false;
    }
    fseek(p,pos*sizeof micro,0 );
    bool escribo=fwrite(&micro,sizeof micro,1,p);
    fclose (p);
    return escribo;
}

void Archivo_micros::listar(){
    Micros micro;
    int contreg=contarRegistros();
    for(int i=0;i<contreg;i++){
        micro=leerRegistros(i);
        if(micro.getdisponible()){
            micro.mostrar();
            cout<<endl;
        }
    }
}
