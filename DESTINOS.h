#ifndef DESTINOS_H_INCLUDED
#define DESTINOS_H_INCLUDED
#include "HORA.h"

class Destinos{
private:
    int idDestino;
    char nombre_provincia[40];
    char nombre_destino[40];
    float distanciaKm;
    Hora duracion;
    bool habilitado;
public:

    void setidDestino(int );
    void setnombre_provincia(const char *);
    void setnombre_destino(const char *);
    void setdistanciaKm(float );
    void setduracion(Hora);
    void sethabilitado(bool );

    int getidDestino();
    const char *getnombre_provincia();
    const char *getnombre_destino();
    float getdistanciaKm();
    Hora getduracion();
    bool gethabilitado();

    void cargar(int);
    void mostrar(int X=40,int Y=3);

};


#endif // DESTINOS_H_INCLUDED
