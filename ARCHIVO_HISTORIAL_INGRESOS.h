#ifndef ARCHIVO_HISTORIAL_INGRESOS_H_INCLUDED
#define ARCHIVO_HISTORIAL_INGRESOS_H_INCLUDED
#include "HISTORIAL_INGRESOS.h"

class Archivo_historial_usuario{
private:
    char archivo_historial[30];
public:
    Archivo_historial_usuario(const char *ah = "Historial_ingresos.dat");
    int contarRegistros();
    int buscarRegistro(int);
    Historial_ingreso leerRegistros(int);
    bool grabarRegistro(Historial_ingreso);
    void mostrar();
    void listar();
};

#endif // ARCHIVO_HISTORIAL_INGRESOS_H_INCLUDED
