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
    char tipo_butaca[30];
    Fechas fecha_Inicio;
    Fechas fecha_Fin;
    Hora hora_Inicio;
    Hora hora_Fin;
    char nombre_destino[40];
    char provincia_destino[40];

public:

};


#endif // PASAJE_H_INCLUDED
