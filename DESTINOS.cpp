#include<iostream>
#include "DESTINOS.h"
#include "funciones.h"
#include<cstring>
#include "rlutil.h"

using namespace rlutil;
using namespace std;

void Destino::setIdDestino(int idd){idDestino=idd; }
void Destino::setNombre_provincia(const char *p){strcpy(nombre_provincia, p); }
void Destino::setNombre_destino(const char *nd){strcpy(nombre_destino, nd); }
void Destino::setDistanciaKm(float dkm){distanciaKm=dkm; }
void Destino::setDuracion(Hora hd){duracion=hd; }
void Destino::setHabilitado(bool h){habilitado=h; }

int Destino::getIdDestino(){return idDestino; }
const char*Destino::getNombre_provincia(){return nombre_provincia; }
const char *Destino::getNombre_destino(){return nombre_destino; }
float Destino::getDistanciaKm(){return distanciaKm; }
Hora Destino::getDuracion(){return duracion; }
bool Destino::getHabilitado(){return habilitado; }

void Destino::cargar(int idd){
    cls();

    setColor(GREEN);
    locate(40,3);  cout << "----------------------------------------------";
    locate(40,4);  cout << "            CARGA DE NUEVO DESTINO            ";
    locate(40,5);  cout << "----------------------------------------------";
    setColor(WHITE);

    locate(40,7);
    cout << "ID de destino asignado: " << (idDestino = idd);

    setColor(GREEN);
    locate(40,8); cout << "----------------- DATOS DEL DESTINO -----------------";
    setColor(WHITE);

    while(true){
        setColor(CYAN);
        locate(40,10); cout << "Ingrese nombre de provincia: ";
        setColor(WHITE);
        locate(40,11); cargarCadena(nombre_provincia,39);

        bool bandera = false;

      for(int i=1; i<=23; i++){
        if(strcmp(funcion_provincias(i,1), nombre_provincia) == 0) bandera = true;
        if(strcmp(funcion_provincias(i,2), nombre_provincia) == 0) bandera = true;
        if(strcmp(funcion_provincias(i,3), nombre_provincia) == 0) bandera = true;
    }
        if(bandera){
            LimpiarLineas(10,15,40);
            break;
        }

        setColor(RED);
        locate(40,13); cout << "Provincia invalida. Intente nuevamente.";
        setColor(WHITE);
        anykey();
        LimpiarLineas(10,15,40);
    }

    setColor(CYAN);
    locate(40,10); cout << "Ingrese lugar de destino: ";
    setColor(WHITE);
    locate(40,11); cargarCadena(nombre_destino,39);
    LimpiarLineas(10,15,40);

    setColor(CYAN);
    locate(40,10); cout << "Ingrese hora de duracion de viaje: ";
    setColor(WHITE);
    locate(40,11); duracion.cargar_viaje();
    LimpiarLineas(10,15,40);

    while(true){
        setColor(CYAN);
        locate(40,10); cout << "Ingrese distancia en KM: ";
        setColor(WHITE);
        locate(40,11); cin >> distanciaKm;

        if(validar_numero()){
            LimpiarLineas(10,15,40);
            break;
        }

        setColor(RED);
        locate(40,13); cout << "Valor invalido. Intente nuevamente.";
        setColor(WHITE);
        anykey();
        LimpiarLineas(10,15,40);
    }

    habilitado = true;

    cls();
}
void Destino::mostrar(int X, int Y){
    setColor(YELLOW);
    locate(X, Y);     cout << "----------------------------------------------";
    locate(X, Y + 1); cout << "             INFORMACION DEL DESTINO           ";
    locate(X, Y + 2); cout << "----------------------------------------------";
    setColor(WHITE);

    locate(X, Y + 4);  setColor(CYAN); cout << "ID de destino: "; locate(X+30, Y+4); setColor(WHITE); cout << idDestino;
    locate(X, Y + 5);  setColor(CYAN); cout << "Provincia: "; locate(X+30, Y+5); setColor(WHITE); cout << nombre_provincia;
    locate(X, Y + 6);  setColor(CYAN); cout << "Lugar de destino: "; locate(X+30, Y+6); setColor(WHITE); cout << nombre_destino;
    locate(X, Y + 7);  setColor(CYAN); cout << "Duracion del viaje: "; setColor(WHITE); duracion.mostrar(X + 10, Y + 7);
    locate(X, Y + 8);  setColor(CYAN); cout << "Distancia (KM): "; locate(X+30, Y+8);setColor(WHITE); cout << distanciaKm;

    anykey();
    LimpiarLineas(Y + 4, Y + 8, X);
}
