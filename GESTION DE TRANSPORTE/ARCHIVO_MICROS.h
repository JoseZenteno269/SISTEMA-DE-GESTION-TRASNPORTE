#ifndef ARCHIVO_MICROS_H_INCLUDED
#define ARCHIVO_MICROS_H_INCLUDED
#include "MICROS.h"

class Archivo_micro{
private:
    char archivo[30];
public:
    Archivo_micro(const char *a="Micros.dat");
    int contarRegistros();
    int buscarRegsitro(int);
    Micro leerRegistros(int);
    bool grabarRegistro(Micro);
    bool modificarRegistro(Micro, int);
    void listar();
    void listartabla();
};


#endif // ARCHIVO_MICROS_H_INCLUDED
