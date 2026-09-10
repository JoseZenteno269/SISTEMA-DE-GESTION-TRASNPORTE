#ifndef ARCHIVO_USUARIOS_H_INCLUDED
#define ARCHIVO_USUARIOS_H_INCLUDED
#include "USUARIOS.h"

class Archivo_usuario{
private:
    char archivo[30];
public:
    Archivo_usuario(const char *a="Usuarios.dat");
    int contarRegistros();
    int buscarRegistro(int);
    Usuario leerRegistros(int);
    bool grabarRegistro(Usuario);
    bool modificarRegistro(Usuario, int);
    void listar();
};


#endif // ARCHIVO_USUARIOS_H_INCLUDED
