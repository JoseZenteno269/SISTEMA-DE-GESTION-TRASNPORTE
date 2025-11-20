#ifndef ARCHIVO_VIAJES_H_INCLUDED
#define ARCHIVO_VIAJES_H_INCLUDED
#include "VIAJES.h"

class Archivo_viaje{
private:
    char archivo[30];
public:
    Archivo_viaje(const char *a="Viajes.dat");
    int contarRegistros();
    int buscarRegistro(int);
    Viaje leerRegistros(int);
    bool grabarRegistro(Viaje);
    bool modificarRegistro(Viaje, int);
    void listar();
    void listartabla();
};


#endif // ARCHIVO_VIAJES_H_INCLUDED
