#ifndef DOMICILIO_H_INCLUDED
#define DOMICILIO_H_INCLUDED

class Domicilio{
private:
    char calle[30];
    int altura;
    char codigoPostal[10];
    char localidad[30];
    char partido[30];
    char provincia[30];
public:

    void setcalle(const char *);
    void setaltura(int);
    void setcodigoPostal(const char *);
    void setlocalidad(const char *);
    void setpartido(const char *);
    void setprovincia(const char *);

    const char *getcalle();
    int getaltura();
    const char *getcodigoPostal();
    const char *getlocalidad();
    const char *getpartido();
    const char *getprovincia();

    void Cargar();
    void CargarEn(int x=40, int y=20);
    void Mostrar(int X=40,int Y=20);
};


#endif // DOMICILIO_H_INCLUDED
