#include<iostream>
#include "PERSONA.h"
#include "funciones.h"
#include<cstring>

using namespace std;

void Personas::setnombre(const char *n){strcpy(nombre, n); }
void Personas::setapellido(const char *a){strcpy(apellido, a); }
void Personas::setdni(int d){dni=d; }
void Personas::settelefono(int t){telefono=t; }
void Personas::setemail(const char *e){strcpy(email,e);}
void Personas::setgenero(int g){genero=g;}
void Personas::setfecha_Nacimiento(Fechas f){fecha_Nacimiento = f;}
void Personas::setdomicilio(Domicilio d){domicilio=d;}


const char *Personas::getnombre(){return nombre; }
const char *Personas::getapellido(){return apellido; }
int Personas::getdni(){return dni; }
int Personas::gettelefono(){return telefono; }
const char *Personas::getemail(){return email;}
int Personas::getgenero(){return genero;}
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
    cout<<"ingrese nombre: "; cargarCadena(nombre, 39);
    cout<<"ingrese apellido: "; cargarCadena(apellido, 39);
    cout<<"ingrese DNI: "; cin>>dni;
    cout<<"ingrese N° de contacto: "; cin>>telefono;
    cout<<"ingrese su email: "; cargarCadena(email, 99);
    cout<<"ingrese su genero(1=masculino, 2=femenino, 3=no binario) : "; cin>>genero;
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
    cout<<"Fecha de nacimiento: "<<endl;
    fecha_Nacimiento.mostrar();
    cout<<"Domicilio: "<<endl;
    domicilio.Mostrar();
}

