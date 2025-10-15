#ifndef CHOFERES_H_INCLUDED
#define CHOFERES_H_INCLUDED
#include "PERSONA.h"
#include "FECHAS.h"

class Choferes:public Personas{
private:
    int legajo;
    int idMicro;
    bool estado;
    Fechas fecha_de_ingreso;
public:

    void setlegajo(int );
    void setidMicro(int );
    void setestado(bool );
    void setfecha_de_ingreso(Fechas );

    int getlegajo();
    int getidMicro();
    bool getestado();
    Fechas getfecha_de_ingreso();

    void cargar();
    void mostrar();
};


#endif // CHOFERES_H_INCLUDED
