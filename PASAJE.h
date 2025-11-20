#ifndef PASAJE_H_INCLUDED
#define PASAJE_H_INCLUDED
#include "FECHAS.h"
#include "HORA.h"
#include "VIAJES.h"

class Pasaje{
private:
    int pasaje;
    int idviaje;
    int butaca;
    float precioxkm;
    char tipo_butaca[30];
    char nombre_destino[40];
    char provincia_destino[40];

public:

    void setpasaje(int);
    void setidviaje(int);
    void setbutaca(int);
    void setprecioxkm(int);
    void settipo_butaca(const char*);
    void setnombre_destino(const char *);
    void setprovincia_destino(const char *);
    void setdatos(Viaje);

    int getpasaje();
    int getidviaje();
    int getbutaca();
    int getprecioxkm();
    const char *gettipo_butaca();
    const char *getnombre_destino();
    const char *getprovincia_destino();

    void mostrar();
};


#endif // PASAJE_H_INCLUDED
