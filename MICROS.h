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

    void setIdMicro(int );
    void setMarca(const char *mrc);
    void setTipo(const char *t);
    void setCapacidad(int );
    void setTipoButaca(const char *tb);
    void setPatente(const char *p);
    void setDisponible(bool );

    int getIdMicro();
    const char *getMarca();
    const char *getTipo();
    int getCapacidad();
    const char *getTipoButaca();
    const char *getPatente();
    bool getDisponible();

    void capacidadportipo();

    void cargar(int);
    void mostrar(int X=40,int Y=3);

};


#endif // MICROS_H_INCLUDED
