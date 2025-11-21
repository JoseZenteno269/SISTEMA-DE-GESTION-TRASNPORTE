#ifndef HORA_H_INCLUDED
#define HORA_H_INCLUDED
#include <ctime>

class Hora{
private:
    int hora;
    int minuto;

public:
    Hora();
    Hora(int, int);

    void setHora(int);
    void setMinuto(int);
    void setHora_viaje(int);
    void setMinuto_viaje(int);
    void setTiempo(int, int);

    int getHora();
    int getMinuto();
    int getHora_viaje();
    int getMinuto_viaje();

    bool validar(int h, int m);
    bool validar_viaje(int h, int m);

    void cargar();
    void cargar_viaje();
    void mostrar(int,int);
    void mostrarEn(int X = 40, int Y = 14);
};


#endif // HORA_H_INCLUDED
