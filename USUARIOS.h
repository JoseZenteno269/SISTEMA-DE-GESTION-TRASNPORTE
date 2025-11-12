#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED
#include "PERSONA.h"
#include "FECHAS.h"

class Usuarios:public Personas{
private:
    int idUsuario;
    char contrasena[30];
    Fechas ingreso;
    int nivel;
    bool estado;
public:

    void setidUsuario(int );
    void setcontrasena(const char *);
    void setingreso(Fechas );
    void setnivel(int);
    void setestado(bool );

    int getidUsuario();
    const char *getcontrasena();
    Fechas getingreso();
    int getnivel();
    bool getestado();

    void cargar(int);
    void mostrar();
};


#endif // USUARIOS_H_INCLUDED
