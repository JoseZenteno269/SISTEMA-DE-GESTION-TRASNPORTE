#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include "FECHAS.h"
#include "Domicilio.h"

class Personas{
private:
    char nombre[40];
    char apellido[40];
    int dni;
    int telefono;
    char email[30];
    ///std::string genero;
    Fechas fecha_Nacimiento;
    Domicilio domicilio;
public:

    void setnombre(const char *);
    void setapellido(const char *);
    void setdni(int);
    void settelefono(int);
    void setemail(const char *);
    ///void setgenero(std::string);
    void setfecha_Nacimiento(Fechas);
    void setdomicilio(Domicilio);

    const char *getnombre();
    const char *getapellido();
    int getdni();
    int gettelefono();
    const char *getemail();
    ///std::string getgenero();
    Fechas getfecha_Nacimiento();
    Domicilio getdomicilio();

    void cargar();
    void mostrar();
};

#endif // PERSONA_H_INCLUDED
