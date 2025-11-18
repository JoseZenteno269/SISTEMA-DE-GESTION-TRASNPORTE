#include<iostream>
#include "DOMICILIO.h"
#include "funciones.h"
#include<cstring>
#include "rlutil.h"

using namespace rlutil;
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

void Domicilio::Cargar() {

    while (true) {
        setColor(CYAN);
        locate(40, 10); cout << "Calle: ";
        setColor(WHITE);
        locate(47, 10); cargarCadena(calle, 29);

        if (validarPalabra(calle)) break;

        setColor(RED);
        locate(40, 11); cout << "Calle inválida. Intente nuevamente.";
        anykey();
        LimpiarLineas(10, 11, 40);
        setColor(WHITE);
    }

    while (true) {
        setColor(CYAN);
        locate(40, 12); cout << "Altura: ";
        setColor(WHITE);
        locate(48, 12); cin >> altura;

        int longitud = to_string(altura).length();
        if (validar_numero() && longitud >= 1 && longitud <= 6) break;

        setColor(RED);
        locate(40, 13); cout << "Altura inválida. Intente nuevamente.";
        anykey();
        LimpiarLineas(12, 13, 40);
        setColor(WHITE);
    }

    setColor(CYAN);
    locate(40, 14); cout << "Código Postal: ";
    setColor(WHITE);
    locate(56, 14); cargarCadena(codigoPostal, 9);

    while (true) {
        setColor(CYAN);
        locate(40, 16); cout << "Localidad: ";
        setColor(WHITE);
        locate(50, 16); cargarCadena(localidad, 29);

        if (validarPalabra(localidad)) break;

        setColor(RED);
        locate(40, 17); cout << "Localidad inválida. Intente nuevamente.";
        anykey();
        LimpiarLineas(16, 17, 40);
        setColor(WHITE);
    }

    while (true) {
        setColor(CYAN);
        locate(40, 18); cout << "Partido: ";
        setColor(WHITE);
        locate(48, 18); cargarCadena(partido, 29);

        if (validarPalabra(partido)) break;

        setColor(RED);
        locate(40, 19); cout << "Partido inválido. Intente nuevamente.";
        anykey();
        LimpiarLineas(18, 19, 40);
        setColor(WHITE);
    }

    while (true) {
        setColor(CYAN);
        locate(40, 20); cout << "Provincia: ";
        setColor(WHITE);
        locate(50, 20); cargarCadena(provincia, 29);

        if (validarPalabra(provincia)) break;

        setColor(RED);
        locate(40, 21); cout << "Provincia inválida. Intente nuevamente.";
        anykey();
        LimpiarLineas(20, 21, 40);
        setColor(WHITE);
    }
}

void Domicilio::CargarEn(int x, int y) {

    while (true) {
        setColor(CYAN);
        locate(x,y); cout << "Calle: ";
        setColor(WHITE);
        locate(x+7, y); cargarCadena(calle, 29);

        if (validarPalabra(calle)) break;

        setColor(RED);
        locate(x, y+1); cout << "Calle inválida. Intente nuevamente.";
        anykey();
        LimpiarLineas(y, y+1, x);
        setColor(WHITE);
    }

    while (true) {
        setColor(CYAN);
        locate(x, y+2); cout << "Altura: ";
        setColor(WHITE);
        locate(x+8, y+2); cin >> altura;

        int longitud = to_string(altura).length();
        if (validar_numero() && longitud >= 1 && longitud <= 6) break;

        setColor(RED);
        locate(x, y); cout << "Altura inválida. Intente nuevamente.";
        anykey();
        LimpiarLineas(y, y+3, x);
        setColor(WHITE);
    }

    setColor(CYAN);
    locate(x, y+4); cout << "Código Postal: ";
    setColor(WHITE);
    locate(x+16, y+4); cargarCadena(codigoPostal, 9);

    while (true) {
        setColor(CYAN);
        locate(x, y+6); cout << "Localidad: ";
        setColor(WHITE);
        locate(x+10, y+6); cargarCadena(localidad, 29);

        if (validarPalabra(localidad)) break;

        setColor(RED);
        locate(x, y+7); cout << "Localidad inválida. Intente nuevamente.";
        anykey();
        LimpiarLineas(y+6, y+8, x);
        setColor(WHITE);
    }

    while (true) {
        setColor(CYAN);
        locate(x, y+8); cout << "Partido: ";
        setColor(WHITE);
        locate(x+8, y+8); cargarCadena(partido, 29);

        if (validarPalabra(partido)) break;

        setColor(RED);
        locate(x, y+9); cout << "Partido inválido. Intente nuevamente.";
        anykey();
        LimpiarLineas(y+8, y+9, x);
        setColor(WHITE);
    }

    while (true) {
        setColor(CYAN);
        locate(x, y+10); cout << "Provincia: ";
        setColor(WHITE);
        locate(x+10, y+10); cargarCadena(provincia, 29);

        if (validarPalabra(provincia)) break;

        setColor(RED);
        locate(x, y+11); cout << "Provincia inválida. Intente nuevamente.";
        anykey();
        LimpiarLineas(y+10, y+12, x);
        setColor(WHITE);
    }
}


void Domicilio::Mostrar(int X, int Y) {
    setColor(CYAN);
    locate(X, Y);     cout << "Calle:   ";
    setColor(WHITE);
    locate(X + 15, Y); cout << calle;

    setColor(CYAN);
    locate(X, Y + 1); cout << "Altura:  ";
    setColor(WHITE);
    locate(X + 15, Y + 1); cout << altura;

    setColor(CYAN);
    locate(X, Y + 2); cout << "Código Postal:   ";
    setColor(WHITE);
    locate(X + 15, Y + 2); cout << codigoPostal;

    setColor(CYAN);
    locate(X, Y + 3); cout << "Localidad:   ";
    setColor(WHITE);
    locate(X + 15, Y + 3); cout << localidad;

    setColor(CYAN);
    locate(X, Y + 4); cout << "Partido:     ";
    setColor(WHITE);
    locate(X + 15, Y + 4); cout << partido;

    setColor(CYAN);
    locate(X, Y + 5); cout << "Provincia:   ";
    setColor(WHITE);
    locate(X + 15, Y + 5); cout << provincia;
}

