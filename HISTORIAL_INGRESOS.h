#ifndef HISTORIAL_INGRESOS_H_INCLUDED
#define HISTORIAL_INGRESOS_H_INCLUDED
#include "FECHAS.h"
#include "HORA.h"

class Historial_ingreso{
private:
    int idusuario;
    Fecha ingreso_sesion;
    Hora inicio;
public:
    void setIdusuario(int );
    void setIngreso_sesion(Fecha );
    void setInicio(Hora );

    int getIdusuario();
    Fecha getIngreso_sesion();
    Hora getInicio();

    void mostrar();
};


#endif // HISTORIAL_INGRESOS_H_INCLUDED
