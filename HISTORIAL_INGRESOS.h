#ifndef HISTORIAL_INGRESOS_H_INCLUDED
#define HISTORIAL_INGRESOS_H_INCLUDED
#include "FECHAS.h"
#include "HORA.h"

class Historial_ingreso{
private:
    int idusuario;
    char nombre_usuario[40];
    Fecha ingreso_sesion;
    Hora inicio;
public:
    void setIdusuario(int );
    void setIngreso_sesion(Fecha );
    void setInicio(Hora );
    void setNombre_usuario(const char *);

    int getIdusuario();
    Fecha getIngreso_sesion();
    Hora getInicio();
    const char *getNombre_usuario();

    void mostrar();
};


#endif // HISTORIAL_INGRESOS_H_INCLUDED
