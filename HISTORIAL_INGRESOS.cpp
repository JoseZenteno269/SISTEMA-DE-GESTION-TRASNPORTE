#include<iostream>
#include<cstring>
#include "HISTORIAL_INGRESOS.h"
#include "rlutil.h"
using namespace rlutil;

using namespace std;

void Historial_ingreso::setidusuario(int idu){idusuario=idu;}
void Historial_ingreso::setingreso_sesion(Fechas is){ingreso_sesion=is; }
void Historial_ingreso::setinicio(Hora i){inicio=i; }
void Historial_ingreso::setnombre_usuario(const char *nu){strcpy(nombre_usuario,nu); }

int Historial_ingreso::getidusuario(){return idusuario; }
Fechas Historial_ingreso::getingreso_sesion(){return ingreso_sesion; }
Hora Historial_ingreso::getinicio(){return inicio; }
const char *Historial_ingreso::getnombre_usuario(){return nombre_usuario; }

void Historial_ingreso::mostrar() {

    setColor(YELLOW);
    locate(40, 3);  cout << "----------------------------------------------";
    locate(40, 4);  cout << "              HISTORIAL DE INGRESO            ";
    locate(40, 5);  cout << "----------------------------------------------";
    setColor(WHITE);

    locate(40, 7);  cout << "ID de usuario:       " << idusuario;
    locate(40, 8);  cout << "Nombre:              " << nombre_usuario;

    setColor(YELLOW);
    locate(40, 10); cout << "------------- FECHA DE INGRESO ---------------";
    setColor(WHITE);

    locate(40, 11);
    ingreso_sesion.mostrarEn(40,12);

    setColor(YELLOW);
    locate(40, 13); cout << "------------------ HORA -----------------------";
    setColor(WHITE);

    locate(40, 14);
    inicio.mostrar(40,14);

    setColor(YELLOW);
    locate(40, 16); cout << "----------------------------------------------";
    setColor(WHITE);

    anykey();
}
