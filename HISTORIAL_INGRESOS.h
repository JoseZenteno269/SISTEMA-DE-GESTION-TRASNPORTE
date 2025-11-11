#ifndef HISTORIAL_INGRESOS_H_INCLUDED
#define HISTORIAL_INGRESOS_H_INCLUDED
#include "FECHAS.h"
#include "HORA.h"

class Historial_ingreso{
private:
    int idusuario;
    char nombre_usuario[40];
    Fechas ingreso_sesion;
    Hora inicio;
public:
     void setidusuario(int );
    void setingreso_sesion(Fechas );
    void setinicio(Hora );
    void setnombre_usuario(const char *);

    int getidusuario();
    Fechas getingreso_sesion();
    Hora getinicio();
    const char *getnombre_usuario();

    void mostrar();
};


#endif // HISTORIAL_INGRESOS_H_INCLUDED
