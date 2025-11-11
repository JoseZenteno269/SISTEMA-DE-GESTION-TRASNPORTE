#ifndef HORA_H_INCLUDED
#define HORA_H_INCLUDED
#include <ctime>


class Hora{
private:
    int hora;
    int minuto;
    bool validar(int h, int m);
    bool validar_viaje(int h, int m);

public:
    Hora();
    Hora(int, int);

    void sethora(int);
    void setminuto(int);
    void sethora_viaje(int);
    void setminuto_viaje(int);
    void settiempo(int, int);

    int gethora();
    int getminuto();

    void cargar();
    void cargar_viaje();
    void mostrar();
};


#endif // HORA_H_INCLUDED
