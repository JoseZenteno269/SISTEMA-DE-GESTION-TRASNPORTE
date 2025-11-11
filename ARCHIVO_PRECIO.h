#ifndef ARCHIVO_PRECIO_H_INCLUDED
#define ARCHIVO_PRECIO_H_INCLUDED
#include "PRECIO.h"

class Archivo_Precio{
private:
    char archivo[30];
public:
    Archivo_Precio(const char *a="Precio.dat");
    PrecioxKilometro leerRegistros();
    bool grabarRegistro(PrecioxKilometro);
    void listar();
};


#endif // ARCHIVO_PRECIO_H_INCLUDED
