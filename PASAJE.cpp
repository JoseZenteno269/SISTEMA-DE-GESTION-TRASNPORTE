#include<iostream>
#include<cstring>
#include "PASAJE.h"
#include "rlutil.h"
#include "VIAJES.h"
#include "ARCHIVO_VIAJES.h"
#include "DESTINOS.h"
#include "ARCHIVO_DESTINOS.h"

using namespace rlutil;
using namespace std;

void Pasaje::setPasaje(int pasj){pasaje=pasj;}
void Pasaje::setIdviaje(int idv){idviaje=idv; }
void Pasaje::setButaca(int but){butaca=but; }
void Pasaje::setPrecio(float p){precio=p; }
void Pasaje::setTipo_butaca(const char* tb){strcpy(tipo_butaca, tb); }

int Pasaje::getPasaje(){return pasaje; }
int Pasaje::getIdviaje(){return idviaje; }
int Pasaje::getButaca(){return butaca; }
int Pasaje::getPrecio(){return precio; }
const char *Pasaje::getTipo_butaca(){return tipo_butaca; }

void Pasaje::mostrar(){
    Viaje viajes;
    Archivo_viaje archivoviaje;

    Destino destinos;
    Archivo_destino archivodestino;

    int contregviaje=archivoviaje.contarRegistros();

    for(int i=0; i<contregviaje; i++){
        viajes=archivoviaje.leerRegistros(i);
        if(viajes.getIdViaje()==idviaje){
            int posdestino=archivodestino.buscarRegistros(viajes.getIdDestino());
            if(posdestino<0)cout<<"ERROR AL LEER LOS ARCHIVOS"<<endl;
            destinos=archivodestino.leerRegistros(posdestino);
        }
    }


    setColor(YELLOW);
    locate(40, 3);  cout << "------------------------------------------";
    locate(40, 4);  cout << "            INFORMACION DEL PASAJE        ";
    locate(40, 5);  cout << "------------------------------------------";
    setColor(WHITE);

    locate(40, 7);cout<<"========================================";
    locate(40, 8);cout<<"Numero de Pasaje:       "<<pasaje;
    locate(40, 9);cout<<"ID de viaje:            "<<idviaje;
    locate(40, 11);cout<<"Numero de Butaca:       "<<butaca;
    locate(40, 12);cout<<"Tipo de Butaca:         "<<tipo_butaca;
    locate(40, 13);cout<<"Precio $                "<<precio;
    locate(40, 14);cout<<"Lugar de Destino:       "<<destinos.getNombre_destino();
    locate(40, 15);cout<<"Provincia de Destino:   "<<destinos.getNombre_provincia();
    locate(40, 17);cout<<"========================================";
}
