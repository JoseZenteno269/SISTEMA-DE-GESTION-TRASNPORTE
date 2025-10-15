#ifndef ARCHIVO_CHOFERES_H_INCLUDED
#define ARCHIVO_CHOFERES_H_INCLUDED
#include "CHOFERES.h"

class Archivo_choferes{
private:
    char archivo[30];
public:
    Archivo_choferes(const char *a="Choferes.dat");
    int contarRegistros();
    int buscarRegistro(int);
    Choferes leerRegistros(int);
    bool grabarRegistro(Choferes);
    bool modificarRegistro(Choferes, int);
    void listar();
};

#endif // ARCHIVO_CHOFERES_H_INCLUDED
