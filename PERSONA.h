#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include "FECHAS.h"
#include "Domicilio.h"

class Persona{
protected:
    char nombre[40];
    char apellido[40];
    long long dni;
    long long telefono;
    char email[100];
    int genero;
    char nacionalidad[40];
    Fecha fecha_Nacimiento;
    Domicilio domicilio;
public:

    void setnombre(const char *);
    void setapellido(const char *);
    void setdni(long long );
    void settelefono(long long );
    void setemail(const char *);
    void setgenero(int);
    void setnacionalidad(const char *);
    void setfecha_Nacimiento(Fecha);
    void setdomicilio(Domicilio);

    const char *getnombre();
    const char *getapellido();
    long long getdni();
    long long gettelefono();
    const char *getemail();
    int getgenero();
    const char *getnacionalidad();
    Fecha getfecha_Nacimiento();
    Domicilio getdomicilio();
    const char* getgenerotexto() const;

    void cargar();
    void modificar();
    void mostrar(int);
};

#endif // PERSONA_H_INCLUDED
