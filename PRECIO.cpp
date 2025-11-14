#include<iostream>
#include "PRECIO.h"
#include "funciones.h"

using namespace std;

void PrecioxKilometro::setPrecio(float p){Precio=p; }
void PrecioxKilometro::setPreciobutaca_cama(float pca){Preciobutaca_cama=pca; }
void PrecioxKilometro::setPreciobutaca_comun(float pco){Preciobutaca_comun=pco; }
void PrecioxKilometro::setPreciobutaca_semicama(float psc){Preciobutaca_semicama=psc; }

float PrecioxKilometro::getPrecio(){return Precio; }
float PrecioxKilometro::getPreciobutaca_cama(){return Preciobutaca_cama; }
float PrecioxKilometro::getPreciobutaca_comun(){return Preciobutaca_comun; }
float PrecioxKilometro::getPreciobutaca_semicama(){return Preciobutaca_semicama; }

void PrecioxKilometro::cargar(){
    while(true){
        cout<<"Ingrese el Precio x Kilometro: "; cin>>Precio;
        if(validar_numero())break;
    }
}
void PrecioxKilometro::mostrar(){cout<<"Precio x Kilomretro: "<<Precio<<endl; }

void PrecioxKilometro::cargarvalorbutaca(){
    while(true){
        cout<<"Ingrese el Precio butaca cama: "; cin>>Preciobutaca_cama;
        if(validar_numero())break;
    }

    while(true){
        cout<<"Ingrese el Precio butaca semi-cama: "; cin>>Preciobutaca_semicama;
        if(validar_numero())break;
    }

    while(true){
        cout<<"Ingrese el Precio butaca comun: "; cin>>Preciobutaca_comun;
        if(validar_numero())break;
    }
}

void PrecioxKilometro::mostrarvalorbutaca(){
    cout<<"Precio x butaca cama: "<<Preciobutaca_cama<<endl;
    cout<<"Precio x butaca semi-cama: "<<Preciobutaca_semicama<<endl;
    cout<<"Precio x butaca comun: "<<Preciobutaca_comun<<endl;
}
