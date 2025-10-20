#ifndef ARCHIVO_PASAJEROS_H_INCLUDED
#define ARCHIVO_PASAJEROS_H_INCLUDED
#include "PASAJEROS.h"

class Archivo_pasajeros{
private:
    char archivo[30];
public:
    Archivo_pasajeros(const char *a="Pasajeros.dat");
    int contarRegistros();
    int buscarRegistro(int);
    Pasajeros leerRegistros(int);
    bool grabarRegistro(Pasajeros);
    bool modificarRegistro(Pasajeros, int);
    void listar();
};

#endif // ARCHIVO_PASAJEROS_H_INCLUDED
