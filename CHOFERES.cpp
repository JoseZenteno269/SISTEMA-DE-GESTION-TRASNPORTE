#include<iostream>
#include "CHOFERES.h"
#include "funciones.h"
#include<cstring>

using namespace std;


void Choferes::setlegajo(int l){legajo=l; }
void Choferes::setmail_laboral(const char *ml){strcpy(mail_laboral, ml); }
void Choferes::setestado(bool e){estado=e; }
void Choferes::setfecha_de_ingreso(Fechas f){fecha_de_ingreso=f; }

int Choferes::getlegajo(){return legajo; }
const char *Choferes::getmail_laboral(){return mail_laboral; }
bool Choferes::getestado(){return estado; }
Fechas Choferes::getfecha_de_ingreso(){return fecha_de_ingreso; }

void Choferes::cargar(int leg){
    cout<<"El N° de legajo: "<<(legajo==leg)<<endl;
    cout<<"Mail laboral: "; cargarCadena(mail_laboral, 99);
    Personas::cargar();
    cout<<endl;
    fecha_de_ingreso.cargar();
    estado=true;

}
void Choferes::mostrar(){
    cout<<"N° de legajo: "<<legajo<<endl;
    cout<<"Mail laboral: "<<mail_laboral<<endl;
    Personas::mostrar();
    fecha_de_ingreso.mostrar();
}
