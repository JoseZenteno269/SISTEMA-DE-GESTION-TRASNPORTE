#ifndef PASAJE_H_INCLUDED
#define PASAJE_H_INCLUDED
#include "FECHAS.h"
#include "HORA.h"
#include "VIAJES.h"

class Pasaje{
private:
    int pasaje;
    int idviaje;
    int butaca;
    float precio;
    char tipo_butaca[30];

public:

    void setPasaje(int);
    void setIdviaje(int);
    void setButaca(int);
    void setPrecio(float);
    void setTipo_butaca(const char*);

    int getPasaje();
    int getIdviaje();
    int getButaca();
    int getPrecio();
    const char *getTipo_butaca();

    void mostrar();
};


#endif // PASAJE_H_INCLUDED
