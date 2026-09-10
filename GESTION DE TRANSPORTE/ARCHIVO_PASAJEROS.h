#ifndef ARCHIVO_PASAJEROS_H_INCLUDED
#define ARCHIVO_PASAJEROS_H_INCLUDED
#include "PASAJEROS.h"

class Archivo_pasajero{
private:
    char archivo[30];
public:
    Archivo_pasajero(const char *a="Pasajeros.dat");
    int contarRegistros();
    int buscarRegistro(int);
    Pasajero leerRegistros(int);
    bool grabarRegistro(Pasajero);
    bool modificarRegistro(Pasajero, int);
    void listar();
};

#endif // ARCHIVO_PASAJEROS_H_INCLUDED
