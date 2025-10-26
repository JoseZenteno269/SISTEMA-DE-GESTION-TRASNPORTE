#ifndef ARCHIVO_PROVINCIAS_H_INCLUDED
#define ARCHIVO_PROVINCIAS_H_INCLUDED
#include "PROVINCIAS.h"

class Archivo_provincias{
private:
    char archivo[30];
public:
    Archivo_provincias(const char *a="Provincias.dat");
    int contarRegistros();
    int buscarRegistros(int);
    Provincia leerRegistros(int);
    bool grabarRegistro(Provincia);
    bool modificarRegistro(Provincia,int);
    void listar();
};

#endif // ARCHIVO_PROVINCIAS_H_INCLUDED
