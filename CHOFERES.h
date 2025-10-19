#ifndef CHOFERES_H_INCLUDED
#define CHOFERES_H_INCLUDED
#include "PERSONA.h"
#include "FECHAS.h"

class Choferes:public Personas{
private:
    int legajo;
    char mail_laboral[100];
    bool estado;
    Fechas fecha_de_ingreso;
    float recaudacion;

public:

    void setlegajo(int );
    void setmail_laboral(const char *);
    void setestado(bool );
    void setfecha_de_ingreso(Fechas );
    void setrecaudacion(float);

    int getlegajo();
    const char *getmail_laboral();
    bool getestado();
    Fechas getfecha_de_ingreso();
    float getrecaudacion();

    void cargar(int);
    void mostrar();
    void generarMailLaboral();
    int calcularAntiguedad();
    void agregarRecaudacion(float);
};


#endif // CHOFERES_H_INCLUDED
