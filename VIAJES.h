#ifndef VIAJES_H_INCLUDED
#define VIAJES_H_INCLUDED
#include "FECHAS.h"
#include "HORA.h"
#include "TIEMPO_ACTUAL.h"

class Viajes{
private:
    int idViaje;
    int idMicro;
    int idChofer;
    int idDestino;
    Fecha fecha_Inicio_Viaje;
    Fecha fecha_Fin_Viaje;
    Hora hora_Inicio_Viaje;
    Hora hora_Fin_Viaje;
    bool realizado;
public:
    void setidViaje(int);
    void setidMicro(int);
    void setidChofer(int);
    void setidDestino(int);
    void setfecha_Inicio_Viaje(Fecha);
    void setfecha_Fin_Viaje(Fecha);
    void sethora_Inicio_Viaje(Hora);
    void sethora_Fin_Viaje(Hora);
    void setrealizado(bool);

    int getidViaje();
    int getidMicro();
    int getidChofer();
    int getidDestino();
    Fecha getfecha_Inicio_Viaje();
    Fecha getfecha_Fin_Viaje();
    Hora gethora_Inicio_Viaje();
    Hora gethora_Fin_Viaje();
    bool getrealizado();

    void cargar(int);
    void mostrar();
    //void mostrar();
    void listartabla();
};


#endif // VIAJES_H_INCLUDED
