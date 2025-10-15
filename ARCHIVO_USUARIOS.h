#ifndef ARCHIVO_USUARIOS_H_INCLUDED
#define ARCHIVO_USUARIOS_H_INCLUDED
#include "USUARIOS.h"

class Archivo_usuarios{
private:
    char archivo[30];
public:
    Archivo_usuarios(const char *a="Usuarios.dat");
    int contarRegistros();
    int buscarRegistro(int);
    Usuarios leerRegistros(int);
    bool grabarRegistro(Usuarios);
    bool modificarRegistro(Usuarios, int);
    void listar();
};


#endif // ARCHIVO_USUARIOS_H_INCLUDED
