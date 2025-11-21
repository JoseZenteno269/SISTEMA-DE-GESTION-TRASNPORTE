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

    void setNombre(const char *);
    void setApellido(const char *);
    void setDni(long long );
    void setTelefono(long long );
    void setEmail(const char *);
    void setGenero(int);
    void setNacionalidad(const char *);
    void setFecha_Nacimiento(Fecha);
    void setDomicilio(Domicilio);

    const char *getNombre();
    const char *getApellido();
    long long getDni();
    long long getTelefono();
    const char *getEmail();
    int getGenero();
    const char *getNacionalidad();
    Fecha getFecha_Nacimiento();
    Domicilio getDomicilio();
    const char* getGenerotexto() const;

    void cargar();
    void modificar();
    void mostrar(int);
};

#endif // PERSONA_H_INCLUDED
