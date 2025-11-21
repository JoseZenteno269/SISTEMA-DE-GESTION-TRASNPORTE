#ifndef FECHAS_H_INCLUDED
#define FECHAS_H_INCLUDED

class Fecha{
private:
    int dia;
    int mes;
    int anio;
public:
    Fecha(int d=1, int m=1, int a=1900);

    void setDia(int );
    void setMes(int );
    void setAnio(int );

    int getDia();
    int getMes();
    int getAnio();

    void cargar();
    void cargarEn(int, int);
    void mostrar();
    void mostrarEn(int,int);
};

#endif // FECHAS_H_INCLUDED
