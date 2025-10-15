#ifndef ARCHIVO_HISTORIAL_INGRESOS_H_INCLUDED
#define ARCHIVO_HISTORIAL_INGRESOS_H_INCLUDED
#include "USUARIOS.h"
#include "FECHAS.h"

class Archivo_historial_usuarios{
private:
    char archivo_historial[30];
    int idusuario;
    char nombre_usuario[40];
    Fechas ingreso_sesion;
public:
    Archivo_historial_usuarios(const char *ah = "Historial_ingresos.dat");

    void setidusuario(int );
    void setingreso_sesion(Fechas );
    void setnombre_usuario(const char *);

    int getidusuario();
    Fechas getingreso_sesion();
    const char *getnombre_usuario();

    int contarRegistros();
    int buscarRegistro(int);
    Archivo_historial_usuarios leerRegistros(int);
    bool grabarRegistro();
    void mostrar();
    void listar();
};

#endif // ARCHIVO_HISTORIAL_INGRESOS_H_INCLUDED
