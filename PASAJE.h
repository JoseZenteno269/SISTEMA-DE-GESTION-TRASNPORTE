#ifndef PASAJE_H_INCLUDED
#define PASAJE_H_INCLUDED
#include "FECHAS.h"
#include "HORA.h"

class Pasajes{
private:
    int pasaje;
    int idviaje;
    int iddestino;
    int legajo_chofer;
    int idmicro;
    int butaca;
    float precioxkm;
    char tipo_butaca[30];
    Fechas fecha_Inicio;
    Fechas fecha_Fin;
    Hora hora_Inicio;
    Hora hora_Fin;
    char nombre_destino[40];
    char provincia_destino[40];
    char archivo[30];

public:
    Pasajes(const char *p="Pasaje.dat");

    void setpasaje(int);
    void setidviaje(int);
    void setiddestino(int);
    void setlegajo_chofer(int);
    void setidmicro(int);
    void setbutaca(int);
    void setprecioxkm(int);
    void settipo_butaca(const char*);
    void setfecha_Inicio(Fechas);
    void setfecha_Fin(Fechas);
    void sethora_Inicio(Hora);
    void sethora_Fin(Hora);
    void setnombre_destino(const char *);
    void setprovincia_destino(const char *);

    int getpasaje();
    int getidviaje();
    int getiddestino();
    int getlegajo_chofer();
    int getidmicro();
    int getbutaca();
    int getprecioxkm();
    const char *gettipo_butaca();
    Fechas getfecha_Inicio();
    Fechas getfecha_Fin();
    Hora gethora_Inicio();
    Hora gethora_Fin();
    const char *getnombre_destino();
    const char *getprovincia_destino();

    int contarRegistros();
    int buscarRegistro(int);
    Pasajes leerRegistros(int);
    bool grabarRegistro(Pasajes);
    void mostrar();
    void listar();
};


#endif // PASAJE_H_INCLUDED
