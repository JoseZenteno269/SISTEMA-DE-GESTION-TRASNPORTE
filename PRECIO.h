#ifndef PRECIO_H_INCLUDED
#define PRECIO_H_INCLUDED

class PrecioxKilometro{
private:
    float Precio;

public:
    void setPrecio(float);

    int getPrecio();

    void cargar();
    void mostrar();
};


#endif // PRECIO_H_INCLUDED
