#include<iostream>
#include "USUARIOS.h"
#include<cstring>
#include "funciones.h"

using namespace std;


void Usuarios::setidUsuario(int idu){idUsuario=idu;}
void Usuarios::setcontrasena(const char *c){strcpy(contrasena, c); }
void Usuarios::setingreso(Fechas i){ingreso=i; }
void Usuarios::setestado(bool e){estado=e; }

int Usuarios::getidUsuario(){return idUsuario; }
const char *Usuarios::getcontrasena(){return contrasena; }
Fechas Usuarios::getingreso(){return ingreso; }
bool Usuarios::getestado(){return estado; }

void Usuarios::cargar(int idu){
    cout<<"ingrese ID de usuario: "<<(idUsuario=idu)<<endl;
    Personas::cargar();
    cout<<"ingrese fecha de ingreso: "<<endl;
    ingreso.cargar();
    cout<<"Crear contraseña: "; cargarCadena(contrasena, 29);
    estado=true;
}

void Usuarios::mostrar(){
    cout<<"ID de usuario: "<<idUsuario<<endl;
    cout<<"contraseña: "<<contrasena<<endl;
    Personas::mostrar();
    cout<<"Fecha de ingreso: "<<endl;
    ingreso.mostrar();
}
