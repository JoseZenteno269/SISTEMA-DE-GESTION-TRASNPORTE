#ifndef ARCHIVO_MICROS_H_INCLUDED
#define ARCHIVO_MICROS_H_INCLUDED
#include "MICROS.h"

class Archivo_micros{
private:
    char archivo[30];
public:
    Archivo_micros(const char *a="Micros.dat");
    int contarRegistros();
    int buscarRegsitro(int);
    Micros leerRegistros(int);
    bool grabarRegistro(Micros);
    bool modificarRegistro(Micros, int);
    void listar();
    void listartabla();
};


#endif // ARCHIVO_MICROS_H_INCLUDED
