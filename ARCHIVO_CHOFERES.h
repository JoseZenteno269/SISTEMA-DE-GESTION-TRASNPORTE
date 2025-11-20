#ifndef ARCHIVO_CHOFERES_H_INCLUDED
#define ARCHIVO_CHOFERES_H_INCLUDED
#include "CHOFERES.h"

class Archivo_chofer{
private:
    char archivo[30];
public:
    Archivo_chofer(const char *a="Choferes.dat");
    int contarRegistros();
    int buscarRegistro(int);
    Chofer leerRegistros(int);
    bool grabarRegistro(Chofer);
    bool modificarRegistro(Chofer, int);
    void listar();
};

#endif // ARCHIVO_CHOFERES_H_INCLUDED
