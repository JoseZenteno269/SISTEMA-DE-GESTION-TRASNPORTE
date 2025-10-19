#ifndef FECHAS_H_INCLUDED
#define FECHAS_H_INCLUDED
#include "TIEMPO_ACTUAL.h"

class Fechas{
private:
    int dia;
    int mes;
    int anio;
public:
    Fechas(int d=1, int m=1, int a=1900);

    void setdia(int );
    void setmes(int );
    void setanio(int );

    int getdia();
    int getmes();
    int getanio();

    void cargar();
    void mostrar();
};

#endif // FECHAS_H_INCLUDED
