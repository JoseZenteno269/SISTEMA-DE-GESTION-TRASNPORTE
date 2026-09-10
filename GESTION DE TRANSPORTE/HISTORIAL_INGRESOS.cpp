#include<iostream>
#include<cstring>
#include "HISTORIAL_INGRESOS.h"
#include "USUARIOS.h"
#include "ARCHIVO_USUARIOS.h"
#include "rlutil.h"
#include<iomanip>

using namespace rlutil;
using namespace std;

void Historial_ingreso::setIdusuario(int idu){idusuario=idu;}
void Historial_ingreso::setIngreso_sesion(Fecha is){ingreso_sesion=is; }
void Historial_ingreso::setInicio(Hora i){inicio=i; }

int Historial_ingreso::getIdusuario(){return idusuario; }
Fecha Historial_ingreso::getIngreso_sesion(){return ingreso_sesion; }
Hora Historial_ingreso::getInicio(){return inicio; }

void Historial_ingreso::mostrar(){
    Usuario usuarios;
    Archivo_usuario archivo;

    int pos=archivo.buscarRegistro(idusuario);
    if(pos<0){
        cout<<"ERROR, ID de Usuario no encontrado"<<endl;
    }
    usuarios=archivo.leerRegistros(pos);

    setColor(YELLOW);
    locate(40, 3);  cout<<"----------------------------------------------";
    locate(40, 4);  cout<<"              HISTORIAL DE INGRESO            ";
    locate(40, 5);  cout<<"----------------------------------------------";
    setColor(WHITE);
    locate(40, 7); cout<<left<<setw(35)<<"ID de usuario: "<<right<<setw(10)<<idusuario;
    locate(40, 8); cout<<left<<setw(35)<<"Nombre: "<<right<<setw(10)<<usuarios.getNombre();
    setColor(YELLOW);
    locate(40, 10); cout<<"------------- FECHA DE INGRESO ---------------";
    setColor(WHITE);
    ingreso_sesion.mostrarEn(57,11);
    setColor(YELLOW);
    locate(40, 12); cout<<"------------------ HORA ----------------------";
    setColor(WHITE);
    inicio.mostrar(40,13);
    setColor(YELLOW);
    locate(40, 14); cout<<"----------------------------------------------";
    setColor(WHITE);

    anykey();
}
