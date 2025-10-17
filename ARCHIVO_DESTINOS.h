#ifndef ARCHIVO_DESTINOS_H_INCLUDED
#define ARCHIVO_DESTINOS_H_INCLUDED
#include "DESTINOS.h"

class Archivo_destinos{
private:
    char archivo[30];
public:
    Archivo_destinos (const char *a="Destinos.dat");
    int contarRegistros();
    int buscarRegistros(int);
    Destinos leerRegistros(int);
    bool grabarRegistro(Destinos);
    bool modificarRegistro(Destinos,int);
    void listar();
};


#endif // ARCHIVO_DESTINOS_H_INCLUDED
