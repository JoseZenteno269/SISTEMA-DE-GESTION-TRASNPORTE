#ifndef ARCHIVO_PASAJE_H_INCLUDED
#define ARCHIVO_PASAJE_H_INCLUDED
#include "PASAJE.h"

class Archivo_pasaje{
private:
    char archivo[30];
public:
    Archivo_pasaje(const char *a="Pasajes.dat");
    int contarRegistros();
    int buscarRegistro(int);
    Pasaje leerRegistros(int);
    bool grabarRegistro(Pasaje);
    void listar();
};




#endif // ARCHIVO_PASAJE_H_INCLUDED
