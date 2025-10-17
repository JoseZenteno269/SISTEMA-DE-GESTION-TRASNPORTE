#ifndef VIAJES_H_INCLUDED
#define VIAJES_H_INCLUDED
#include "FECHAS.h"

class Viajes{
private:
    int idViaje;
    int idMicro;
    int idChofer;
    int idDestino;
    Fechas fecha_Inicio_Viaje;
    Fechas fecha_Fin_Viaje;
    bool realizado;
public:
    void setidViaje(int);
    void setidMicro(int);
    void setidChofer(int);
    void setidDestino(int);
    void setfecha_Inicio_Viaje(Fechas);
    void setfecha_Fin_Viaje(Fechas);
    void setrealizado(bool);

    int getidViaje();
    int getidMicro();
    int getidChofer();
    int getidDestino();
    Fechas getfecha_Inicio_Viaje();
    Fechas getfecha_Fin_Viaje();
    bool getrealizado();

    void cargar();
    void mostrar();

};


#endif // VIAJES_H_INCLUDED
