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
///void Personas::setgenero(string g){Genero gen=interpretar(g); genero=cargoGenero(g);}
void Personas::setfecha_Nacimiento(Fechas f){fecha_Nacimiento = f;}
void Personas::setdomicilio(Domicilio d){domicilio=d;}


const char *Personas::getnombre(){return nombre; }
const char *Personas::getapellido(){return apellido; }
int Personas::getdni(){return dni; }
int Personas::gettelefono(){return telefono; }
const char *Personas::getemail(){return email;}
///string Personas::getgenero(){return genero;}
Fechas Personas::getfecha_Nacimiento(){return fecha_Nacimiento;}
Domicilio Personas::getdomicilio(){return domicilio;}


void Personas::cargar(){
    cout<<"ingrese nombre: "; cargarCadena(nombre, 39);
    cout<<"ingrese apellido: "; cargarCadena(apellido, 39);
    cout<<"ingrese DNI: "; cin>>dni;
    cout<<"ingrese N° de contacto: "; cin>>telefono;
    cout<<"ingrese su email: "; cargarCadena(email, 99);
    ///cout<<"ingrese su genero: "; string g; getline(cin, g); setgenero(g);
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
    ///cout<<"genero: "<<genero<<endl;
    cout<<"Fecha de nacimiento: "<<endl;
    fecha_Nacimiento.mostrar();
    cout<<"Domicilio: "<<endl;
    domicilio.Mostrar();
}
