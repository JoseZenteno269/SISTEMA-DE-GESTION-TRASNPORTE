#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include "FECHAS.h"
#include "Domicilio.h"

class Personas{
protected:
    char nombre[40];
    char apellido[40];
    int dni;
    int telefono;
    char email[100];
    int genero;
    Fechas fecha_Nacimiento;
    Domicilio domicilio;
public:

    void setnombre(const char *);
    void setapellido(const char *);
    void setdni(int);
    void settelefono(int);
    void setemail(const char *);
    void setgenero(int);
    void setfecha_Nacimiento(Fechas);
    void setdomicilio(Domicilio);

    const char *getnombre();
    const char *getapellido();
    int getdni();
    int gettelefono();
    const char *getemail();
    int getgenero();
    Fechas getfecha_Nacimiento();
    Domicilio getdomicilio();
    const char* getgenerotexto() const;

    void cargar();
    void mostrar();
};

#endif // PERSONA_H_INCLUDED
