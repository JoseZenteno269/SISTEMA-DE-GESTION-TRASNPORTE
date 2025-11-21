#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED
#include "PERSONA.h"
#include "FECHAS.h"

class Usuario:public Persona{
private:
    int idUsuario;
    char contrasena[30];
    Fecha ingreso;
    int nivel;
    bool estado;
public:

    void setIdUsuario(int );
    void setContrasena(const char *);
    void setIngreso(Fecha );
    void setNivel(int);
    void setEstado(bool );

    int getIdUsuario();
    const char *getContrasena();
    Fecha getIngreso();
    int getNivel();
    bool getEstado();

    void cargar(int);
    void mostrar();
};


#endif // USUARIOS_H_INCLUDED
