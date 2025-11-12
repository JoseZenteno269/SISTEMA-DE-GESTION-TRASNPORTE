#include<iostream>
#include "CHOFERES.h"
#include "funciones.h"
#include "TIEMPO_ACTUAL.h"
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
    cout<<"El N° de legajo: "<<(legajo=leg)<<endl;
    cout<<endl;
    Personas::cargar();
    generarMailLaboral();
    cout<<endl;
    cout<<"FECHA DE INGRESO"<<endl;
    Tiempo_Actual tiempo;
    Fechas fecha(tiempo.getDia(), tiempo.getMes(), tiempo.getAnio());
    setfecha_de_ingreso(fecha);
    fecha.mostrar();
    estado=true;

}
void Choferes::mostrar(){
    cout<<"N° de legajo: "<<legajo<<endl;
    cout<<"Email Laboral: "<<mail_laboral<<endl;
    cout<<endl;
    cout<<"DATOS PERSONALES"<<endl;
    Personas::mostrar();
    cout<<endl;
    cout<<"FECHA DE INGRESO"<<endl;
    fecha_de_ingreso.mostrar();
    int Antiguedad=calcularAntiguedad();
    cout<<"Antiguedad: "<<Antiguedad<<" años"<<endl;
}
void Choferes::generarMailLaboral(){

    if(nombre[0]=='\0' or apellido[0]=='\0'){
    strcpy(mail_laboral, "desconocido@viautn.com");
    }
    else{
    sprintf(mail_laboral, "%c%s%d@viautn.com", nombre[0], apellido, legajo);
    }
}

int Choferes::calcularAntiguedad(){
    Tiempo_Actual hoy;

    int antiguedad=hoy.getAnio()-fecha_de_ingreso.getanio();

    if(hoy.getMes()<fecha_de_ingreso.getmes() or (hoy.getMes() == fecha_de_ingreso.getmes() and hoy.getDia()<fecha_de_ingreso.getdia())){
        antiguedad--;
    }
    return antiguedad;
}
