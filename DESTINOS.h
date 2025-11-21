#ifndef DESTINOS_H_INCLUDED
#define DESTINOS_H_INCLUDED
#include "HORA.h"

class Destino{
private:
    int idDestino;
    char nombre_provincia[40];
    char nombre_destino[40];
    float distanciaKm;
    Hora duracion;
    bool habilitado;
public:

    void setIdDestino(int );
    void setNombre_provincia(const char *);
    void setNombre_destino(const char *);
    void setDistanciaKm(float );
    void setDuracion(Hora);
    void setHabilitado(bool );

    int getIdDestino();
    const char *getNombre_provincia();
    const char *getNombre_destino();
    float getDistanciaKm();
    Hora getDuracion();
    bool getHabilitado();

    void cargar(int);
    void mostrar(int X=40,int Y=3);

};


#endif // DESTINOS_H_INCLUDED
