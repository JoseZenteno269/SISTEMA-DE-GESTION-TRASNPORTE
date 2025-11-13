#ifndef ARCHIVO_VIAJES_H_INCLUDED
#define ARCHIVO_VIAJES_H_INCLUDED
#include "VIAJES.h"

class Archivo_viajes{
private:
    char archivo[30];
public:
    Archivo_viajes(const char *a="Viajes.dat");
    int contarRegistros();
    int buscarRegistro(int);
    Viajes leerRegistros(int);
    bool grabarRegistro(Viajes);
    bool modificarRegistro(Viajes, int);
    void listar();
    void listar_Disponibles();
};


#endif // ARCHIVO_VIAJES_H_INCLUDED
