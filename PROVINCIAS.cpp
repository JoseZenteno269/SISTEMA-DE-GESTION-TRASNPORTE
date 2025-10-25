#include <iostream>
#include "PROVINCIAS.h"
#include <cstring>
#include "funciones.h"
#include "ARCHIVO_PROVINCIAS.h"

using namespace std;

void Provincia::setNombre(const char *n){strcpy(nombre,n);}
void Provincia::setcodigo_provincias(int cdp){codigo_provincias=cdp; }

const char *Provincia::getNombre(){return nombre;}
int Provincia::getcodigo_provincias(){return codigo_provincias; }

void Provincia::cargar(){
    cout<<"ingrese el nombre de la provincia: "; cargarCadena(nombre,29);
    Archivo_provincias archivo;
    codigo_provincias=archivo.contarRegistros()+1;
}
void Provincia::mostrar(){}
