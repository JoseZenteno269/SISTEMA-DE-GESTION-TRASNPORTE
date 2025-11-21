#include<iostream>
#include "FECHAS.h"
#include "rlutil.h"
#include "funciones.h"

using namespace std;
using namespace rlutil;

Fecha::Fecha(int d, int m, int a){
    dia=d;
    mes=m;
    anio=a;
}

void Fecha::setDia(int d){dia=d; }
void Fecha::setMes(int m){mes=m; }
void Fecha::setAnio(int a){anio=a; }

int Fecha::getDia(){return dia; }
int Fecha::getMes(){return mes; }
int Fecha::getAnio(){return anio; }

void Fecha::cargar(){
    while (true) {
        locate(40, 10); cout << "Año: ";
        locate(45, 10); cin >> anio;

        if (validar_numero() && (anio > 1900 && anio < 2100)) break;

        setColor(RED);
        locate(40, 11); cout << "Año inválido. Intente nuevamente.";
        anykey();
        LimpiarLineas(10,11,40);
        setColor(WHITE);
    }

    while (true) {
        locate(40, 12); cout << "Mes: ";
        locate(45, 12); cin >> mes;

        if (validar_numero() && (mes >= 1 && mes <= 12)) break;

        setColor(RED);
        locate(40, 13); cout << "Mes inválido. Intente nuevamente.";
        anykey();
        LimpiarLineas(12,13,40);
        setColor(WHITE);
    }

    int diasMes = diasEnMes(mes, anio);

    while (true) {
        locate(40, 14); cout << "Día: ";
        locate(45, 14); cin >> dia;

        if (validar_numero() && (dia >= 1 && dia <= diasMes))break;

        setColor(RED);
        locate(40, 15); cout << "Día inválido. Intente nuevamente.";
        anykey();
        LimpiarLineas(14,15,40);
        setColor(WHITE);
    }
}

void Fecha::cargarEn(int x, int y){
    while (true) {
        locate(x, y); cout << "Año: ";
        locate(x+5, y); cin >> anio;

        if (validar_numero() && (anio > 1900 && anio < 2100)) break;

        setColor(RED);
        locate(x, y+1); cout << "Año inválido. Intente nuevamente.";
        anykey();
        LimpiarLineas(y,y+5,x);
        setColor(WHITE);
    }

    while (true) {
        locate(x, y+2); cout << "Mes: ";
        locate(x+5, y+2); cin >> mes;

        if (validar_numero() && (mes >= 1 && mes <= 12)) break;

        setColor(RED);
        locate(x, y+3); cout << "Mes inválido. Intente nuevamente.";
        anykey();
        LimpiarLineas(y+2,y+3,x);
        setColor(WHITE);
    }

    int diasMes = diasEnMes(mes, anio);

    while (true) {
        locate(x, y+4); cout << "Día: ";
        locate(x+5, y+4); cin >> dia;

        if (validar_numero() && (dia >= 1 && dia <= diasMes))break;

        setColor(RED);
        locate(x, y+5); cout << "Día inválido. Intente nuevamente.";
        anykey();
        LimpiarLineas(y+4,y+5,x);
        setColor(WHITE);
    }
}


void Fecha::mostrar() {

    setColor(WHITE);
    locate(40, 17); cout << dia << "/" << mes << "/" << anio;

}
void Fecha::mostrarEn(int x, int y) {
    setColor(WHITE);
    locate(x, y);
    cout << dia << "/" << mes << "/" << anio;
}
