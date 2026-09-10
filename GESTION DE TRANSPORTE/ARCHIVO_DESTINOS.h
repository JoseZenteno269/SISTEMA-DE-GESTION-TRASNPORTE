#ifndef ARCHIVO_DESTINOS_H_INCLUDED
#define ARCHIVO_DESTINOS_H_INCLUDED
#include "DESTINOS.h"

class Archivo_destino{
private:
    char archivo[30];
public:
    Archivo_destino(const char *a="Destinos.dat");
    int contarRegistros();
    int buscarRegistros(int);
    Destino leerRegistros(int);
    bool grabarRegistro(Destino);
    bool modificarRegistro(Destino,int);
    void listar();
};


#endif // ARCHIVO_DESTINOS_H_INCLUDED
