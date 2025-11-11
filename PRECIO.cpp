#include<iostream>
#include "PRECIO.h"

using namespace std;

void PrecioxKilometro::setPrecio(float p){Precio=p; }

int PrecioxKilometro::getPrecio(){return Precio;}

void PrecioxKilometro::cargar(){cout<<"Ingrese el Precio x Kilometro: "; cin>>Precio; }
void PrecioxKilometro::mostrar(){cout<<"Precio x Kilomretro: "<<Precio<<endl; }
