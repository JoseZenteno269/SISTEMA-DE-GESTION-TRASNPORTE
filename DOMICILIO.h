#ifndef DOMICILIO_H_INCLUDED
#define DOMICILIO_H_INCLUDED

class Domicilio{
private:
    char calle[30];
    int altura;
    char codigoPostal[6];
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
    void Mostrar();
};


#endif // DOMICILIO_H_INCLUDED
