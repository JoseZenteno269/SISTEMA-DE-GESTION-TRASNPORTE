#ifndef PASAJEROS_H_INCLUDED
#define PASAJEROS_H_INCLUDED
#include "PERSONA.h"

class Pasajero:public Persona{
private:
    int numero_pasaje;
    bool habilitado;
public:
    void setnumero_pasaje(int);
    void sethabilitado(bool);

    int getnumero_pasaje();
    bool gethabilitado();

    void cargar(int);
    void mostrar();
};



#endif // PASAJEROS_H_INCLUDED
