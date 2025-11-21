#ifndef VIAJES_H_INCLUDED
#define VIAJES_H_INCLUDED
#include "FECHAS.h"
#include "HORA.h"
#include "TIEMPO_ACTUAL.h"

class Viaje{
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
    void setIdViaje(int);
    void setIdMicro(int);
    void setIdChofer(int);
    void setIdDestino(int);
    void setFecha_Inicio_Viaje(Fecha);
    void setFecha_Fin_Viaje(Fecha);
    void setHora_Inicio_Viaje(Hora);
    void setHora_Fin_Viaje(Hora);
    void setRealizado(bool);

    int getIdViaje();
    int getIdMicro();
    int getIdChofer();
    int getIdDestino();
    Fecha getFecha_Inicio_Viaje();
    Fecha getFecha_Fin_Viaje();
    Hora getHora_Inicio_Viaje();
    Hora getHora_Fin_Viaje();
    bool getRealizado();

    void cargar(int);
    void mostrar();
    void listartabla();
};


#endif // VIAJES_H_INCLUDED
