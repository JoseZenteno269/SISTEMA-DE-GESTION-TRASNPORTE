#include<iostream>
#include "ARCHIVO_HISTORIAL_INGRESOS.h"
#include<cstring>

using namespace std;

Archivo_historial_usuarios::Archivo_historial_usuarios(const char *ah){strcpy(archivo_historial, ah); }

void Archivo_historial_usuarios::setidusuario(int idu){idusuario=idu;}
void Archivo_historial_usuarios::setingreso_sesion(Fechas is){ingreso_sesion=is; }
void Archivo_historial_usuarios::setinicio(Hora i){inicio=i; }
void Archivo_historial_usuarios::setnombre_usuario(const char *nu){strcpy(nombre_usuario,nu); }

int Archivo_historial_usuarios::getidusuario(){return idusuario; }
Fechas Archivo_historial_usuarios::getingreso_sesion(){return ingreso_sesion; }
Hora Archivo_historial_usuarios::getinicio(){return inicio; }
const char *Archivo_historial_usuarios::getnombre_usuario(){return nombre_usuario; }

int Archivo_historial_usuarios::contarRegistros(){
    FILE *p=fopen(archivo_historial, "rb");
    if(p==nullptr){
        cout<<"no se ingreso al archivo"<<endl;
        return -1;
    }
    fseek(p, 0, 2);
    int bytes=ftell(p);
    fclose(p);
    return bytes/sizeof(Archivo_historial_usuarios);
}

int Archivo_historial_usuarios::buscarRegistro(int idu){
    Archivo_historial_usuarios archivo;
    int contreg=contarRegistros();
    for(int i=0; i<contreg; i++){
        archivo=leerRegistros(i);
        if(archivo.getidusuario()==idu){
            return i;
        }
    }
    return -2;
}

Archivo_historial_usuarios Archivo_historial_usuarios::leerRegistros(int pos){
    FILE *p=fopen(archivo_historial, "rb");
    Archivo_historial_usuarios historial;
    if(p==nullptr){
        historial.setidusuario(-3);
        return historial;
    }
    fseek(p, pos*sizeof (Archivo_historial_usuarios), 0);
    historial.setidusuario(-4);
    fread(&historial, sizeof (Archivo_historial_usuarios), 1, p);
    fclose(p);
    return historial;
}

bool Archivo_historial_usuarios::grabarRegistro(){
    FILE *p=fopen(archivo_historial, "ab");
    if(p==nullptr){
        return false;
    }
    bool escribo=fwrite(this, sizeof (Archivo_historial_usuarios), 1, p);
    fclose(p);
    return escribo;
}


void Archivo_historial_usuarios::mostrar(){
    cout<<"=============================="<<endl;
    cout<<"ID de usuario: "<<idusuario<<endl;
    cout<<"Nombre: "<<nombre_usuario<<endl;
    cout<<"Fecha:"<<endl;
    ingreso_sesion.mostrar();
    cout<<"Hora de ingreso: ";
    inicio.mostrar();
    cout<<"=============================="<<endl;
}

void Archivo_historial_usuarios::listar(){
    Archivo_historial_usuarios historial;
    int contreg=contarRegistros();
    for(int i=0; i<contreg; i++){
        historial=leerRegistros(i);
        historial.mostrar();
        cout<<endl;
    }
}
