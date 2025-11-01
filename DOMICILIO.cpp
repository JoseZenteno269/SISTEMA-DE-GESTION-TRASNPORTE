#include<iostream>
#include "DOMICILIO.h"
#include "funciones.h"
#include<cstring>

using namespace std;

void Domicilio::setcalle(const char *c){strcpy(calle, c); }
void Domicilio::setaltura(int a){altura=a; }
void Domicilio::setcodigoPostal(const char *cp){strcpy(codigoPostal, cp); }
void Domicilio::setlocalidad(const char *l){strcpy(localidad, l); }
void Domicilio::setpartido(const char *p){strcpy(partido, p); }
void Domicilio::setprovincia(const char *prov){strcpy(provincia, prov); }

const char *Domicilio::getcalle(){return calle; }
int Domicilio::getaltura(){return altura; }
const char *Domicilio::getcodigoPostal(){return codigoPostal; }
const char *Domicilio::getlocalidad(){return localidad; }
const char *Domicilio::getpartido(){return partido; }
const char *Domicilio::getprovincia(){return provincia; }

void Domicilio::Cargar(){
    while(true){
        cout<<"INGRESE EL NOMBRE DE LA CALLE: "; cargarCadena(calle,29);
        if(validarPalabra(calle))break;
    }

    while(true){
        cout<<"INGRESE LA ALTURA: "; cin>>altura;
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
        }else{
            int longitud=to_string(altura).length();
            if(longitud>=2 and longitud<=6)break;
        }
    }

    cout<<"INGRESE EL CODIGO POSTAL: "; cargarCadena(codigoPostal,9);

    while(true){
        cout<<"INGRESE LA LOCALIDAD: "; cargarCadena(localidad,29);
        if(validarPalabra(localidad))break;
    }

    while(true){
        cout<<"INGRESE EL PARTIDO: "; cargarCadena(partido,29);
        if(validarPalabra(partido))break;
    }

    while(true){
        cout<<"INGRESE LA PROVINCIA: "; cargarCadena(provincia,29);
        if(validarPalabra(provincia))break;
    }
}

void Domicilio::Mostrar(){
    cout<<"CALLE: "<<calle<<endl;
    cout<<"ALTURA: "<<altura<<endl;
    cout<<"CODIGO POSTAL: "<<codigoPostal<<endl;
    cout<<"LOCALIDAD: "<<localidad<<endl;
    cout<<"PARTIDO: "<<partido<<endl;
    cout<<"PROVINCIA: "<<provincia<<endl;
}
