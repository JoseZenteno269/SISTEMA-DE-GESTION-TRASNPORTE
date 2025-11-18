#ifndef PRECIO_H_INCLUDED
#define PRECIO_H_INCLUDED

class Precios{
private:
    float Precio;
    float Preciobutaca_cama;
    float Preciobutaca_semicama;
    float Preciobutaca_comun;

public:
    void setPrecio(float);
    void setPreciobutaca_cama(float);
    void setPreciobutaca_semicama(float);
    void setPreciobutaca_comun(float);

    float getPrecio();
    float getPreciobutaca_cama();
    float getPreciobutaca_semicama();
    float getPreciobutaca_comun();

    void cargar();
    void mostrar();
};

#endif // PRECIO_H_INCLUDED
