#ifndef FECHAS_H_INCLUDED
#define FECHAS_H_INCLUDED

class Fecha{
private:
    int dia;
    int mes;
    int anio;
public:
    Fecha(int d=1, int m=1, int a=1900);

    void setdia(int );
    void setmes(int );
    void setanio(int );

    int getdia();
    int getmes();
    int getanio();

    void cargar();
    void cargarEn(int, int);
    void mostrar();
    void mostrarEn(int,int);
};

#endif // FECHAS_H_INCLUDED
