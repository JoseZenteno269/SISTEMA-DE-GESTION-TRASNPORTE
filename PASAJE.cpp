#include<iostream>
#include<cstring>
#include "PASAJE.h"

using namespace std;

Pasajes::Pasajes(const char *p){strcpy(archivo, p); }

void Pasajes::setpasaje(int pasj){pasaje=pasj;}
void Pasajes::setidviaje(int idv){idviaje=idv; }
void Pasajes::setiddestino(int idd){iddestino=idd; }
void Pasajes::setlegajo_chofer(int leg){legajo_chofer=leg; }
void Pasajes::setidmicro(int idm){idmicro=idm; }
void Pasajes::setbutaca(int but){butaca=but; }
void Pasajes::settipo_butaca(const char* tb){strcpy(tipo_butaca, tb); }
void Pasajes::setfecha_Inicio(Fechas fi){fecha_Inicio=fi; }
void Pasajes::setfecha_Fin(Fechas ff){fecha_Fin=ff; }
void Pasajes::sethora_Inicio(Hora hi){hora_Inicio=hi; }
void Pasajes::sethora_Fin(Hora hf){hora_Fin=hf; }
void Pasajes::setnombre_destino(const char *nd){strcpy(nombre_destino, nd); }
void Pasajes::setprovincia_destino(const char * pd){strcpy(provincia_destino, pd); }

int Pasajes::getpasaje(){return pasaje; }
int Pasajes::getidviaje(){return idviaje; }
int Pasajes::getiddestino(){return iddestino; }
int Pasajes::getlegajo_chofer(){return legajo_chofer; }
int Pasajes::getidmicro(){return idmicro; }
int Pasajes::getbutaca(){return butaca; }
const char *Pasajes::gettipo_butaca(){return tipo_butaca; }
Fechas Pasajes::getfecha_Inicio(){return fecha_Inicio; }
Fechas Pasajes::getfecha_Fin(){return fecha_Fin; }
Hora Pasajes::gethora_Inicio(){return hora_Inicio; }
Hora Pasajes::gethora_Fin(){return hora_Fin; }
const char *Pasajes::getnombre_destino(){return nombre_destino; }
const char *Pasajes::getprovincia_destino(){return provincia_destino; }

int Pasajes::contarRegistros(){
    FILE *p=fopen(archivo, "rb");
    if(p==nullptr){
        cout<<"no se ingreso al archivo"<<endl;
        return -1;
    }
    fseek(p, 0, 2);
    int bytes=ftell(p);
    fclose(p);
    return bytes/sizeof(Pasajes);
}

int Pasajes::buscarRegistro(int pasj){
    Pasajes archivo;
    int contreg=contarRegistros();
    for(int i=0; i<contreg; i++){
        archivo=leerRegistros(i);
        if(archivo.getpasaje()==pasj){
            return i;
        }
    }
    return -2;
}

Pasajes Pasajes::leerRegistros(int pos){
    FILE *p=fopen(archivo, "rb");
    Pasajes archivo;
    if(p==nullptr){
        archivo.setpasaje(-3);
        return archivo;
    }
    fseek(p, pos*sizeof (Pasajes), 0);
    archivo.setpasaje(-4);
    fread(&archivo, sizeof (Pasajes), 1, p);
    fclose(p);
    return archivo;
}

bool Pasajes::grabarRegistro(){
    FILE *p=fopen(archivo, "ab");
    if(p==nullptr){
        return false;
    }
    bool escribo=fwrite(this, sizeof (Pasajes), 1, p);
    fclose(p);
    return escribo;
}

void Pasajes::mostrar(){
    cout<<"========================================"<<endl;
    cout<<"Numero de Pasaje: "<<pasaje<<endl;
    cout<<"ID de viaje: "<<idviaje<<endl;
    cout<<"ID de destino: "<<iddestino<<endl;
    cout<<"Legajo de Chofer: "<<legajo_chofer<<endl;
    cout<<"ID de Micro: "<<idmicro<<endl;
    cout<<"Numero de Butaca: "<<butaca<<endl;
    cout<<"Tipo de Butaca: "<<tipo_butaca<<endl;
    cout<<"Fecha de Inicio de Viaje: "<<endl; fecha_Inicio.mostrar();
    cout<<"Fecha de Fin Viaje: "<<endl; fecha_Fin.mostrar();
    cout<<"Hora de Inicio de Viaje"<<endl; hora_Inicio.mostrar();
    cout<<"Hora de Fin de Viaje: "<<endl; hora_Fin.mostrar();
    cout<<"Lugar de Destino: "<<nombre_destino<<endl;
    cout<<"Provincia de Destino: "<<provincia_destino<<endl;
    cout<<"========================================"<<endl;
}
void Pasajes::listar(){
    Pasajes archivo;
    int contreg=contarRegistros();
    for(int i=0; i<contreg; i++){
        archivo=leerRegistros(i);
        archivo.mostrar();
        cout<<endl;
    }
}
