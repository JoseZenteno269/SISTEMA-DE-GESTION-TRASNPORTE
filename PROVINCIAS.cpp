#include <iostream>
#include "PROVINCIAS.h"
#include <cstring>
#include "funciones.h"
#include "ARCHIVO_PROVINCIAS.h"

using namespace std;

void Provincia::setNombre(const char *n){strcpy(nombre,n);}
void Provincia::setcodigo_provincias(const char *cdp){strcpy(codigo_provincias, cdp); }
void Provincia::setidprovincia(int idp){idprovincia=idp; }

const char *Provincia::getNombre(){return nombre;}
const char *Provincia::getcodigo_provincias(){return codigo_provincias; }
int Provincia::getidprovincia(){return idprovincia; }

void Provincia::cargar(){
    cout<<"ingrese el nombre de la provincia: "; cargarCadena(nombre,39);
    cout<<"ingrese Codigo de provincia: "; cargarCadena(codigo_provincias, 4);
    Archivo_provincias archivo;
    idprovincia=archivo.contarRegistros();
}
void Provincia::mostrar(){
    cout<<"============================================"<<endl;
    cout<<"Nombre de la provincia: "<<nombre<<endl;
    cout<<"Codigo de provincia: "<<codigo_provincias<<endl;
    cout<<"ID de provincia: "<<idprovincia<<endl;
    cout<<"============================================"<<endl;
}
