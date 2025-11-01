#ifndef ARCHIVO_PASAJE_H_INCLUDED
#define ARCHIVO_PASAJE_H_INCLUDED
#include "PASAJE.h"

class Archivo_pasajes{
private:
    char archivo[30];
public:
    Archivo_pasajes(const char *a="Pasajes.dat");
    int contarRegistros();
    int buscarRegistro(int);
    Pasajes leerRegistros(int);
    bool grabarRegistro(Pasajes);
    void listar();
};




#endif // ARCHIVO_PASAJE_H_INCLUDED
