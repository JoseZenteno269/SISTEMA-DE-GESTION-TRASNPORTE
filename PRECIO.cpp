#include<iostream>
#include "PRECIO.h"
#include "funciones.h"
#include "rlutil.h"

using namespace rlutil;

using namespace std;

void Precio::setPrecio(float p){Precio=p; }
void Precio::setPreciobutaca_cama(float pca){Preciobutaca_cama=pca; }
void Precio::setPreciobutaca_comun(float pco){Preciobutaca_comun=pco; }
void Precio::setPreciobutaca_semicama(float psc){Preciobutaca_semicama=psc; }

float Precio::getPrecio(){return Precio; }
float Precio::getPreciobutaca_cama(){return Preciobutaca_cama; }
float Precio::getPreciobutaca_comun(){return Preciobutaca_comun; }
float Precio::getPreciobutaca_semicama(){return Preciobutaca_semicama; }

void Precio::cargar(){
    while(true){
        setColor(CYAN);
        locate(40,10); cout<<"Ingrese el Precio x Kilometro: ";
        setColor(WHITE);
        locate(40,11); cin>>Precio;

        if(validar_numero()){
            LimpiarLineas(10,12,40);
            break;
        }
    }

    while(true){
        setColor(CYAN);
        locate(40,10); cout<<"Ingrese el Precio butaca cama: ";
        setColor(WHITE);
        locate(40,11); cin>>Preciobutaca_cama;

        if(validar_numero()){
            LimpiarLineas(10,12,40);
            break;
        }

        setColor(RED);
        locate(40,12); cout << "Valor invalido. Intente nuevamente.";
        setColor(WHITE);
        anykey();
        LimpiarLineas(10,12,40);
    }

    while(true){
        setColor(CYAN);
        locate(40,10); cout<<"Ingrese el Precio butaca semi-cama: ";
        setColor(WHITE);
        locate(40,11); cin>>Preciobutaca_semicama;

        if(validar_numero()){
            LimpiarLineas(10,12,40);
            break;
        }

        setColor(RED);
        locate(40,12); cout<<"Valor invalido. Intente nuevamente.";
        setColor(WHITE);
        anykey();
        LimpiarLineas(10,12,40);
    }

    while(true){
        setColor(CYAN);
        locate(40,10); cout<<"Ingrese el Precio butaca comun: ";
        setColor(WHITE);
        locate(40,11); cin>>Preciobutaca_comun;

        if(validar_numero()){
            LimpiarLineas(10,12,40);
            break;
        }

        setColor(RED);
        locate(40,12); cout<<"Valor invalido. Intente nuevamente.";
        setColor(WHITE);
        anykey();
        LimpiarLineas(10,12,40);
    }
}
void Precio::mostrar(){
    cls();
    setColor(YELLOW);
    locate(40,3); cout<<"----------------------------------------------";
    locate(40,4); cout<<"                    PRECIOS                   ";
    locate(40,5); cout<<"----------------------------------------------";
    setColor(WHITE);

    locate(40,6); cout<<"Precio x Kilomretro:           "<<"$"<<Precio;
    locate(40,7); cout<<"Precio x butaca cama:          "<<"$"<<Preciobutaca_cama;
    locate(40,8); cout<<"Precio x butaca semi-cama:     "<<"$"<<Preciobutaca_semicama;
    locate(40,9); cout<<"Precio x butaca comun:         "<<"$"<<Preciobutaca_comun;

    setColor(WHITE);
    anykey();
    cls();
    //LimpiarLineas(6,10,40);
}
