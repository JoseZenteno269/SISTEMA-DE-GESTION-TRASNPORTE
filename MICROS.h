#ifndef MICROS_H_INCLUDED
#define MICROS_H_INCLUDED

class Micro{
private:
    int idMicro;
    char marca[30];
    char tipo[30];
    int capacidad;
    char tipoButaca[30];
    char patente[10];
    bool disponible;
public:

    void setidMicro(int );
    void setmarca(const char *mrc);
    void settipo(const char *t);
    void setcapacidad(int );
    void settipoButaca(const char *tb);
    void setpatente(const char *p);
    void setdisponible(bool );

    int getidMicro();
    const char *getmarca();
    const char *gettipo();
    int getcapacidad();
    const char *gettipoButaca();
    const char *getpatente();
    bool getdisponible();
    void capacidadportipo();

    void cargar(int);
    void mostrar(int X=40,int Y=3);

};


#endif // MICROS_H_INCLUDED
