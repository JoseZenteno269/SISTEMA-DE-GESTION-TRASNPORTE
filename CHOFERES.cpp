#include<iostream>
#include "CHOFERES.h"
#include "funciones.h"
#include "TIEMPO_ACTUAL.h"
#include<cstring>
#include "rlutil.h"

using namespace rlutil;
using namespace std;

void Chofer::setlegajo(int l){legajo=l; }
void Chofer::setmail_laboral(const char *ml){strcpy(mail_laboral, ml); }
void Chofer::setestado(bool e){estado=e; }
void Chofer::setfecha_de_ingreso(Fecha f){fecha_de_ingreso=f; }

int Chofer::getlegajo(){return legajo; }
const char *Chofer::getmail_laboral(){return mail_laboral; }
bool Chofer::getestado(){return estado; }
Fecha Chofer::getfecha_de_ingreso(){return fecha_de_ingreso; }

void Chofer::cargar(int leg){
    cls();

    setColor(YELLOW);
    locate(40,3); cout << "----------------------------------------------";
    locate(40,4); cout << "              CARGA DE CHOFER                 ";
    locate(40,5); cout << "----------------------------------------------";
    setColor(WHITE);

    locate(40,6);
    setColor(CYAN);
    cout << "El N° de legajo: ";
    setColor(WHITE);
    locate(70,6); cout << (legajo = leg);

    Persona::cargar();

    generarMailLaboral();

    setColor(CYAN);
    locate(40,9); cout << "FECHA DE INGRESO: ";
    setColor(WHITE);
    Tiempo_Actual tiempo;
    Fecha fecha(tiempo.getDia(), tiempo.getMes(), tiempo.getAnio());
    setfecha_de_ingreso(fecha);
    fecha.mostrarEn(60,9);

    estado = true;

    anykey();
    cls();
}

void Chofer::mostrar(){
    setColor(YELLOW);
    locate(40, 2); cout << "----------------------------------------------";
    locate(40, 3); cout << "              INFORMACION DEL CHOFER          ";
    locate(40, 4); cout << "----------------------------------------------";
    setColor(WHITE);

    locate(40, 6); cout << "N° de legajo: " << legajo;
    locate(40, 7); cout << "Email Laboral: " << mail_laboral;

    setColor(GREEN);
    locate(40, 9); cout << "-------------- DATOS PERSONALES --------------";
    setColor(WHITE);
    Persona::mostrar(10);

    setColor(GREEN);
    locate(40, 27); cout << "--------------- FECHA DE INGRESO -------------";
    setColor(WHITE);
    fecha_de_ingreso.mostrarEn(40,28);

    int Antiguedad = calcularAntiguedad();
    locate(40, 29); cout << "Antiguedad: " << Antiguedad << " años";

    anykey();
    LimpiarLineas(2, 31, 40);
}


void Chofer::generarMailLaboral(){

    if(nombre[0]=='\0' or apellido[0]=='\0'){
    strcpy(mail_laboral, "desconocido@viautn.com");
    }else sprintf(mail_laboral, "%c%s%d@viautn.com", nombre[0], apellido, legajo);
}

int Chofer::calcularAntiguedad(){
    Tiempo_Actual hoy;

    int antiguedad=hoy.getAnio()-fecha_de_ingreso.getanio();

    if(hoy.getMes()<fecha_de_ingreso.getmes() or (hoy.getMes() == fecha_de_ingreso.getmes() and hoy.getDia()<fecha_de_ingreso.getdia())){
        antiguedad--;
    }
    return antiguedad;
}
