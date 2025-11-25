#include <iostream>
#include "PROVINCIAS.h"
#include <cstring>
#include "funciones.h"
#include "ARCHIVO_PROVINCIAS.h"
#include "rlutil.h"

using namespace rlutil;
using namespace std;

void Provincia::setNombre(const char *n){strcpy(nombre,n);}

void Provincia::setIdprovincia(int idp){idprovincia=idp; }

const char *Provincia::getNombre(){return nombre;}

int Provincia::getIdprovincia(){return idprovincia; }

void Provincia::cargar(){
    bool oknorepite=false;
    bool ok=false;

    while(true){
        ok = false;
        oknorepite = true;

        cout<<"ingrese el nombre de la provincia: ";
        cargarCadena(nombre,39);

        for(int i=1;i<=23;i++){
            if (strcmp(nombre,funcion_provincias(i,1))==0) ok=true;
            if (strcmp(nombre,funcion_provincias(i,2))==0) ok=true;
            if (strcmp(nombre,funcion_provincias(i,3))==0) ok=true;
        }

        if(ok==true){

            Archivo_provincia archivo;
            Provincia P;
            int X = archivo.contarRegistros();

            for(int i=0;i<X;i++){
                P = archivo.leerRegistros(i);
                if(strcasecmp(nombre, P.getNombre())==0){
                    oknorepite = false;
                }
            }

            if(oknorepite==true){
                idprovincia = X+1;
                cout<<"PROVINCIA CARGADA CORRECTAMENTE"<<endl;
                cout<<"ID: "<<idprovincia<<endl;
                break;
            }
            else{
                cout<<"PROVINCIA YA EXISTENTE"<<endl;
            }
        }
    }
}

void Provincia::mostrar(){
    Archivo_provincia archivo;
    Provincia P;

    int total = archivo.contarRegistros();

    cls();

    setColor(GREEN);
    locate(40,2); cout << "----------------------------------------------";
    locate(40,3); cout << "             LISTADO DE PROVINCIAS            ";
    locate(40,4); cout << "----------------------------------------------";
    setColor(WHITE);

    if(total < 1){
        setColor(RED);
        locate(40,6); cout << "NO HAY PROVINCIAS REGISTRADAS";
        setColor(WHITE);
        anykey();
        return;
    }

    setColor(YELLOW);
    locate(40,6); cout << "ID";
    locate(70,6); cout << "PROVINCIA";
    setColor(WHITE);

    int fila = 8;

    for(int i = 0; i < total; i++){
        P = archivo.leerRegistros(i);

        locate(40, fila); cout << i+1;
        locate(65, fila); cout << P.getNombre();

        fila++;
    }

    anykey();
}
