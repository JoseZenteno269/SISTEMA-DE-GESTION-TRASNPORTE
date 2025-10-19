#ifndef DESTINOS_H_INCLUDED
#define DESTINOS_H_INCLUDED

class Destinos{
private:
    int idDestino;
    char nombre_destino[40];
    char provincia[40];
    float distanciaKm;
    bool habilitado;
public:

    void setidDestino(int );
    void setnombre_destino(const char *);
    void setprovincia(const char *);
    void setdistanciaKm(float );
    void sethabilitado(bool );

    int getidDestino();
    const char *getnombre_destino();
    const char *getprovincia();
    float getdistanciaKm();
    bool gethabilitado();

    void cargar(int);
    void mostrar();

};


#endif // DESTINOS_H_INCLUDED
