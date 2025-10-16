#ifndef CHOFERES_H_INCLUDED
#define CHOFERES_H_INCLUDED
#include "PERSONA.h"
#include "FECHAS.h"

class Choferes:public Personas{
private:
    int legajo;
    char mail_laboral[40];
    bool estado;
    Fechas fecha_de_ingreso;
public:

    void setlegajo(int );
    void setestado(bool );
    void setfecha_de_ingreso(Fechas );

    int getlegajo();
    bool getestado();
    Fechas getfecha_de_ingreso();

    void cargar();
    void mostrar();
};


#endif // CHOFERES_H_INCLUDED
