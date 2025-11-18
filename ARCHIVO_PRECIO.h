#ifndef ARCHIVO_PRECIO_H_INCLUDED
#define ARCHIVO_PRECIO_H_INCLUDED
#include "PRECIO.h"

class Archivo_Precio{
private:
    char archivo[30];
public:
    Archivo_Precio(const char *a="Precio.dat");
    Precios leerRegistros();
    bool grabarRegistro(Precios);
    void listar();
};


#endif // ARCHIVO_PRECIO_H_INCLUDED
