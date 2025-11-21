#ifndef CHOFERES_H_INCLUDED
#define CHOFERES_H_INCLUDED
#include "PERSONA.h"
#include "FECHAS.h"

class Chofer :public Persona{
private:
    int legajo;
    char mail_laboral[100];
    bool estado;
    Fecha fecha_de_ingreso;

public:

    void setLegajo(int );
    void setMail_laboral(const char *);
    void setEstado(bool );
    void setFecha_de_ingreso(Fecha );

    int getLegajo();
    const char *getMail_laboral();
    bool getEstado();
    Fecha getFecha_de_ingreso();

    void cargar(int);
    void mostrar();
    void generarMailLaboral();
    int calcularAntiguedad();
};


#endif // CHOFERES_H_INCLUDED
