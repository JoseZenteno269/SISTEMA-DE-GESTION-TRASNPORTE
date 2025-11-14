#include<iostream>
#include "PERSONA.h"
#include "funciones.h"
#include<cstring>

using namespace std;

void Personas::setnombre(const char *n){strcpy(nombre, n); }
void Personas::setapellido(const char *a){strcpy(apellido, a); }
void Personas::setdni(long long d){dni=d; }
void Personas::settelefono(long long t){telefono=t; }
void Personas::setemail(const char *e){strcpy(email,e);}
void Personas::setgenero(int g){genero=g;}
void Personas::setnacionalidad(const char *nac){strcpy(nacionalidad, nac); }
void Personas::setfecha_Nacimiento(Fechas f){fecha_Nacimiento = f;}
void Personas::setdomicilio(Domicilio d){domicilio=d;}


const char *Personas::getnombre(){return nombre; }
const char *Personas::getapellido(){return apellido; }
long long Personas::getdni(){return dni; }
long long Personas::gettelefono(){return telefono; }
const char *Personas::getemail(){return email;}
int Personas::getgenero(){return genero;}
const char *Personas::getnacionalidad(){return nacionalidad; }
Fechas Personas::getfecha_Nacimiento(){return fecha_Nacimiento;}
Domicilio Personas::getdomicilio(){return domicilio;}

const char* Personas::getgenerotexto()const{
    switch(genero){
    case 1: return "Masculino";
        break;
    case 2: return "Femenino";
        break;
    case 3: return "No binario";
        break;
    default: return "Desconocido";
        break;
    }
}
void Personas::cargar(){
    while(true){
        cout<<"ingrese nombre: "; cargarCadena(nombre, 39);
        if(validarPalabra(nombre))break;
    }

    while(true){
        cout<<"ingrese apellido: "; cargarCadena(apellido, 39);
        if(validarPalabra(apellido))break;
    }

    while(true){
        cout<<"ingrese DNI (7-11 digitos): "; cin>>dni;
        int longitud=to_string(dni).length();
        if(validar_numero() and longitud>=7 and longitud<=11) break;
    }

    while(true){
        cout<<"ingrese N° de contacto (10 digitos): "; cin>>telefono;
        int longitud=to_string(telefono).length();
        if(validar_numero() and longitud==10) break;
    }

    cout<<"ingrese su email: "; cargarCadena(email, 99);

    while(true){
        cout<<"ingrese su genero(1=masculino, 2=femenino, 3=no binario) : "; cin>>genero;
        if(validar_numero() and (genero==1 or genero==2 or genero==3))break;
    }

    while(true){
        cout<<"ingrese su nacionalidad: "; cargarCadena(nacionalidad, 39);
        if(validarPalabra(nacionalidad))break;
    }

    cout<<"ingrese fecha de nacimiento"<<endl;
    fecha_Nacimiento.cargar();
    cout<<"ingrese su domicilio: "<<endl;
    domicilio.Cargar();

}
void Personas::mostrar(){
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Apellido: "<<apellido<<endl;
    cout<<"N° de DNI: "<<dni<<endl;
    cout<<"N° de contacto: "<<telefono<<endl;
    cout<<"Email: "<<email<<endl;
    cout<<"genero: "<<getgenerotexto()<<endl;
    cout<<"Nacionalidad: "<<nacionalidad<<endl;
    cout<<"Fecha de nacimiento: ";
    fecha_Nacimiento.mostrar();
    cout<<"Datos Domicilio"<<endl;
    domicilio.Mostrar();
}

